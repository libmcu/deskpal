/*
 * SPDX-FileCopyrightText: 2023 Kyunghwan Kwon <k@libmcu.org>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef DESKPAL_H
#define DESKPAL_H

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdint.h>

struct air_quality {
	uint16_t aqi; /**< Air Quality Index */
	char updated_time[25+1];
};

struct deskpal {
	struct air_quality air_quality;
	uint32_t won_dollar_exchange_rate;
	uint8_t battery_pct;
};

#if defined(__cplusplus)
}
#endif

#endif /* DESKPAL_H */
