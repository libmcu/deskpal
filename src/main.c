/*
 * SPDX-FileCopyrightText: 2022 Kyunghwan Kwon <k@libmcu.org>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <unistd.h>

#include "libmcu/board.h"
#include "libmcu/logging.h"
#include "libmcu/metrics.h"
#include "libmcu/cli.h"
#include "libmcu/syscall.h"
#include "libmcu/ao.h"
#include "libmcu/ao_timer.h"
#include "libmcu/pm.h"

#include "ledind.h"
#include "userbutton.h"
#include "battery.h"
#include "selftest.h"
#include "gui.h"
#include "collector.h"

#define AO_STACK_SIZE_BYTES		8192U
#define AO_PRIORITY			1U

#define CLI_MAX_HISTORY			10U

#define LED_BLINK_ON_TIME_MS		50U
#define LED_BLINK_INTERVAL_MS		1500U
#define LED_BLINK_ERROR_INTERVAL_MS	150U

typedef void (*event_handler_t)(void *ctx);

struct ao_event {
	event_handler_t handler;
	void *ctx;
};

static struct ao ao_handle;

static void process_led(void *ctx);
static void process_button(void *ctx);
static void process_battery(void *ctx);
static void process_gui(void *ctx);
static void process_collector(void *ctx);

static struct deskpal deskpal;

static struct ao_event led_event = {
	.handler = process_led,
};

static struct ao_event button_event = {
	.handler = process_button,
};

static struct ao_event battery_event = {
	.handler = process_battery,
};

static struct ao_event gui_event = {
	.handler = process_gui,
};

static struct ao_event collector_event = {
	.handler = process_collector,
};

static void on_userbutton_state_change(void)
{
	ao_post(&ao_handle, &button_event);
}

static void on_battery_status_change(void)
{
	ao_post(&ao_handle, &battery_event);
}

static void process_button(void *ctx)
{
	unused(ctx);
	if (userbutton_process()) {
		ao_post(&ao_handle, &button_event);
	}
}

static void process_battery(void *ctx)
{
	unused(ctx);
	enum battery_status status = battery_status();

	if (status == BATTERY_UNKNOWN) {
		ao_post_defer(&ao_handle, &battery_event, 100);
	}

	deskpal.battery_pct = battery_level_pct();
}

static void process_led(void *ctx)
{
	unused(ctx);
	uint32_t msec = ledind_step();
	ao_post_defer(&ao_handle, &led_event, msec);
}

static void dispatch(struct ao * const ao, const struct ao_event * const event)
{
	(void)ao;

	if (event && event->handler) {
		(*event->handler)(event->ctx);
	}
}

static void process_gui(void *ctx)
{
	unused(ctx);
	gui_step(0);
	ao_post_defer(&ao_handle, &gui_event, GUI_UPDATE_INTERVAL_MS);
}

static void process_collector(void *ctx)
{
	uint32_t interval_ms = COLLECTOR_RETRY_INTERVAL_MS;

	if (collector_aggregate(&deskpal) == COLLECTOR_SUCCESS) {
		gui_step(&deskpal);
		interval_ms = COLLECTOR_SCAN_INTERVAL_MS;
		pm_enter(PM_SLEEP_DEEP);
	}

	ao_post_defer(&ao_handle, &collector_event, interval_ms);
}

static size_t logging_stdout_writer(const void *data, size_t size)
{
	unused(size);
	static char buf[LOGGING_MESSAGE_MAXLEN];
	size_t len = logging_stringify(buf, sizeof(buf), data);

	buf[len++] = '\n';
	buf[len] = '\0';

	write(1, buf, len);

	return len;
}

static void logging_stdout_backend_init(void)
{
	syscall_register_writer(cli_io_create()->write);

	static struct logging_backend log_console = {
		.write = logging_stdout_writer,
	};

	logging_add_backend(&log_console);
}

static void shell_start(void)
{
	static char cli_buffer[CLI_CMD_MAXLEN * CLI_MAX_HISTORY];
	struct cli cli;

	DEFINE_CLI_CMD_LIST(cli_commands,
			help, exit, info, reboot, md, metric, wifi, ble);

	cli_init(&cli, cli_io_create(), cli_buffer, sizeof(cli_buffer));
	cli_register_cmdlist(&cli, cli_commands);
	cli_run(&cli);
}

static void run_selftest(void)
{
	uint32_t led_blink_interval = LED_BLINK_INTERVAL_MS;

	if (selftest() != SELFTEST_SUCCESS) {
		led_blink_interval = LED_BLINK_ERROR_INTERVAL_MS;
	}

	ledind_set(LEDIND_BLINK, LED_BLINK_ON_TIME_MS,
			led_blink_interval - LED_BLINK_ON_TIME_MS);
}

static void on_userbutton_event(button_event_t event,
		const struct button *info, void *ctx)
{
	unused(ctx);
	switch (event) {
	case BUTTON_EVT_CLICK:
		ao_post(&ao_handle, &collector_event);
		break;
	default:
		break;
	}
}

static void on_deep_sleep(void *ctx)
{
	gui_sleep();
	battery_enable_monitor(false);
	ledind_off();
	ledind_disable();
}

int main(void)
{
	board_init(); /* should be called very first. */

	metrics_init(0);
	logging_init(board_get_time_since_boot_ms);
	logging_stdout_backend_init();

	ao_timer_init();
	ao_create(&ao_handle, AO_STACK_SIZE_BYTES, AO_PRIORITY);
	ao_start(&ao_handle, dispatch);

	battery_init(battery_monitor_init(on_battery_status_change));
	userbutton_init(userbutton_gpio_init(on_userbutton_state_change));
	ledind_init(ledind_gpio_create());
	gui_init();

	info("[%s] %s %s", board_get_reboot_reason_string(),
			board_get_serial_number_string(),
			board_get_version_string());

	pm_register_entry_callback(PM_SLEEP_DEEP, 0, on_deep_sleep, 0);
	userbutton_set_handler(on_userbutton_event, 0);
	ledind_enable();
	ao_post(&ao_handle, &led_event);
	ao_post(&ao_handle, &gui_event);
	ao_post(&ao_handle, &collector_event);
	run_selftest();

	shell_start();

	return 0;
}
