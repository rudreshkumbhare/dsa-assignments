#ifndef CLL_H
#define CLL_H

class CLLNode {
public:
    int data;
    CLLNode* next;

    Node(int val);
};

class CLL {
    CLLNode* head;
    CLLNode* tail;

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
