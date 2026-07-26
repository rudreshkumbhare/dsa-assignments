#ifndef CLL_H
#define CLL_H

class Node {
public:
    int data;
    Node* next;

    Node(int val);
};

class CLL {
    Node* head;
    Node* tail;

public:
    CLL();
    ~CLL();

    void insertAtHead(int val);
    void insertAtTail(int val);
    void insert(int val, int pos);
    void deleteAtHead();
    void deleteAtTail();
    void deleteSpecific(int val);
    int search(int val);
    void displayCLL();
};

#endif
