#include "FreeRTOS.h"
#include "tasks.h"
#include "FreeRTOSConfig.h"
#include <stdio.h>
#include <stddef.h> 
void Task1(void *pvParameters) {
    while (1) {
        printf("Task 1 is running\n");
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1 second
    }
}

void Task2(void *pvParameters) {
    while (1) {
        printf("Task 2 is running\n");
        vTaskDelay(pdMS_TO_TICKS(2000)); // Delay for 2 seconds
    }
}

int main() {
    xTaskCreate(Task1, "Task 1", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
    xTaskCreate(Task2, "Task 2", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    vTaskStartScheduler();

    while (1);
    return 0;
}
