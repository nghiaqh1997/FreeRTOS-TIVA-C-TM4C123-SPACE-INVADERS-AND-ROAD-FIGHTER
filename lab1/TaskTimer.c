/*
 * TaskTimer.c
 *
 *  Created on: May 22, 2022
 *      Author: nghia
 */
#include "include.h"
#include "Images.h"
#include "Task_def.h"
#include "Nokia5110/SPI.h"
#include "sprite.h"
uint8_t Special = 0;
void prvOneShotTimerCallback(TimerHandle_t xTimer){
    TickType_t xTimeNow;
    xTimeNow = xTaskGetTickCount();
    UARTprintf("%d",xTimeNow);
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_7, GPIO_PIN_7);
    Special = 1;
}


