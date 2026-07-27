#pragma once

class SLLNode {
public:
    int data;
    SLLNode* next;

    SLLNode(int val);
};

class SLL {
private:
    SLLNode* head;
    SLLNode* tail;

public:
    SLL();
    ~SLL();

    void push_front(int val);
    void pop_front();
    void push_back(int val);
    void pop_back();
    void insert(int val, int pos);
    void pop_specific(int val);
    void reverseList();
    int search(int val);
    void displayLL();
};
