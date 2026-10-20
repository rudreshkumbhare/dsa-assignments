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

<table>
  <thead>
    <tr>
      <th width="16%">Assignment</th>
      <th width="22%">Topic</th>
      <th width="44%">Description</th>
      <th width="18%">Files</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><strong>Assignment 1</strong></td>
      <td>Singly Linked List</td>
      <td>Playlist Maker app with add, play, and deletion.</td>
      <td><a href="assignment1.cpp"><code>assignment1.cpp</code></a></td>
    </tr>
    <tr>
      <td><strong>Assignment 2</strong></td>
      <td>Doubly Linked List</td>
      <td>Text Editor with insert, delete, reverse and file persistent storage.</td>
      <td><a href="assignment2.cpp"><code>assignment2.cpp</code></a></td>
    </tr>
    <tr>
      <td><strong>Assignment 3</strong></td>
      <td>Browser History using Stack</td>
      <td>Browser History with tab addition and navigation.</td>
      <td><a href="assignment3.cpp"><code>assignment3.cpp</code></a></td>
    </tr>
    <tr>
      <td><strong>Assignment 4</strong></td>
      <td>Infix to Prefix &amp; Postfix Conversion and Evaluation</td>
      <td>Conversion of Infix to Prefix &amp; Postfix and evaluation of these expressions.</td>
      <td><a href="assignment4.cpp"><code>assignment4.cpp</code></a></td>
    </tr>
    <tr>
      <td><strong>Assignment 5</strong></td>
      <td>Queue</td>
      <td>Restaurant waitlist system with add party, seat party and display waitlist.</td>
      <td><a href="assignment5.cpp"><code>assignment5.cpp</code></a></td>
    </tr>
    <tr>
      <td><strong>Assignment 6</strong></td>
      <td>Circular Queue</td>
      <td>Customer checkout system with customer arrival and checkout, close checkout counter and view customer.</td>
      <td><a href="assignment6.cpp"><code>assignment6.cpp</code></a></td>
    </tr>
    <tr>
      <td><strong>Assignment 7</strong></td>
      <td>BST</td>
      <td>Dictionary system with insertion, deletion, search, mirroring, copying, level-wise display, and path-sum checking.</td>
      <td><a href="assignment7.cpp"><code>assignment7.cpp</code></a></td>
    </tr>
    <tr>
      <td><strong>Assignment 8</strong></td>
      <td>TBST</td>
      <td>Library book indexing system with book insertion, ID-based search, and inorder traversal using threads.</td>
      <td><a href="assignment8.cpp"><code>assignment8.cpp</code></a></td>
    </tr>
    <tr>
      <td><strong>Assignment 9</strong></td>
      <td>Graph</td>
      <td>Maze-solving system using DFS and BFS to find paths from the starting point to the goal while avoiding blocked cells.</td>
      <td><a href="assignment9.cpp"><code>assignment9.cpp</code></a></td>
    </tr>
    <tr>
      <td><strong>Assignment 10</strong></td>
      <td>Graph</td>
      <td>College campus network using Prim’s algorithm to connect departments with minimum total distance.</td>
      <td><a href="assignment10.cpp"><code>assignment10.cpp</code></a></td>
    </tr>
    <tr>
      <td><strong>Assignment 11</strong></td>
      <td>Graph</td>
      <td>Supply chain network using Dijkstra’s algorithm to find the shortest transportation routes between locations.</td>
      <td><a href="assignment11.cpp"><code>assignment11.cpp</code></a></td>
    </tr>
  </tbody>
</table>

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
