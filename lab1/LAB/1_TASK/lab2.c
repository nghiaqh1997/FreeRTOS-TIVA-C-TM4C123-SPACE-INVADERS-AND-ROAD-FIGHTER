//TaskHandle_t TaskHandle2;
//char *text1 = "Task 1 is running\n";
//char *text2 = "Task 2 is running\n";
//void vTask1(void *pvParameters){
//    char *pcText;
//    pcText = (char *)pvParameters;
//    UBaseType_t uxPriority = uxTaskPriorityGet(TaskHandle2);
//    while(1){
//        printf("%s",pcText);
//        vTaskPrioritySet(TaskHandle2, uxPriority+2);
//        //vTaskDelay(pdMS_TO_TICKS(100));
//    }
//}
//void vTask2(void *pvParameters){
//    char *pcText;
//    pcText = (char *)pvParameters;
//    portTickType xLastWakeTime = xTaskGetTickCount();
//    UBaseType_t uxPriority = uxTaskPriorityGet(NULL);
//    while(1){
//        printf("%s",pcText);
//        vTaskPrioritySet(TaskHandle2, uxPriority-2);
//        //vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(100));
//    }
//}
//int main(){
//    vSetupHardware();
//    UART_Init();
//    xTaskCreate(vTask1, "Task 1", 200, (void *)text1, 2, NULL);
//    xTaskCreate(vTask2, "Task 2", 200, (void *)text2, 1, &TaskHandle2);
//    vTaskStartScheduler();
//    while(1){
//
//    }
//}
//
//
//
//
