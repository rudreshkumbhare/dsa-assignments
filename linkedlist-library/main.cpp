#include <iostream>
#include "SLL.h"
#include "DLL.h"
#include "CLL.h"
using namespace std;

int main() {
    cout << "========================================\n";
    cout << "   Testing Singly Linked List (SLL)     \n";
    cout << "========================================\n";
    SLL sll;
    sll.push_front(2);
    sll.push_front(1);
    sll.push_back(3);
    sll.push_back(5);
    cout << "SLL initial: ";
    sll.displayLL();

    sll.insert(4, 4);
    cout << "SLL after insert(4, 4): ";
    sll.displayLL();

    sll.pop_specific(3);
    cout << "SLL after pop_specific(3): ";
    sll.displayLL();

    cout << "\n========================================\n";
    cout << "   Testing Doubly Linked List (DLL)     \n";
    cout << "========================================\n";
    DLL dll;
    dll.push_front(2);
    dll.push_front(1);
    dll.push_back(3);
    dll.push_back(5);
    cout << "DLL initial: ";
    dll.displayDLL();

    dll.insert(4, 5);
    cout << "DLL after insert(4, 5): ";
    dll.displayDLL();

    dll.pop_specific(3);
    cout << "DLL after pop_specific(3): ";
    dll.displayDLL();

    cout << "\n========================================\n";
    cout << "   Testing Circular Linked List (CLL)   \n";
    cout << "========================================\n";
    CLL cll;
    cll.insertAtHead(2);
    cll.insertAtHead(1);
    cll.insertAtTail(3);
    cll.insertAtTail(5);
    cout << "CLL initial: ";
    cll.displayCLL();

    cll.insert(4, 4);
    cout << "CLL after insert(4, 4): ";
    cll.displayCLL();

    cll.deleteSpecific(3);
    cout << "CLL after deleteSpecific(3): ";
    cll.displayCLL();

    return 0;
}
