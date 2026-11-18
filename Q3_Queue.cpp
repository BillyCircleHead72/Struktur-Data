#include <iostream>
using namespace std;

const int maxqueue = 5;
typedef int infotype;

struct Queue {
    infotype info[maxqueue];
    int front;
    int rear;
};

void createQueue(Queue &Q) {
    Q.front = -1;
    Q.rear = -1;
}

bool isEmpty(Queue Q) {
    return Q.front == -1;
}

bool isFull(Queue Q) {
    return Q.rear == maxqueue - 1;
}

void enqueue(Queue &Q, infotype x) {
    if (isFull(Q)) {
        cout << "Queue Overflow! Cannot insert " << x << ".\n";
    } else {
        if (isEmpty(Q)) {
            Q.front = 0;
        }
        Q.rear = Q.rear + 1;
        Q.info[Q.rear] = x;
        cout << x << " inserted successfully.\n";
    }
}

void dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue Underflow! Queue is empty.\n";
    } else {
        infotype x = Q.info[Q.front];
        if (Q.front == Q.rear) {
            Q.front = -1;
            Q.rear = -1;
        } else {
            Q.front = Q.front + 1;
        }
        cout << x << " removed successfully.\n";
    }
}

void front(Queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Front element: " << Q.info[Q.front] << "\n";
    }
}

void display(Queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue: (empty)\n";
    } else {
        cout << "Queue: ";
        for (int i = Q.front; i <= Q.rear; i++) {
            cout << Q.info[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    Queue Q;
    createQueue(Q);
    int choice;
    infotype val;

    while (true) {
        cout << "\n===== QUEUE MENU =====\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Front\n4. Display\n5. Exit\n";
        cout << "Choose operation: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            enqueue(Q, val);
        }
        else if (choice == 2) {
            dequeue(Q);
        }
        else if (choice == 3) {
            front(Q);
        }
        else if (choice == 4) {
            display(Q);
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