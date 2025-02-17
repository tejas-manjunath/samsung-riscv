#include <ch32v00x.h>
#include <stdio.h>

#define TASK_COUNT 3

uint32_t taskTimers[TASK_COUNT] = {0};  
uint32_t systemTime = 0;  


void delay_ms(uint32_t ms) {
    for (volatile uint32_t i = 0; i < (ms * 800); i++);
}


void print(const char *message) {
    printf("%s\n", message);
}


void task1_logData() {
    if (taskTimers[0] == 0) {
        print("[Task 1] Logging data...");
        taskTimers[0] = 1000;  
    }
}

void task2_processData() {
    if (taskTimers[1] == 0) {
        print("[Task 2] Processing data...");
        taskTimers[1] = 2000;  
    }
}

void task3_virtualLED() {
    static uint8_t ledState = 0;
    if (taskTimers[2] == 0) {
        ledState = !ledState;
        print(ledState ? "[Task 3] Virtual LED ON" : "[Task 3] Virtual LED OFF");
        taskTimers[2] = 3000;  
    }
}

void taskScheduler() {
    for (int i = 0; i < TASK_COUNT; i++) {
        if (taskTimers[i] > 0) {
            taskTimers[i] -= 100;  
        }
    }
    task1_logData();
    task2_processData();
    task3_virtualLED();
}

int main() {
 
    print("Starting Task Scheduler...");

    while (1) {
        taskScheduler();
        delay_ms(100);  
    }
}
