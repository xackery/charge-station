/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"

const uint LED_PIN = 16;
const uint BUTTON_PIN = 14;
const uint SWITCH_PIN = 11;

int main() {
    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);

    gpio_init(SWITCH_PIN);
    gpio_set_dir(SWITCH_PIN, GPIO_OUT);

    int counter = 0;

    while (true) {
        counter = 0;

        printf("on\n");
        gpio_put(LED_PIN, 0);
        gpio_put(SWITCH_PIN, 1);
        
        while (counter < 10) { // Leave on for 2 hours 7200
            printf("counter: %d\n", counter);
            counter++;
            sleep_ms(1000);
            if (gpio_get(BUTTON_PIN)) {
                printf("button pressed\n");
                break;
            }
        }
        counter = 0;

        printf("off\n");
        gpio_put(LED_PIN, 1);
        gpio_put(SWITCH_PIN, 0);

        while (counter < 30) { // Leave off for 1 week 604800
            printf("counter: %d\n", counter);
            counter++;
            sleep_ms(1000);
            if (gpio_get(BUTTON_PIN)) {
                printf("button pressed\n");
                break;
            }
        }
    }
}