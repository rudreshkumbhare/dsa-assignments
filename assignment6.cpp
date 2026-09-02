#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

class CirclularQueue {
    int front, rear;

public:
    string a[MAX];

    CirclularQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(string x) {
        if ((rear + 1) % MAX == front) {
            cout << "Queue is full.\n";
            return;
        }

        if (front == -1) front = 0;
        
        rear = (rear + 1) % MAX;
        a[rear] = x;
        cout << "Customer arrived.\n";
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << a[front] << " is served.\n";
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

        cout << "Customers in queue:\n";
        int i = front;
        while (true) {
            cout << "Customer " << i + 1 << ": " << a[i] << endl;
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }

    void closeCounter() {
        if (front == -1) {
            cout << "No customers waiting.\n";
            cout << "Checkout counter closed.\n";
            return;
        }

        cout << "\nServing remaining customers...\n";
        while (front != -1) {
            cout << a[front] << " is served.\n";
            if (front == rear) {
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % MAX;
            }
        }
        cout << "All customers have been served.\n";
        cout << "Checkout counter closed.\n";
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
    string customerName;

    do {
        cout << "\n—————————— Supermarket Checkout System ——————————\n";
        cout << "\n1. Customer Arrival\n";
        cout << "2. Customer Checkout\n";
        cout << "3. View Customers in Queue\n";
        cout << "4. Close Checkout Counter\n";
        cout << "5. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (!q.isFull()) {
                    cout << "Enter customer name: ";
                    cin >> customerName;
                    q.enqueue(customerName);
                }
                else {
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
                q.closeCounter();
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
    return 0;
}
