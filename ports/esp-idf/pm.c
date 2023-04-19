/*
 * SPDX-FileCopyrightText: 2023 Kyunghwan Kwon <k@libmcu.org>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "libmcu/port/pm.h"
#include "esp_system.h"
#include "esp_sleep.h"

int pm_port_enter(pm_mode_t mode)
{
	esp_sleep_enable_ext0_wakeup(0, 0);
	esp_sleep_enable_timer_wakeup(COLLECTOR_SCAN_INTERVAL_MS * 1000);

	switch (mode) {
	case PM_SLEEP_DEEP:
		esp_deep_sleep_start();
		break;
	case PM_SLEEP:
		esp_light_sleep_start();
		break;
	default:
		esp_restart();
		break;
	}

	return 0;
}
