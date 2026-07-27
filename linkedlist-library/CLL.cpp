#include <iostream>
#include "CLL.h"
using namespace std;

CLLNode::CLLNode(int val) {
    data = val;
    next = NULL;
}

CLL::CLL() {
    head = tail = NULL;
}

CLL::~CLL() {
    while (head != NULL) {
        deleteAtTail();
    }
}

void CLL::insertAtHead(int val) {
    CLLNode* newNode = new CLLNode(val);
    if (head == NULL) {
        head = tail = newNode;
        tail->next = head;
    } else {
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }
}

void CLL::insertAtTail(int val) {
    CLLNode* newNode = new CLLNode(val);
    if (head == NULL) {
        head = tail = newNode;
        tail->next = head;
    } else {
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }
}

void CLL::deleteAtHead() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }

    CLLNode* temp = head;
    head = head->next;
    tail->next = head;
    delete temp;
}

void CLL::deleteAtTail() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }

    CLLNode* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }

    delete tail;
    tail = temp;
    tail->next = head;
}

void CLL::insert(int val, int pos) {
    if (pos < 1) return;

    if (pos == 1) {
        insertAtHead(val);
        return;
    }

    if (head == NULL) return;

    CLLNode* temp = head;
    for (int i = 0; i < pos - 2; i++) {
        temp = temp->next;
        if (temp == head) return;
    }

    if (temp == tail) {
        insertAtTail(val);
        return;
    }

    CLLNode* newNode = new CLLNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

void CLL::deleteSpecific(int val) {
    if (head == NULL) return;

    if (head->data == val) {
        deleteAtHead();
        return;
    }

    CLLNode* temp = head;
    while (temp->next != head && temp->next->data != val) {
        temp = temp->next;
    }

    if (temp->next == head) return;

    if (temp->next == tail) {
        deleteAtTail();
        return;
    }

    CLLNode* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}

int CLL::search(int val) {
    if (head == NULL) return -1;

    CLLNode* temp = head;
    int idx = 0;

    do {
        if (temp->data == val) {
            return idx;
        }
        temp = temp->next;
        idx++;
    } while (temp != head);

    return -1;
}

void CLL::displayCLL() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    CLLNode* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(head: " << head->data << ")\n";
}
