/*
 * SPDX-FileCopyrightText: 2023 Kyunghwan Kwon <k@libmcu.org>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef COLLECTOR_H
#define COLLECTOR_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "deskpal.h"

typedef enum {
	COLLECTOR_SUCCESS,
	COLLECTOR_BUSY,
	COLLECTOR_NOT_INITIALIZED,
	COLLECTOR_NO_NETWORK,
	COLLECTOR_FAULT,
	COLLECTOR_UNKNOWN_STATE,
	COLLECTOR_INVALID,
} collector_err_t;

#define COLLECTOR_SCAN_INTERVAL_MS	(30/*min*/ * 60/*sec*/ * 1000/*msec*/)
#define COLLECTOR_RETRY_INTERVAL_MS	100

void collector_init(void);
collector_err_t collector_aggregate(struct deskpal *deskpal);

#if defined(__cplusplus)
}
#endif

#endif /* COLLECTOR_H */
