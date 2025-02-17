# SPDX-License-Identifier: Apache-2.0

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_LIST_DIR} PORT_SRCS)

set(SDK_ROOT ${CMAKE_SOURCE_DIR}/external/nRF5_SDK_17.1.0_ddde560)

if (NOT EXISTS ${SDK_ROOT})
	message(INFO "Downloading nRF5 SDK")
	set(FETCHCONTENT_QUIET FALSE)
	include(FetchContent)
	FetchContent_Declare(nrf52_sdk
		URL "https://nsscprodmedia.blob.core.windows.net/prod/software-and-other-downloads/sdks/nrf5/binaries/nrf5_sdk_17.1.0_ddde560.zip"
		SOURCE_DIR "${SDK_ROOT}"
	)
	FetchContent_MakeAvailable(nrf52_sdk)
endif()

if (BOARD STREQUAL madi_nrf52)
	set(LD_SCRIPT ${CMAKE_CURRENT_LIST_DIR}/nrf52840.ld)
	set(NRF_SRCS
		${SDK_ROOT}/modules/nrfx/mdk/gcc_startup_nrf52840.S
		${SDK_ROOT}/modules/nrfx/mdk/system_nrf52840.c
	)
	set(NRF_INCS
		${SDK_ROOT}/components/softdevice/s140/headers/nrf52
		${SDK_ROOT}/components/softdevice/s140/headers
	)
	set(NRF_DEFS
		S140
		NRF52840_XXAA
		CUSTOM_BOARD_INC=libmcu
	)
else()
	set(LD_SCRIPT ${CMAKE_CURRENT_LIST_DIR}/nrf52832.ld)
	set(NRF_SRCS
		${SDK_ROOT}/modules/nrfx/mdk/gcc_startup_nrf52.S
		${SDK_ROOT}/modules/nrfx/mdk/system_nrf52.c
	)
	set(NRF_INCS
		${SDK_ROOT}/components/softdevice/s132/headers/nrf52
		${SDK_ROOT}/components/softdevice/s132/headers
	)
	set(NRF_DEFS
		S132
		NRF52832_XXAA
		CUSTOM_BOARD_INC=redbear
	)
endif()

set(TINYUSB_ROOT ${CMAKE_SOURCE_DIR}/external/tinyusb)

if (NOT EXISTS ${TINYUSB_ROOT})
	message(INFO "Downloading tinyusb")
	set(FETCHCONTENT_QUIET FALSE)
	include(FetchContent)
	FetchContent_Declare(tinyusb
		URL "https://github.com/hathach/tinyusb/archive/refs/tags/0.15.0.zip"
		SOURCE_DIR "${TINYUSB_ROOT}"
	)
	FetchContent_MakeAvailable(tinyusb)
endif()

list(APPEND NRF_SRCS
	${TINYUSB_ROOT}/src/tusb.c
	${TINYUSB_ROOT}/src/common/tusb_fifo.c
	${TINYUSB_ROOT}/src/device/usbd.c
	${TINYUSB_ROOT}/src/device/usbd_control.c
	${TINYUSB_ROOT}/src/class/cdc/cdc_device.c
	${CMAKE_CURRENT_LIST_DIR}/tinyusb/dcd_nrf5x.c
	${CMAKE_CURRENT_LIST_DIR}/tinyusb/usb_descriptors.c
	${CMAKE_CURRENT_LIST_DIR}/tinyusb/usbd_cdc.c
)
list(APPEND NRF_INCS
	${TINYUSB_ROOT}/src
	${CMAKE_CURRENT_LIST_DIR}/tinyusb
)
list(APPEND NRF_DEFS
	CFG_TUSB_MCU=OPT_MCU_NRF5X
)

