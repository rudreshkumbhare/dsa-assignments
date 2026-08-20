#include <iostream>
#include <string>

using namespace std;

template <class T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T val) {
        data = val;
        next = NULL;
    }
};

template <class T>
class Stack {
    Node<T>* top;

public:
    Stack() {
        top = NULL;
    }

    void push(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = top;
        top = newNode;
    }

    T pop() {
        if (top == NULL) return 0;
        Node<T>* temp = top;
        T poppedValue = temp->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    T peek() {
        if (top == NULL) return 0;
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string getPostfix(string e) {
    Stack<char> s;
    string result = "";

    for (int i = 0; i < e.length(); i++) {
        char c = e[i];

        if (isalnum(c)) {
            result += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                result += s.peek();
                s.pop();
            }
            if (!s.isEmpty()) s.pop();
        } else {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                result += s.peek();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty()) {
        result += s.peek();
        s.pop();
    }
    return result;
}

string getPrefix(string e) {
    Stack<char> s;
    string result = "";

    for (int i = e.length() - 1; i >= 0; i--) {
        char c = e[i];

        if (isalnum(c)) {
            result = c + result;
        } else if (c == ')') {
            s.push(c);
        } else if (c == '(') {
            while (!s.isEmpty() && s.peek() != ')') {
                result = s.peek() + result;
                s.pop();
            }
            if (!s.isEmpty()) s.pop();
        } else {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                result = s.peek() + result;
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty()) {
        result = s.peek() + result;
        s.pop();
    }
    return result;
}

int evaluatePostfix(string e) {
    Stack<int> s;

    for (int i = 0; i < e.length(); i++) {
        char c = e[i];

        if (isalnum(c)) {
            s.push(c - '0');
        } else {
            int op1 = s.pop();
            int op2 = s.pop();
            int result = 0;

            switch (c) {
                case '+': result = op2 + op1; break;
                case '-': result = op2 - op1; break;
                case '*': result = op2 * op1; break;
                case '/': result = op2 / op1; break;
            }
            s.push(result);
        }
    }
    return s.peek();
}

int evaluatePrefix(string e) {
    Stack<int> s;

    for (int i = e.length() - 1; i >= 0; i--) {
        char c = e[i];

        if (isalnum(c)) {
            s.push(c - '0');
        } else {
            int op1 = s.pop();
            int op2 = s.pop();
            int result = 0;

            switch (c) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }
            s.push(result);
        }
    }
    return s.peek();
}

int main() {
    string infix;
    cout << "Enter infix expression (e.g., (5+3)*(8-2)): ";
    cin >> infix;

    int open = 0, close = 0;
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') open++;
        if (infix[i] == ')') close++;
    }
    if (open != close) {
        cout << "Invalid expression: Mismatched parentheses." << endl;
        return 1;
    }

    string postfix = getPostfix(infix);
    string prefix = getPrefix(infix);
    int evaluationPrefix = evaluatePrefix(prefix);
    int evaluationPostfix = evaluatePostfix(postfix);

    cout << "Infix Input:           " << infix << endl;
    cout << "Postfix:               " << postfix << endl;
    cout << "Prefix:                " << prefix << endl;
    cout << "Evaluated (Prefix):    " << evaluationPrefix << endl;
    cout << "Evaluated (Postfix):   " << evaluationPostfix << endl;

    return 0;
}