#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#define configUSE_PREEMPTION        1
#define configUSE_IDLE_HOOK         0
#define configUSE_TICK_HOOK         0
#define configTICK_RATE_HZ          ((TickType_t)1000)
#define configMAX_PRIORITIES        (7)
#define configMINIMAL_STACK_SIZE    ((unsigned short)128)
#define configTOTAL_HEAP_SIZE       ((size_t)(15 * 1024))
#define configMAX_TASK_NAME_LEN     (16)
#define configUSE_TRACE_FACILITY    0
#define configUSE_16_BIT_TICKS      0
#define configIDLE_SHOULD_YIELD     1
#define configCHECK_FOR_STACK_OVERFLOW 2
#define configUSE_MALLOC_FAILED_HOOK 1
#define configUSE_APPLICATION_TASK_TAG 0
#define configUSE_QUEUE_SETS        1
#define configUSE_TIME_SLICING      0
#define configUSE_NEWLIB_REENTRANT  0
#define configENABLE_BACKWARD_COMPATIBILITY 0

#define INCLUDE_vTaskPrioritySet        1
#define INCLUDE_uxTaskPriorityGet       1
#define INCLUDE_vTaskDelete             1
#define INCLUDE_vTaskCleanUpResources   1
#define INCLUDE_vTaskSuspend            1
#define INCLUDE_vTaskDelayUntil         1
#define INCLUDE_vTaskDelay              1

#define configENABLE_FPU                1
#define configENABLE_MPU                0

#define configUSE_DAEMON_TASK_STARTUP_HOOK 0
#define configUSE_IDLE_HOOK              0
#define configUSE_TICK_HOOK              0
#define configCHECK_FOR_STACK_OVERFLOW   2
#define configUSE_MALLOC_FAILED_HOOK     1

#endif /* FREERTOS_CONFIG_H */
