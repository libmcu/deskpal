# SPDX-License-Identifier: Apache-2.0

TARGET_PLATFORM := nrf52
PORT_ROOT := ports/nrf5-sdk
PLATFORM_SPECIFIC_MAKE := $(PORT_ROOT)/sdk.mk
INCS += $(PORT_ROOT)

include projects/arch/cm4f.mk

.PHONY: flash flash_softdevice erase gdbserver
flash: $(OUTHEX)
	pyocd flash -t nrf52832 $<
flash_softdevice: $(SDK_ROOT)/components/softdevice/s132/hex/s132_nrf52_7.2.0_softdevice .hex
	pyocd flash -t nrf52832 $<
erase:
	pyocd erase -t nrf52832 --chip
gdbserver:
	$(Q)pyocd $@ -t nrf52832
