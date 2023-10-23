#ifndef TASKS_H
#define TASKS_H

typedef void* TaskHandle_t;
typedef int BaseType_t;
typedef unsigned int TickType_t;

#define pdPASS        (1)
#define pdFAIL        (0)
#define pdTRUE        (1)
#define pdFALSE       (0)
#define pdMS_TO_TICKS(xTimeInMs) ((TickType_t)(((TickType_t)(xTimeInMs)) / portTICK_PERIOD_MS))

void vTaskStartScheduler(void);
BaseType_t xTaskCreate(void (*)(void*), const char*, unsigned short, void*, unsigned portBASE_TYPE, TaskHandle_t*);
void vTaskDelay(TickType_t xTicksToDelay);
void vTaskDelete(TaskHandle_t xTask);

#endif /* TASKS_H */
