#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Node {
public:
    int key;
    string value;
    Node* left;
    Node* right;

    Node(int k, string v) {
        key = k;
        value = v;
        left = NULL;
        right = NULL;
    }
};

class Dictionary {
private:
    Node* root;

    Node* insert(Node* root, int key, string value) {
        if (root == NULL) {
            return new Node(key, value);
        }

        if (key < root->key) {
            root->left = insert(root->left, key, value);
        } else if (key > root->key) {
            root->right = insert(root->right, key, value);
        } else {
            cout << "Duplicate word! Entry already exists.\n";
        }
        return root;
    }

    Node* deleteNode(Node* root, int key) {
        if (root == NULL) {
            return root;
        }
        if (key < root->key) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = minValueNode(root->right);

            root->key = temp->key;
            root->value = temp->value;

            root->right = deleteNode(root->right, temp->key);
        }
        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    Node* search(Node* root, int key) {
        if (root == NULL)
            return NULL;

        if (key == root->key)
            return root;

        if (key < root->key)
            return search(root->left, key);

        return search(root->right, key);
    }

    void inorder(Node* root) {
        if (root == NULL)
            return;
        
        inorder(root->left);
        cout << root->key << " : " << root->value << endl;
        inorder(root->right);
    }

    void mirror(Node* root) {
        if (root == NULL)
            return;

        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;

        mirror(root->left);
        mirror(root->right);
    }

    Node* copyTree(Node* root) {
        if (root == NULL)
            return NULL;

        Node* newNode = new Node(root->key, root->value);
        newNode->left = copyTree(root->left);
        newNode->right = copyTree(root->right);

        return newNode;
    }

    bool checkPathSum(Node* root, int sum) {
        if (root == NULL) return false;

        if (root->left == NULL && root->right == NULL)
            return sum == root->key;

        int remainingSum = sum - root->key;

        return checkPathSum(root->left, remainingSum) ||
            checkPathSum(root->right, remainingSum);
    }   

public:
    Dictionary() {
        root = NULL;
    }
    
    void insertWord(int key, string value) {
        root = insert(root, key, value);
    }

    void deleteWord(int key) {
        if (search(root, key) == NULL) {
            cout << "Word not found.\n";
            return;
        }

        root = deleteNode(root, key);
        cout << "Word deleted successfully.\n";
    }

    void searchWord(int key) {
        Node* result = search(root, key);

        if (result == NULL) {
            cout << "Word not found.\n";
        }
        else {
            cout << "Word found:\n";
            cout << "Key: " << result->key << endl;
            cout << "Value: " << result->value << endl;
        }
    }

    void display() {
        if (root == NULL) {
            cout << "Dictionary is empty.\n";
            return;
        }

        cout << "\nDictionary:\n";
        inorder(root);
    }

    void mirrorDictionary() {
        mirror(root);
        cout << "Dictionary mirrored successfully.\n";
    }

    Dictionary createCopy() {
        Dictionary copy;
        copy.root = copyTree(root);
        return copy;
    }

    void displayLevelWise() {
        if (root == NULL) {
            cout << "Dictionary is empty.\n";
            return;
        }
        
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();

            while (n--) {
                Node* temp = q.front();
                q.pop();
                
                cout << temp->key << " : " << temp->value << "    ";
                
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            cout << endl;
        }
    }

    void pathSum(int sum) {
        if (checkPathSum(root, sum)) {
            cout << "True\n";
        } else {
            cout << "False\n";
        }
    }
};

int main() {
    Dictionary dict;

    int choice;
    int key;
    string value;

    do {
        cout << "\n========== DICTIONARY ==========\n";
        cout << "1. Insert Word\n";
        cout << "2. Delete Word\n";
        cout << "3. Search Word\n";
        cout << "4. Display Dictionary\n";
        cout << "5. Mirror Dictionary\n";
        cout << "6. Create Copy of Dictionary\n";
        cout << "7. Display Level Wise\n";
        cout << "8. Check Path Sum\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key: ";
            cin >> key;

            cout << "Enter value: ";
            cin >> value;

            dict.insertWord(key, value);
            break;
        
        case 2: 
            cout << "Enter key to delete: ";
            cin >> key;

            dict.deleteWord(key);
            break;
        
        case 3:
            cout << "Enter key to search: ";
            cin >> key;

            dict.searchWord(key);
            break;

        case 4:
            dict.display();
            break;

        case 5:
            dict.mirrorDictionary();
            break;

        case 6: {
            Dictionary copy = dict.createCopy();

            cout << "\nCopied Dictionary:\n";
            copy.display();
            break;
        }

        case 7:
            dict.displayLevelWise();
            break;

        case 8:
            cout << "Enter the sum to check: ";
            int sum;
            cin >> sum;
            dict.pathSum(sum);
            break;

        case 9:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 9);

    return 0;
}