#include "include.h"
#include "Config_Register/Config_Register.h"
#include "FSM/FSM.h"
#include "Nokia5110/SPI.h"
#include "Task_def.h"

/*-----------------------------------------------------------*/
#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}

#endif
/*-----------------------------------------------------------*/
void vApplicationMallocFailedHook( void )
{
    /* This function will only be called if an API call to create a task, queue
    or semaphore fails because there is too little heap RAM remaining. */
    for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( xTaskHandle *pxTask, signed char *pcTaskName )
{
    /* This function will only be called if a task overflows its stack.  Note
    that stack overflow checking does slow down the context switch
    implementation. */
    for( ;; );
}
/*-----------------------------------------------------------*/
volatile unsigned int Idle = 0;
void vApplicationIdleHook( void )
{
    /* This example does not use the idle hook to perform any processing. */
    Idle++;
}
/*-----------------------------------------------------------*/

void vApplicationTickHook( void )
{
    /* This example does not use the tick hook to perform any processing. */
}
/*-----------------------------------------------------------*/
int main(){
    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
    PortF_Init();
    Interrupt_GPIOF_Init();
    PortA_Init();
    Interrupt_GPIOA_Init();
    Uart_Init();
    ADC_Timer_Init();
    Nokia5110_Init();
    Nokia5110_Clear();
    Nokia5110_ClearBuffer();
    Nokia5110_OutString("*----------*  LAP TRINH NHUNG NHOM 1PRESS SWITCH   TO PLAY  *----------*");
    xTaskCreate(vTask1,"Task 1",configMINIMAL_STACK_SIZE,(void *)0,3,xTaskHandle1);
    xTaskCreate(vTask2,"Task 2",configMINIMAL_STACK_SIZE,(void *)0,5,xTaskHandle2);
    xTaskCreate(vTask3,"Task 3",configMINIMAL_STACK_SIZE,(void *)0,1,xTaskHandle3);
    xTaskCreate(vTask4,"Task 4",configMINIMAL_STACK_SIZE,(void *)0,5,xTaskHandle4);
    xQueue1 = xQueueCreate(5,sizeof(int));
    vSemaphoreCreateBinary(xSemaphore1);
    vSemaphoreCreateBinary(xSemaphore2);
    vSemaphoreCreateBinary(xSemaphore3);
    xOneShotTimer = xTimerCreate("OneShot", pdMS_TO_TICKS(10000), pdFALSE, 0, prvOneShotTimerCallback);
    IntMasterEnable();
    //UARTprintf("%d",xPortGetFreeHeapSize());
    vTaskStartScheduler();
    while(1){

    }
}
