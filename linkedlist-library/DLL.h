class DLLNode {
public:
    int data;
    DLLNode* next;
    DLLNode* prev;

    DLLNode(int val);
};

class DLL {
private:
    DLLNode* head;
    DLLNode* tail;

public:
    DLL();
    ~DLL();

    void push_front(int val);
    void push_back(int val);
    void insert(int val, int key);
    void pop_front();
    void pop_back();
    void pop_specific(int val);
    void displayDLL();
};
