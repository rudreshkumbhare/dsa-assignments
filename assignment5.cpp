#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;

class Queue {
    int front, rear;
public:
    int a[MAX]; 
    Queue() {
        front = -1;
        rear = -1;
    }

    void add_party(int x) {
        if (rear == MAX - 1) {
            cout << "Waitlist is full\n";
            return;
        }
        if (front == -1) front = 0;
        a[++rear] = x;
        cout << "Party of size " << x << " added to waitlist\n";
    }
    
    void seat_party() {
        if (front == -1 || front > rear) {
            cout << "Waitlist is empty\n";
            return;
        }
        front++;
        cout << "Party of size " << a[front-1] << " seated\n";
    }

    void display_waitlist() {
        if (front == -1 || front > rear) {
            cout << "Waitlist is empty\n";
            return;
        }
        cout << "—————————— Current Waitlist ——————————\n";
        for (int i = front; i <= rear; i++)
            cout << "Party size " << i+1 << ": " << a[i] << endl;
    }
};

int main() {
    Queue q1;
    int choice;
    do {
        cout << "\n—————————— Restaurant Waitlist Management System ——————————\n";
        cout << "\n1. Add party to waitlist\n";
        cout << "2. Seat party\n";
        cout << "3. Display waitlist\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int party_size;
                cout << "Enter party size: ";
                cin >> party_size;
                q1.add_party(party_size);
                break;
            }
            case 2:
                q1.seat_party();
                break;
            case 3:
                q1.display_waitlist();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}