#  Task Scheduler Simulation using RISC-V Processor

## Overview:
This project implements a simple task scheduler using a RISC-V processor to simulate multitasking in an embedded system. It schedules multiple tasks such as logging, data processing, and virtual LED control using a Round-Robin algorithm without an RTOS. The scheduler ensures that each task gets executed at predefined time intervals, demonstrating cooperative multitasking.

## Features:
* Simulates multiple tasks executing at different time intervals.
* Uses software timers instead of hardware interrupts.
* Implements Round-Robin scheduling without an RTOS.
* Works entirely in software (no hardware needed).
* Outputs logs via serial monitor for real-time debugging.

## Components Required:
* RISC-V Processor (VSDquadron Mini)
* Serial Communication (UART for debugging)
* Software-based Timers

## Process of Implementation:

**1. Define Tasks and Timing:**
* Task 1: Logging data (executes every 1 second)
* Task 2: Processing data (executes every 2 seconds)
* Task 3: Virtual LED toggling (executes every 3 seconds)

**2.Configure the Task Scheduler**
* Use a system tick counter to keep track of time.
* Each task has a timer value that decrements every tick.
* When a task’s timer reaches zero, it executes and resets its timer.

**3.Implement the Task Execution Logic:**
* The scheduler loops infinitely, checking and executing tasks.
* Each task runs cooperatively, meaning one must finish before the next begins.
* The scheduler assigns time slots for fair execution.

**4.Display Output via Serial Monitor:**
* Use printf() to display when each task executes.
* Serial output simulates real-world task execution logs.

**5.Test and Debug:**
* Run the system in PlatformIO Serial Monitor.
* Check whether tasks execute at correct intervals.
* Fine-tune timing for better task management.
