# SPDX-License-Identifier: Apache-2.0

add_subdirectory(external/libmcu)
add_subdirectory(external/pble)
add_subdirectory(external/pwifi)
add_subdirectory(external/pl4)
add_subdirectory(external/pmqtt)
add_subdirectory(external/bq25180)

target_compile_definitions(libmcu PUBLIC
	METRICS_USER_DEFINES=\"${PROJECT_SOURCE_DIR}/include/metrics.def\"
	_POSIX_THREADS
	_POSIX_C_SOURCE=200809L
)

list(APPEND APP_INCS ${CMAKE_SOURCE_DIR}/external/jsmn)
