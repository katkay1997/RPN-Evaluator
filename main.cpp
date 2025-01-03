#include <iostream>
#include <cstdlib>
using namespace std;

class stack {
private:
    static const int STACK_SIZE = 128;
    int _stack[STACK_SIZE];
    int _top;

public:
    stack();
    void push(int);
    int pop();
    int top();
    bool is_empty();
};

// Constructor
stack::stack() : _top(-1) {}

void stack::push(int value) {
    if (_top >= STACK_SIZE - 1) {
        cerr << "Stack overflow" << endl;
        return;
    }
    _stack[++_top] = value;
}

int stack::pop() {
    if (is_empty()) {
        cerr << "Stack underflow" << endl;
        return -1; // Return an invalid value
    }
    return _stack[_top--];
}

int stack::top() {
    if (is_empty()) {
        cerr << "Stack is empty" << endl;
        return -1; // Return an invalid value
    }
    return _stack[_top];
}

bool stack::is_empty() {
    return _top == -1;
}

int main() {
    stack s;
    int num;

    cout << "Enter a number (or any non-number to exit): ";
    while (cin >> num) {
        s.push(num);
        cout << "Top element: " << s.top() << endl;
        cout << "Enter another number  (type a non-number to exit): ";
    }

    // Display the final stack contents
    cout << "\n Final stack contents (from top to bottom):" << endl;
    while (!s.is_empty()) {
        cout << s.pop() << " ";
    }
    cout << endl;

    cout << "Done." << endl;
    return 0;
}