# SPDX-License-Identifier: Apache-2.0

include(${BASEDIR}/projects/arch/cm4f.cmake)

set(PLATFORM_SPECIFIC_DIR ${CMAKE_SOURCE_DIR}/ports/stm32/g4)

add_custom_target(${PROJECT_NAME}.bin ALL DEPENDS ${PROJECT_NAME})
add_custom_target(${PROJECT_NAME}.hex ALL DEPENDS ${PROJECT_NAME})
add_custom_target(flash DEPENDS ${PROJECT_NAME}.hex)
add_custom_target(gdb DEPENDS ${PROJECT_NAME})

add_custom_command(TARGET ${PROJECT_NAME}.hex
	COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${PROJECT_NAME}>
			${PROJECT_NAME}.hex
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

add_custom_command(TARGET ${PROJECT_NAME}.bin
	COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${PROJECT_NAME}>
			${PROJECT_NAME}.bin
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

add_custom_command(TARGET flash
	USES_TERMINAL COMMAND
		pyocd flash -t stm32g473ce ${PROJECT_NAME}.hex
)

add_custom_command(TARGET gdb
	USES_TERMINAL COMMAND
		pyocd gdbserver -t stm32g473ce
)