# SPDX-License-Identifier: MIT

COMPONENT_NAME = collector

SRC_FILES = \
	../src/collector.c \
	../external/libmcu/tests/stubs/logging.c

TEST_SRC_FILES = \
	src/collector_test.cpp \
	src/test_all.cpp \

INCLUDE_DIRS = \
	$(CPPUTEST_HOME)/include \
	../include \
	../external/libmcu/tests/stubs/overrides \
	../external/pwifi/include \
	../external/libmcu/modules/logging/include \
	../external/libmcu/modules/common/include \
	../external/jsmn \

MOCKS_SRC_DIRS =
CPPUTEST_CPPFLAGS = -DTARGET_PLATFORM=fake

include runners/MakefileRunner
