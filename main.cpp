/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "stdio.h"


// Blinking rate in milliseconds
#define BLINKING_RATE     500ms


/*  Polling Button
int main()
{
    // Initialise the digital pin LED1 as an output
#ifdef LED1
    DigitalOut led(LED1);
#else
    bool led;
#endif

#ifdef BUTTON1
    DigitalIn button(BUTTON1);
#else
    bool button;
#endif
    
    while (true) {
        if(button){
            led = true;
        }
        else{
            led = false;
        }
    }
}
*/

// IRQ
/*
InterruptIn button(BUTTON1);
DigitalOut led1(LED1);
DigitalOut led2(LED2);
//enable_irq();
void trigger() {
    led1 = !led1;
}


int main() {
    // register trigger() to be called upon the rising edge of event
    button.rise(&trigger);
    while(1) {
        led2 = !led2;
        ThisThread::sleep_for(250);
    }
}
*/


//Timer

/*
InterruptIn button(BUTTON1);
DigitalOut led1(LED1);
DigitalOut led2(LED2);
Timer timer;
int begin1, end1;
//enable_irq();
void rising_edge() {
    led1 = !led1;
    begin1 = timer.read_us();
}

void falling_edge() {
    end1 = timer.read_us();
}


int main() {
    timer.start();
    // register trigger() to be called upon the rising edge of event
    button.rise(&rising_edge);
    button.fall(&falling_edge);
    while(1) {
        printf("Toggled the button for %d us \n", end1 - begin1);
        led2 = !led2;
        ThisThread::sleep_for(250);
    }
}
*/

// Ticker
/*
DigitalOut led1(LED1);
Ticker ticker;

void attime() {
    led1 = !led1;
}


int main() {
    ticker.attach(&attime, 1s);
    while(1) {
        ThisThread::sleep_for(250);
    }
}
*/

// FREQUENCE CONTROL
/*
DigitalOut led1(LED1);
DigitalOut led2(LED2);
InterruptIn  button(BUTTON1);
std::chrono::milliseconds FREQ1 = 1000ms;
std::chrono::milliseconds FREQ2 = 200ms;
std::chrono::milliseconds freq = FREQ1;
Ticker ticker;

void attime() {
    led1 = !led1;
}

void trigger(){
    if (freq == FREQ1) {
        freq = FREQ2;
        led2 != led2;
    }
    else {
        freq = FREQ1;
    }
    led2 != led2;
}

int main() {
    button.rise(&trigger);
    ticker.attach(&attime, freq);
    while(1) {
        ThisThread::sleep_for(250);
    }
}
*/


// I2C Temperature
// Read temperature from AS6261

/*
I2C i2c(P1_I2C_SDA, P1_I2C_SCL);

const int addr7bit = 0x48;      // 7 bit I2C address
const int addr8bit = 0x48 << 1; // 8bit I2C address, 0x90

int main()
{
    char cmd[2];
    while (1) {
        cmd[0] = 0x01;
        cmd[1] = 0x00;
        i2c.write(addr8bit, cmd, 2);

        ThisThread::sleep_for(500);

        cmd[0] = 0x00;
        i2c.write(addr8bit, cmd, 1);
        i2c.read(addr8bit, cmd, 2);

        float tmp = (float((cmd[0] << 8) | cmd[1]) / 256.0);
        printf("Temp = %2.f \n", tmp);
    }
}
*/