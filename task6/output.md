# Step-by-Step Process of Output Generation:

## 1. System Initialization
* The program starts by printing:
```
Starting Task Scheduler...
```
* This confirms that the scheduler is running.

## 2. System Tick Counter (Software Timer Mechanism)
* The scheduler runs in an infinite loop, checking task timers every 100 milliseconds (ms).
* Each task has a countdown timer that decreases every cycle:
    Task 1 (Logging) executes every 1000 ms (1 sec)
    Task 2 (Processing) executes every 2000 ms (2 sec)
    Task 3 (Virtual LED) executes every 3000 ms (3 sec)

## 3. Task Execution (Round-Robin Scheduling)
* When a task's countdown timer reaches zero, it executes and prints a message.
* After executing, the timer resets to its predefined value.

# Output displayed as on Serial monitor 

![image](https://github.com/user-attachments/assets/845697a6-f07b-4a06-aae8-a9f55276f598)
