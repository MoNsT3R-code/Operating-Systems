# Operating-Systems: Low-Level Kernel & Systems Engineering Laboratory

A comprehensive repository containing low-level systems programming implementations, POSIX concurrency systems, Inter-Process Communication (IPC) frameworks, and kernel scheduler affinity evaluations written in C.

![Language](https://img.shields.io/badge/Language-C99%20%2F%20POSIX-blue?logo=c&logoColor=white)
![Domain](https://img.shields.io/badge/Domain-Operating%20Systems-purple)
![Kernel Features](https://img.shields.io/badge/Subsystems-IPC%20%2F%20Signals%20%2F%20Threads-orange)
![Scheduling](https://img.shields.io/badge/Affinity-CPU%20Core%20Binding-darkgreen)
![Environment](https://img.shields.io/badge/Environment-Linux%20%2F%20GCC-lightgrey)

---

## 🌐 Engine Overview

The Operating-Systems laboratory framework focuses on design boundaries, process lifecycles, and shared system resources under UNIX architectures. Spanning high-performance parallel summations, hardware sensor unit mocks, strict producer-consumer circular queues, and custom process resource monitors, this repository isolates raw computational routines from thread execution synchronization contexts.

---

## 📍 Quick Navigation

* [🌐 Project Overview](#-engine-overview)
* [💻 Languages & Technologies Used](#%EF%B8%8F-tech-stack)
* [📁 Repository Structure and Module Index](#-repository-structure-and-module-index)
* [🧱 Document Structure (`cpu_affinity_test.c`)](#-repository-structure-and-module-index)
* [⚙️ Application Logic (`proc_monitor.c`)](#-architectural-highlights)

---

## 📦 System Architecture

<div align="center">

```text
┌──────────────────────────────────────────────────────────────────┐
│                    USER SPACE SHELL INTERACTION                  │
├──────────────────────────────────────────────────────────────────┤
│                POSIX Signal Traps / Terminal IO                  │ 
│                (SIGINT, SIGKILL, Custom Buffers)                 │
└──────────────────────────────┬───────────────────────────────────┘
                               ↓
┌──────────────────────────────────────────────────────────────────┐
│                 POSIX KERNEL SYSTEM CALL INTERFACE               │
├────────────┬─────────────┬────────────┬─────────────┬────────────┤
│ Process    │ Pthread Sync│ IPC Shared │ CPU Core    │ File I/O   │
│ Lifecycle  │ Mutexes &   │ Memory     │ Affinity    │ Stream     │
│ (`fork()`) │ Semaphores  │ Channels   │ Schedulers  │ Descriptors│
└────────────┴─────────────┴────────────┴─────────────┴────────────┘
                               ↓
┌──────────────────────────────────────────────────────────────────┐
│                 HARDWARE ARCHITECTURE LINK                       │
├──────────────────────────────────────────────────────────────────┤
│         Multi-Core Execution Slices & Memory Pages               │
└──────────────────────────────────────────────────────────────────┘

```

| Architectural Layer | Core Components & Strategies | Quick Links / Reference |
| --- | --- | --- |
| **Top: Application** | Asynchronous signal capture loops and runtime terminal arguments | [Setup & Execution Guide](https://www.google.com/search?q=%23-setup--execution-guide) |
| **Middle: System Call** | Inter-process piping, synchronized multi-threading, and core mask filters | [Repository Structure](https://www.google.com/search?q=%23-repository-structure-and-module-index) |
| **Bottom: Hardware** | Deterministic process allocation onto explicit logical CPU nodes | [Application Core Interfaces](https://www.google.com/search?q=%23-application-core-interfaces) |

---

## ✨ Key Architecture Features

✅ **Advanced Concurrency Models** - Spawns decoupled processes (`fork()`) and lightweight threads (`pthread_create`) while resolving race hazards via transactional mutex barriers.

✅ **Robust IPC Networks** - Architectures communications using shared storage fields, standard pipelines (`pipe()`), and synchronized producer-consumer rings.

✅ **Scheduler Core Binding** - Implements strict kernel-level core masking (`sched_setaffinity`) to bind specific execution execution branches onto explicit hardware nodes.

✅ **Asynchronous Signal Routing** - Injects robust handlers to catch and parse asynchronous operating system triggers (`SIGALRM`, `SIGUSR1`) without causing dangling process trees.

---

## 📁 Repository Structure and Module Index

The codebase is meticulously partitioned across systemic system challenges and modular assignments:

### ⚙️ Kernel Scheduling & Process Control

* **`cpu_affinity_test.c`** - Evaluates asymmetric scheduling policies by binding active thread executions to single logical processing units.
* **`proc_monitor.c`** - High-density process tracking script managing execution metrics, state transitions, and usage limits.
* **`A2OS.c` & `T3OS.c**` - Comprehensive systems engineering modules handling high-order system pipelines and multi-tiered worker structures.

### 🔄 Multi-Threading, IPC, & Synchronization

* **`task2_ipc.c`** - Manages messaging between independent memory spaces using native UNIX message channels.
* **`lab6prod (1).c` & `lab6cons (1).c**` - Canonical producer-consumer coordination engine utilizing thread semaphores to regulate a circular storage array.
* **`parsum.c`** - Leverages multi-threaded map-reduce loops to calculate parallel summations over split numeric arrays.
* **`Lab 9 (signals) - B.c`** - Registers signal routines to intercept and route hardware alerts smoothly.

### 🛠️ Lab Foundations & Support Scripts

* **`SensorUnit.c`** - Simulates external tracking arrays writing telemetry parameters directly to system output points.
* **`Lab4Task2OS.c` to `lab11B.c**` - Hierarchical sequence of incremental laboratory scripts tracing standard library descriptors, thread weights, and memory configurations.

---

## 🛠️ Tech Stack

| Component | Technology | Quick Links |
| --- | --- | --- |
| **Development Language** | C (ISO/IEC 9899:1999 C99 System Distribution) | [C Language Standards](https://www.google.com/search?q=https://en.cppreference.com/w/c) |
| **API Blueprint** | POSIX Threads (`pthread`) & System Extensions | [IEEE POSIX Specification](https://www.google.com/search?q=https://standards.ieee.org/) |
| **Compilation Suite** | GCC Toolchain (GNU Compiler Collection) | [gcc.gnu.org](https://www.google.com/search?q=https://gcc.gnu.org/) |
| **Debugging Tools** | GDB and Native System Tracers (`strace`, `lsof`) | [GNU GDB Docs](https://www.google.com/search?q=https://www.gnu.org/software/gdb/) |

---

## 💻 System Requirements

Ensure your execution environment adheres to the following baseline parameters:

* **Operating System:** Linux-based Kernel footprint (Ubuntu 20.04 LTS or newer recommended).
* **Compiler Architecture:** GNU GCC supporting standard modern C dialects.
* **Hardware Profiles:** Multi-core physical processor to properly evaluate core affinity scheduling metrics.

---

## 🚀 Setup & Execution Guide

### Step 1: Clone the Kernel System Environment

Download the systems architecture folder onto your active Linux workspace:

```bash
git clone [https://github.com/MoNsT3R-code/Operating-Systems.git](https://github.com/MoNsT3R-code/Operating-Systems.git)
cd Operating-Systems

```

### Step 2: Compile the Concurrency Modules

Utilize GCC to translate the core low-level C files into native system binaries:

```bash
# Compile Affinity Testing Engines
gcc -Wall -Wextra -std=c99 cpu_affinity_test.c -o affinity_engine

# Compile Concurrency Monitoring Subsystems
gcc -Wall -Wextra -std=c99 proc_monitor.c -o process_monitor

# Compile Synchronized Thread Routines (Requires explicit pthread binding flag)
gcc -Wall -Wextra -std=c99 parsum.c -lpthread -o parallel_sum

```

### Step 3: Execute and Monitor Core Tasks

Execute the generated system binaries directly through your active console instance:

```bash
# Run the scheduler affinity binding check
./affinity_engine

# Run the system multi-threaded parallel computation module
./parallel_sum

```

---

## 📊 Application Core Interfaces

The workspace systematically partitions task constraints across clear operational silos:

| System Layer | Interface Mechanics | Target Objective | Primary Performance Monitor |
| --- | --- | --- | --- |
| **CPU Scheduling** | `sched_setaffinity` Matrix | Locks thread loops to explicit execution pipelines. | CPU Migrations Log |
| **Thread Control** | POSIX Mutexes / Conditional Checks | Regulates access to shared variables, eliminating collisions. | Thread Join Lifecycle |
| **IPC Routing** | Pipes, Shared Fields, Signals | Broadcasts operational states across disjointed process domains. | Signal Action Vectors |

---

## 🏗️ Architectural Highlights

### 🎯 Direct CPU Core Mapping Mechanics

The scheduling layer manages processor assignment flags by writing structural thread bitmasks directly into the system scheduler. This approach isolates critical threads onto dedicated hardware cores, optimizing real-time processing tasks:

$$\text{CoreMask} = 1 \ll \text{TargetCoreID}$$

### 🔐 Multi-Threaded Memory Boundary Security

To prevent critical memory overwrites, the multi-threading components enforce strict isolation. Independent workers interact through a highly controlled synchronization layout, preventing thread collisions and ensuring reliable data pipelines.

---

## 📄 License & Terms

This project is open-source. Feel free to copy, modify, and redistribute the systems engineering scripts and low-level code blocks as required.
