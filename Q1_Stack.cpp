#include <iostream>
using namespace std;

const int maxstack = 5;
typedef int infotype;

struct Stack {
    infotype info[maxstack];
    int top;
};

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == maxstack - 1;
}

void push(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack Overflow! Cannot push " << x << ".\n"; // ketika ingin menambahkan tetapi sudah full
    } else {
        S.top = S.top + 1;
        S.info[S.top] = x;
        cout << x << " inserted successfully.\n";
    }
}

void pop(Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack Underflow! Stack is empty.\n";  // ketika ingin mengurangi tetapi sudah kosong
    } else {
        infotype x = S.info[S.top];
        S.top = S.top - 1;
        cout << x << " removed successfully.\n";
    }
}

void peek(Stack S) { // output the top element
    if (isEmpty(S)) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Top element: " << S.info[S.top] << "\n";
    }
}

void display(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Stack elements: ";
        while (S.top >= 0) {  // display by using top (top to bottom)
            cout << S.info[S.top] << " ";
            S.top--;
        }
        cout << "\n";
    }
}

int main() {
    Stack S;
    createStack(S);
    int choice;
    infotype val;

    while (true) {
        cout << "\n===== STACK MENU =====\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Choose operation: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            push(S, val);
        }
        else if (choice == 2) {
            pop(S);
        }
        else if (choice == 3) {
            peek(S);
        }
        else if (choice == 4) {
            display(S);
        }
        else if (choice == 5) {
            cout << "Exiting program.\n";
            break; // Keluar dari perulangan while
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}