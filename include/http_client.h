/*
 * SPDX-FileCopyrightText: 2023 Kyunghwan Kwon <k@libmcu.org>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

struct http_client_conn_param {
	const char *addr;
	uint16_t port;

	const uint8_t *ca_cert;
	size_t ca_cert_len;
	const uint8_t *client_cert;
	size_t client_cert_len;
	const uint8_t *client_key;
	size_t client_key_len;

	uint32_t timeout_ms;
};

struct http_client_response {
	uint16_t status_code;
};

struct http_client_buffer {
	uint8_t *space;
	size_t cap;
	size_t len;
};

typedef void (*http_client_request_callback_t)
		(const struct http_client_response *response, void *ctx);

struct http_client;

struct http_client *http_client_create(const struct http_client_conn_param *param,
		struct http_client_buffer *buf);
int http_client_request(struct http_client *handle,
		http_client_request_callback_t callback, void *ctx);
int http_client_destroy(struct http_client *handle);

#if defined(__cplusplus)
}
#endif

#endif /* HTTP_CLIENT_H */
