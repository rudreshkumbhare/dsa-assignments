# Data Structures & Algorithms in C++

A collection of my Data Structures & Algorithms implementations in C++ — from college course assignments to reusable data structure libraries.

Built while learning core CS concepts like linked lists, memory management, modular programming, file handling, and problem solving.

---

## 🛠️ Tech Stack

- **Language:** C++
- **Concepts Covered:**
  - Data Structures
  - Object-Oriented Programming
  - Dynamic Memory Allocation
  - File Handling
  - Modular Programming
  - Problem Solving

---

## 📊 Course Assignments

| Assignment | Topic | Description | Files |
| :--- | :--- | :--- | :--- |
| **Assignment 1** | Singly Linked List | Playlist Maker app with add, play, and deletion. | [`assignment1.cpp`](assignment1.cpp) |
| **Assignment 2** | Doubly Linked List | Text Editor with insert, delete, reverse and file persistent storage. | [`assignment2.cpp`](assignment2.cpp) |
| **Assignment 3** | Browser History using Stack | Browser History with tab addition and navigation. | [`assignment3.cpp`](assignment3.cpp) |
| **Assignment 4** | Infix to Prefix & Postfix Conversion and Evaluation | Conversion of Infix to Prefix & Postfix and evaluation of these expressions. | [`assignment4.cpp`](assignment4.cpp) |
| **Assignment 5** | Queue | Restaurant waitlist system with add party, seat party and display waitlist. | [`assignment5.cpp`](assignment5.cpp) |
| **Assignment 6** | Circular Queue | Customer checkout system with customer arrival and checkout, close checkout counter and view customer. | [`assignment6.cpp`](assignment6.cpp) |

---

## 🔧 How to Compile & Run Assignments

All implementations are written in standard C++. You can run any assignment using a terminal and a C++ compiler (like `g++`):

1. **Compile:**

```bash
g++ assignmentName.cpp -o assignmentName
```

2. **Run:**

```bash
./assignmentName
```

---

# ⭐ Personal Projects & Custom Libraries

## 📌 Custom C++ Linked List Library

A modular implementation of **Singly Linked List (SLL)**, **Doubly Linked List (DLL)** and **Circular Linked List (CLL)** split into header and implementation files.

This project was built to practice reusable code, modular programming, and understanding the internal working of linked list data structures.

* **Location:** `/linkedlist-library`

* **Files:**
  * [`SLL.h`](linkedlist-library/SLL.h) / [`SLL.cpp`](linkedlist-library/SLL.cpp) (Singly Linked List interface & implementation)
  * [`DLL.h`](linkedlist-library/DLL.h) / [`DLL.cpp`](linkedlist-library/DLL.cpp) (Doubly Linked List interface & implementation)
  * [`CLL.h`](linkedlist-library/CLL.h) / [`CLL.cpp`](linkedlist-library/CLL.cpp) (Circular Linked List interface & implementation)
  * [`main.cpp`](linkedlist-library/main.cpp) (Driver program for testing all the lists)

**Compilation & Usage:**

To compile and run the library with the test suite, navigate to the folder and run:

```bash
cd linkedlist-library
g++ SLL.cpp DLL.cpp CLL.cpp main.cpp -o main
./main
```

---

## 🚀 Future Additions

- More Data Structures implementations
- Additional C++ projects
