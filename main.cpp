/*
 * Copyright (c) 2014-2020 Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

// Adjust pin name to your board specification.
// You can use LED1/LED2/LED3/LED4 if any is connected to PWM capable pin,
// or use any PWM capable pin, and see generated signal on logical analyzer.
PwmOut signal(LED1);

int main() {
    int duty = 0;   // unit:%
    signal.period_ms(1);     // pwm frequency set 1kHz.
    
    while(1) {
        // until 100%, increase by 5% in 50ms intervals
        for (; duty <= 100; duty += 5) {
            signal = duty / 100.0;
            thread_sleep_for(50);
        }
        // until 0%, decrease by 5% in 50ms intervals
        for (; duty >= 0; duty -= 5) {
            signal = duty / 100.0;
            thread_sleep_for(50);
        }
    }
}
