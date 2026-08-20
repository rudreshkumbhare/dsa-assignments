#include <iostream>
using namespace std;

class Node{
public:
    string data;
    Node* next;

    Node(string val){
        data = val;
        next = NULL;
    }
};

class Stack{
    Node* top;
    int count = 0;

public:
    Stack(){
        top = NULL;
    }

    void push(string val){
        Node* newNode = new Node(val);
        if (top == NULL) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
        count++;
    }

    void pop(){
        if (top == NULL) {
            cout << "Nothing in the history to remove.\n";
        return; 
        }

        Node* temp = top;
        top = top->next;
        cout << "Tab (URL: " << temp->data << ")" << " removed succesfully.\n";
        delete temp;
        count--;
    }

    void peek() {
        if (top == NULL) {
            isEmpty();
        } else {
            cout << "Current tab: " << top->data << endl;
        }
    }

    void isEmpty(){
        if (top == NULL) {
            cout << "History is empty.\n";
            return;
        } else {
            cout << "History is not empty.\n";
            display();
        }
    }

    void display() {
        int number = count;
        Node* temp = top;
        cout << "\n ----- CURRENT HISTORY -----\n";
        while (temp != NULL) {
            cout << "Tab " << number << ": " << temp->data << endl;
            number--;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice;
    string url;

    do {
        cout << "\n ----- BROWSER HISTORY -----\n";
        cout << "1. Add visited page\n2. Navigate back\n3. View current page\n4. Check if history is empty or not\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
        case 1:
            cout << "Enter your tab URL: ";
            cin >> url;
            s.push(url);
            cout << "Tab added to history.\n";
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.isEmpty();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice entered. Try again!\n";
            break;
        }   
    } while (choice != 5);

return 0;
}