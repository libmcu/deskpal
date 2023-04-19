/*
 * SPDX-FileCopyrightText: 2023 Kyunghwan Kwon <k@mononn.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef GUI_H
#define GUI_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "deskpal.h"

#define GUI_UPDATE_INTERVAL_MS		100

void gui_port_init(void);
void gui_init(void);
void gui_step(const struct deskpal *deskpal);
void gui_flush(void *ctx);
void gui_sleep(void);

#if defined(__cplusplus)
}
#endif

#endif /* GUI_H */
