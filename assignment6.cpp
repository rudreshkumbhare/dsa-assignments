#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

class CirclularQueue {
    int front, rear;
public:
    int a[MAX];
    CirclularQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int x) {
        if ((rear + 1) % MAX == front) {
            cout << "Queue is full.\n";
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        a[rear] = x;
        cout << "Customer arrived\n";
    }
    
    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Customer served\n";
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Customers in queue: \n";
        int i = front;
        while (true) {
            cout << "Customer " << i+1 << ": " << a[i] << endl;
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }

    bool isFull() {
        return (rear + 1) % MAX == front;
    }

    bool isEmpty() {
        return front == -1;
    }
};

int main() {
    CirclularQueue q;
    int choice = 0;
    int customerID = 1;

    do {
        cout << "\n—————————— Supermarket Checkout System ——————————\n";
        cout << "\n1. Customer Arrival\n";
        cout << "2. Customer Checkout\n";
        cout << "3. View Customers in Queue\n";
        cout << "4. Close Checkout Counter\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (!q.isFull()) {
                    q.enqueue(customerID);
                    customerID++;
                } else {
                    cout << "Queue is full! Cannot add more customers.\n";
                }
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Closing checkout counter. Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}