list(APPEND NRF_SRCS
	${SDK_ROOT}/components/ble/ble_advertising/ble_advertising.c
	${SDK_ROOT}/components/ble/common/ble_advdata.c
	${SDK_ROOT}/components/ble/common/ble_conn_params.c
	${SDK_ROOT}/components/ble/common/ble_conn_state.c
	${SDK_ROOT}/components/ble/common/ble_srv_common.c
	${SDK_ROOT}/components/ble/ble_link_ctx_manager/ble_link_ctx_manager.c
	${SDK_ROOT}/components/ble/nrf_ble_gatt/nrf_ble_gatt.c
	${SDK_ROOT}/components/ble/nrf_ble_qwr/nrf_ble_qwr.c
	${SDK_ROOT}/components/ble/nrf_ble_scan/nrf_ble_scan.c
	${SDK_ROOT}/components/ble/ble_db_discovery/ble_db_discovery.c
	${SDK_ROOT}/components/ble/peer_manager/peer_manager.c
	${SDK_ROOT}/components/ble/peer_manager/peer_manager_handler.c
	${SDK_ROOT}/components/ble/peer_manager/security_manager.c
	${SDK_ROOT}/components/ble/peer_manager/gatt_cache_manager.c
	${SDK_ROOT}/components/ble/peer_manager/gatts_cache_manager.c
	${SDK_ROOT}/components/ble/peer_manager/id_manager.c
	${SDK_ROOT}/components/ble/peer_manager/nrf_ble_lesc.c
	${SDK_ROOT}/components/ble/peer_manager/peer_data_storage.c
	${SDK_ROOT}/components/ble/peer_manager/peer_database.c
	${SDK_ROOT}/components/ble/peer_manager/peer_id.c
	${SDK_ROOT}/components/ble/peer_manager/auth_status_tracker.c
	${SDK_ROOT}/components/ble/peer_manager/pm_buffer.c
	${SDK_ROOT}/components/ble/peer_manager/security_dispatcher.c
	${SDK_ROOT}/components/softdevice/common/nrf_sdh.c
	${SDK_ROOT}/components/softdevice/common/nrf_sdh_ble.c
	${SDK_ROOT}/components/softdevice/common/nrf_sdh_soc.c
	${SDK_ROOT}/components/softdevice/common/nrf_sdh_freertos.c
	${SDK_ROOT}/components/boards/boards.c
	${SDK_ROOT}/components/libraries/log/src/nrf_log_frontend.c
	${SDK_ROOT}/components/libraries/log/src/nrf_log_str_formatter.c
	${SDK_ROOT}/components/libraries/util/app_error.c
	${SDK_ROOT}/components/libraries/util/app_error_handler_gcc.c
	${SDK_ROOT}/components/libraries/util/app_error_weak.c
	${SDK_ROOT}/components/libraries/util/app_util_platform.c
	${SDK_ROOT}/components/libraries/util/nrf_assert.c
	${SDK_ROOT}/components/libraries/atomic/nrf_atomic.c
	${SDK_ROOT}/components/libraries/atomic_fifo/nrf_atfifo.c
	${SDK_ROOT}/components/libraries/atomic_flags/nrf_atflags.c
	${SDK_ROOT}/components/libraries/balloc/nrf_balloc.c
	${SDK_ROOT}/components/libraries/memobj/nrf_memobj.c
	${SDK_ROOT}/components/libraries/ringbuf/nrf_ringbuf.c
	${SDK_ROOT}/components/libraries/strerror/nrf_strerror.c
	${SDK_ROOT}/components/libraries/uart/app_uart_fifo.c
	${SDK_ROOT}/components/libraries/fifo/app_fifo.c
	${SDK_ROOT}/components/libraries/sortlist/nrf_sortlist.c
	${SDK_ROOT}/components/libraries/timer/drv_rtc.c
	${SDK_ROOT}/components/libraries/scheduler/app_scheduler.c
	${SDK_ROOT}/components/libraries/timer/app_timer_freertos.c
	${SDK_ROOT}/components/libraries/experimental_section_vars/nrf_section_iter.c
	${SDK_ROOT}/components/libraries/pwr_mgmt/nrf_pwr_mgmt.c
	${SDK_ROOT}/components/libraries/fds/fds.c
	${SDK_ROOT}/components/libraries/fstorage/nrf_fstorage.c
	${SDK_ROOT}/components/libraries/fstorage/nrf_fstorage_nvmc.c
	${SDK_ROOT}/components/libraries/fstorage/nrf_fstorage_sd.c
	${SDK_ROOT}/external/fprintf/nrf_fprintf.c
	${SDK_ROOT}/external/fprintf/nrf_fprintf_format.c
	${SDK_ROOT}/external/freertos/source/croutine.c
	${SDK_ROOT}/external/freertos/source/event_groups.c
	${SDK_ROOT}/external/freertos/source/portable/MemMang/heap_4.c
	${SDK_ROOT}/external/freertos/source/list.c
	${SDK_ROOT}/external/freertos/portable/GCC/nrf52/port.c
	${SDK_ROOT}/external/freertos/portable/CMSIS/nrf52/port_cmsis.c
	${SDK_ROOT}/external/freertos/portable/CMSIS/nrf52/port_cmsis_systick.c
	${SDK_ROOT}/external/freertos/source/queue.c
	${SDK_ROOT}/external/freertos/source/stream_buffer.c
	${SDK_ROOT}/external/freertos/source/tasks.c
	${SDK_ROOT}/external/freertos/source/timers.c
	${SDK_ROOT}/modules/nrfx/soc/nrfx_atomic.c
	${SDK_ROOT}/modules/nrfx/drivers/src/nrfx_uart.c
	${SDK_ROOT}/modules/nrfx/drivers/src/nrfx_uarte.c
	${SDK_ROOT}/modules/nrfx/drivers/src/prs/nrfx_prs.c
	${SDK_ROOT}/modules/nrfx/drivers/src/nrfx_clock.c
	${SDK_ROOT}/modules/nrfx/drivers/src/nrfx_gpiote.c
	${SDK_ROOT}/modules/nrfx/drivers/src/nrfx_rtc.c
	${SDK_ROOT}/modules/nrfx/drivers/src/nrfx_twi.c
	${SDK_ROOT}/modules/nrfx/drivers/src/nrfx_twim.c
	${SDK_ROOT}/modules/nrfx/drivers/src/nrfx_twis.c
	${SDK_ROOT}/modules/nrfx/drivers/src/nrfx_ppi.c
	${SDK_ROOT}/modules/nrfx/drivers/src/nrfx_saadc.c
	${SDK_ROOT}/modules/nrfx/drivers/src/nrfx_qspi.c
	${SDK_ROOT}/integration/nrfx/legacy/nrf_drv_twi.c
	${SDK_ROOT}/integration/nrfx/legacy/nrf_drv_uart.c
	${SDK_ROOT}/integration/nrfx/legacy/nrf_drv_clock.c
	${SDK_ROOT}/integration/nrfx/legacy/nrf_drv_ppi.c

	${SDK_ROOT}/components/ble/ble_services/ble_nus/ble_nus.c

	${PORT_SRCS}

	${CMAKE_SOURCE_DIR}/external/libmcu/ports/freertos/board.c
	${CMAKE_SOURCE_DIR}/external/libmcu/ports/freertos/pthread.c
	${CMAKE_SOURCE_DIR}/external/libmcu/ports/freertos/pthread_mutex.c
	${CMAKE_SOURCE_DIR}/external/libmcu/ports/freertos/ao.c
	${CMAKE_SOURCE_DIR}/external/libmcu/ports/freertos/semaphore.c
	${CMAKE_SOURCE_DIR}/external/libmcu/ports/freertos/timext.c
	${CMAKE_SOURCE_DIR}/external/libmcu/ports/nrf52/freertos.c
	${CMAKE_SOURCE_DIR}/external/libmcu/ports/stubs/syscall.c
)
list(APPEND NRF_INCS
	${SDK_ROOT}/components/ble/common
	${SDK_ROOT}/components/ble/ble_advertising
	${SDK_ROOT}/components/ble/ble_link_ctx_manager
	${SDK_ROOT}/components/ble/nrf_ble_gatt
	${SDK_ROOT}/components/ble/nrf_ble_qwr
	${SDK_ROOT}/components/ble/nrf_ble_scan
	${SDK_ROOT}/components/ble/ble_db_discovery
	${SDK_ROOT}/components/ble/peer_manager
	${SDK_ROOT}/components/softdevice/common
	${SDK_ROOT}/components
	${SDK_ROOT}/components/libraries/strerror
	${SDK_ROOT}/components/toolchain/cmsis/include
	${SDK_ROOT}/components/libraries/sortlist
	${SDK_ROOT}/components/libraries/util
	${SDK_ROOT}/components/libraries/balloc
	${SDK_ROOT}/components/libraries/ringbuf
	${SDK_ROOT}/components/libraries/bsp
	${SDK_ROOT}/components/libraries/log
	${SDK_ROOT}/components/libraries/experimental_section_vars
	${SDK_ROOT}/components/libraries/delay
	${SDK_ROOT}/components/libraries/uart
	${SDK_ROOT}/components/libraries/fifo
	${SDK_ROOT}/components/libraries/atomic_fifo
	${SDK_ROOT}/components/libraries/atomic_flags
	${SDK_ROOT}/components/libraries/timer
	${SDK_ROOT}/components/libraries/scheduler
	${SDK_ROOT}/components/libraries/experimental_section_vars
	${SDK_ROOT}/components/libraries/atomic
	${SDK_ROOT}/components/libraries/memobj
	${SDK_ROOT}/components/libraries/log/src
	${SDK_ROOT}/components/libraries/mutex
	${SDK_ROOT}/components/libraries/pwr_mgmt
	${SDK_ROOT}/components/libraries/fds
	${SDK_ROOT}/components/libraries/fstorage
	${SDK_ROOT}/components/boards
	${SDK_ROOT}/components/drivers_nrf/nrf_soc_nosd
	${SDK_ROOT}/external/fprintf
	${SDK_ROOT}/external/freertos/portable/GCC/nrf52
	${SDK_ROOT}/external/freertos/portable/CMSIS/nrf52
	${SDK_ROOT}/external/freertos/source/include
	${SDK_ROOT}/integration/nrfx
	${SDK_ROOT}/integration/nrfx/legacy
	${SDK_ROOT}/modules/nrfx/mdk
	${SDK_ROOT}/modules/nrfx/hal
	${SDK_ROOT}/modules/nrfx
	${SDK_ROOT}/modules/nrfx/drivers/include
	${SDK_ROOT}/modules/nrfx/drivers/src/prs
	${SDK_ROOT}/modules/nrfx/drivers/src

	${SDK_ROOT}/components/ble/ble_services/ble_nus
	${SDK_ROOT}/components/ble/ble_services/ble_nus_c

	${CMAKE_CURRENT_LIST_DIR}
	${CMAKE_CURRENT_LIST_DIR}/..
)
list(APPEND NRF_DEFS
	SOFTDEVICE_PRESENT
	NRF_SD_BLE_API_VERSION=7
	NRFX_SAADC_API_V2

	BSP_DEFINES_ONLY
	CONFIG_GPIO_AS_PINRESET
	FLOAT_ABI_HARD
	FREERTOS
	__HEAP_SIZE=8192
	__STACK_SIZE=8192
	_POSIX_C_SOURCE=200809L
)

target_include_directories(libmcu PUBLIC
	${CMAKE_SOURCE_DIR}/external/libmcu/modules/common/include/libmcu/posix)

add_library(nrf52 OBJECT ${NRF_SRCS})
target_include_directories(nrf52 PUBLIC ${NRF_INCS} ${APP_INCS})
target_compile_definitions(nrf52 PUBLIC ${NRF_DEFS})
target_link_libraries(nrf52 PUBLIC libmcu bq25180)

target_link_libraries(pble PRIVATE nrf52)

target_link_libraries(${PROJECT_NAME} PRIVATE nrf52)
target_link_options(${PROJECT_NAME} PRIVATE -T${LD_SCRIPT})
target_link_directories(${PROJECT_NAME} PRIVATE ${SDK_ROOT}/modules/nrfx/mdk)
