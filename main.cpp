/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "stdio.h"


// Blinking rate in milliseconds
#define BLINKING_RATE     500ms


int main()
{
    printf("Je suis PAS un BG");
    // Initialise the digital pin LED1 as an output
#ifdef LED1
    DigitalOut led(LED1);
#else
    bool led;
#endif
    ThisThread::sleep_for(1000);
    while (true) {
        led = !led;
        ThisThread::sleep_for(BLINKING_RATE);
        printf("Je suis un BG \n"); 
    }
}
