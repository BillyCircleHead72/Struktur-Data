#include <iostream>
using namespace std;

const int maxstack = 100;
typedef char infotype;

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
    if (!isFull(S)) {
        S.top = S.top + 1;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    infotype x = '\0';
    if (!isEmpty(S)) {
        x = S.info[S.top];
        S.top = S.top - 1;
    }
    return x;
}

int main() {
    Stack S;
    createStack(S);

    char word[maxstack];
    cout << "Enter a word: ";
    cin >> word;

    // Menghitung panjang string secara manual
    int length = 0;
    while (word[length] != '\0') {
        length++;
    }

    cout << "Original word: ";
    for (int i = 0; i < length; i++) {
        cout << word[i];
    }
    cout << "\n";

    // Push Sequence: Push setiap karakter dari kiri ke kanan (forward loop)
    for (int i = 0; i < length; i++) {
        push(S, word[i]);
    }
    
    // Pop Sequence: Pop semua karakter untuk membalikkan urutan secara LIFO
    cout << "Reversed word: ";
    while (!isEmpty(S)) {
        cout << pop(S);
    }
    cout << "\n";

    return 0;
}