/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


#include "pico/stdlib.h"
#include "add.h"
#include "stdio.h"
#include "SEGGER_RTT.h"
 

int main() {

SEGGER_RTT_Init(); 



uint16_t t;
t = add2nums(1000,100);
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_ms(t);
        gpio_put(LED_PIN, 0);
        sleep_ms(1000);
       
          SEGGER_RTT_printf(0, "test TerminalOut\n");
    }

}
