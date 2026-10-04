#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string title;
    int id;
    Node *left, *right;
    int lth, rth;

    Node() {
        left = right = NULL;
        lth = rth = 1;
    }
};

class TBST {
public:
    Node *head, *root;

    TBST() {
        head = new Node();
        head->title = "head";
        head->id = 2147483647;

        head->left = NULL;
        head->right = head;

        head->lth = 0;
        head->rth = 1;

        root = NULL;
    }

    Node* search(int key) {
        Node *temp = root;

        while (temp != NULL && temp != head) {
            if (key == temp->id) {
                cout << "Book Found\n";
                cout << "ID: " << temp->id << endl;
                cout << "Title: " << temp->title << endl;
                return temp;
            }
            if (key < temp->id) {
                if (temp->lth == 0) temp = temp->left;
                else break;
            } else {
                if (temp->rth == 0) temp = temp->right;
                else break;
            }
        }
        cout << "Book Not Found\n";
        return NULL;
    }

    void insert() {
        Node *newnode = new Node();

        int id;
        string title;

        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Title: ";
        cin >> title;

        newnode->id = id;
        newnode->title = title;

        if (root == NULL) {
            newnode->left = head;
            newnode->right = head;

            newnode->lth = 1;
            newnode->rth = 1;

            root = newnode;
            head->left = root;

            cout << "Book inserted successfully\n";
            return;
        }

        Node *temp = root;
        while (true) {
            if (id < temp->id) {
                if (temp->lth == 1) {
                    newnode->left = temp->left;
                    newnode->right = temp;

                    newnode->lth = 1;
                    newnode->rth = 1;

                    temp->left = newnode;
                    temp->lth = 0;

                    cout << "Book inserted on left\n";
                    break;
                }
                temp = temp->left;
            } else if (id > temp->id) {
                if (temp->rth == 1) {
                    newnode->right = temp->right;
                    newnode->left = temp;

                    newnode->lth = 1;
                    newnode->rth = 1;

                    temp->right = newnode;
                    temp->rth = 0;

                    cout << "Book inserted on right\n";
                    break;
                }
                temp = temp->right;
            } else {
                cout << "Book ID already exists\n";
                delete newnode;
                return;
            }
        }
    }

    Node* inorderSuccessor(Node *temp) {
        if (temp->rth == 1) return temp->right;
        temp = temp->right;

        while (temp->lth == 0)
            temp = temp->left;
        return temp;
    }

    void inorder() {
        if (root == NULL) {
            cout << "Library is empty\n";
            return;
        }

        Node *temp = root;
        
        while (temp->lth == 0)
            temp = temp->left;
        cout << "\nLibrary Books (Inorder):\n";

        while (temp != head) {
            cout << "ID: " << temp->id
                 << " | Title: " << temp->title << endl;
            temp = inorderSuccessor(temp);
        }
    }
};

int main() {
    TBST t;
    int choice;
    int key;

    do {
        cout << "\n===== Library Book Index =====\n";
        cout << "1. Insert Book\n";
        cout << "2. Search Book\n";
        cout << "3. Display Books (Inorder)\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            t.insert();
            break;

        case 2:
            cout << "Enter Book ID to search: ";
            cin >> key;
            t.search(key);
            break;

        case 3:
            t.inorder();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}