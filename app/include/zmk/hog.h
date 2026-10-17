/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <zmk/keys.h>
#include <zmk/hid.h>

int zmk_hog_send_keyboard_report(struct zmk_hid_keyboard_report_body *report);
int zmk_hog_send_keyboard_report_to_profile(const struct zmk_hid_keyboard_report_body *report, uint8_t profile_index);

/* Optional transient gestures: pin the recipient, do not mutate global HID state. */
struct bt_conn;
struct k_work_q;
int zmk_hog_send_keyboard_snapshot(struct bt_conn *conn,
                                   const struct zmk_hid_keyboard_report_body *report);
struct k_work_q *zmk_hog_work_queue(void);
int zmk_hog_send_consumer_report(struct zmk_hid_consumer_report_body *body);
int zmk_hog_send_consumer_report_to_profile(const struct zmk_hid_consumer_report_body *report, uint8_t profile_index);

#if IS_ENABLED(CONFIG_ZMK_POINTING)
int zmk_hog_send_mouse_report(struct zmk_hid_mouse_report_body *body);
int zmk_hog_send_mouse_report_to_profile(const struct zmk_hid_mouse_report_body *report, uint8_t profile_index);
#endif // IS_ENABLED(CONFIG_ZMK_POINTING)
