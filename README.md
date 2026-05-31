# APC – Arbitrary Precision Calculator (DSA Project)

## 📌 Description
The **Arbitrary Precision Calculator (APC)** is a **C-based Data Structures project**
that performs arithmetic operations on **very large integers** which exceed the
limits of built-in data types such as `int` and `long long`.

The calculator represents numbers using **dynamic data structures** and supports
all basic arithmetic operations, including **division**.  
This project focuses on **linked list manipulation, memory management, and
algorithmic problem solving**, which are core concepts in DSA and system-level
programming.

---

## 🧠 Concepts Used
- Linked lists
- Dynamic memory allocation
- Structures
- Pointers
- String to number conversion
- Modular programming

---

## ➕ Supported Operations
- Addition
- Subtraction
- Multiplication
- Division

---

## 📁 File Structure

```
apc/
├── main.c        # Program entry point and user interaction
├── functions.c   # Arithmetic operations and linked list logic
├── apc.h         # Structure definitions and function declarations
└── README.md
```

---

## ▶️ Build and Run

### Compile
```bash
gcc *.c -o apc
```

### Run
```bash
./apc
```

Follow the on-screen instructions to enter large numbers and select operations.

---

## 🔍 How It Works
1. Input numbers are read as strings.
2. Each digit (or block of digits) is stored in a **linked list node**.
3. Arithmetic operations (add, subtract, multiply, divide) are performed
   node-by-node using DSA logic.
4. The final result is displayed without any data type size limitation.

---

## 🛠️ Tools & Environment
- **Language:** C (ANSI C / C99 compliant)
- **Compiler:** GCC
- **OS:** Linux
- **Version Control:** Git

---
