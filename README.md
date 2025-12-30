# Embedded RTOS System Manager

This project (work in progress) implements a modular **real-time embedded system architecture** based on **STM32F4** and **FreeRTOS (CMSIS-RTOS v2)**.

The goal is to learn how to produce a **production-style RTOS design**, including deterministic task scheduling, fault handling, monitoring, and communication, following practices commonly used in **automotive, aerospace, and industrial embedded systems**.

## Architecture Overview

The system is organized into clear layers:
- **Application layer**: control, fault management, communication, and monitoring tasks
- **RTOS layer**: task creation, synchronization objects, and scheduling
- **Hardware abstraction**: STM32 HAL drivers (GPIO, UART, timers)

## Implemented Tasks

- **FaultManager Task** (event-driven, highest priority)  
  Handles critical system faults and safety-related events.

- **Control Task** (10 ms periodic)  
  Executes deterministic control logic.

- **Communication Task** (event-driven)  
  Manages UART-based communication using interrupt-to-task signaling.

- **Monitor Task** (100 ms periodic)  
  Provides system heartbeat and runtime health monitoring.

- **Logging Task** (low priority, best-effort)  
  Handles non-critical diagnostic output.

## Key Features

- CMSIS-RTOS v2 APIs
- Deterministic periodic scheduling using `osDelayUntil`
- Interrupt-safe task signaling
- Clear separation between ISR, RTOS, and application logic
- Portable and scalable architecture

## Target Platform

- **MCU**: STM32F407
- **RTOS**: FreeRTOS
- **Language**: C
- **Toolchain**: GCC / Makefile
- **Environment**: VS Code (Windows + WSL2)

---

This project focuses on **architecture and correctness**, not on end-product functionality.
