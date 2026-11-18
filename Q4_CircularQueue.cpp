#include <iostream>
using namespace std;

const int maxqueue = 5;
typedef int infotype;

struct CircularQueue {
    infotype info[maxqueue];
    int front; // untuk delete
    int rear; // untuk insert
    int count;
};

void createQueue(CircularQueue &Q) {
    Q.front = 0;
    Q.rear = -1;
    Q.count = 0;
}

bool isEmpty(CircularQueue Q) {
    return Q.count == 0;
}

bool isFull(CircularQueue Q) {
    return Q.count == maxqueue;
}

// "% maxqueue" on enqueue, dequeue, and display insures that the index doesn't go above the max (maxqueue-1) and continues from the start, if possible

void enqueue(CircularQueue &Q, infotype x) {
    if (isFull(Q)) {
        cout << "Queue Overflow! Cannot enqueue " << x << ".\n";
    } else {
        Q.rear = (Q.rear + 1) % maxqueue;
        Q.info[Q.rear] = x;
        Q.count = Q.count + 1;
    }
}

void dequeue(CircularQueue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue Underflow! Queue is empty.\n";
    } else {
        Q.front = (Q.front + 1) % maxqueue; 
        Q.count = Q.count - 1;
    }
}

void display(CircularQueue Q) {
    if (isEmpty(Q)) {
        cout << "Queue: (empty)\n";
    } else {
        cout << "Queue: ";
        for (int i = 0; i < Q.count; i++) {
            int idx = (Q.front + i) % maxqueue;
            cout << Q.info[idx] << " ";
        }
        cout << "\n";
    }
}

int main() {
    CircularQueue Q;
    createQueue(Q);

    // 1-5. Enqueue: 10, 20, 30, 40, 50
    enqueue(Q, 10);
    enqueue(Q, 20);
    enqueue(Q, 30);
    enqueue(Q, 40);
    enqueue(Q, 50);
    display(Q);

    // 6-7. Dequeue twice (removes 10, 20)
    dequeue(Q);
    dequeue(Q);
    display(Q);

    // 8-9. Enqueue: 60, 70 (wraps around using % 5)
    enqueue(Q, 60);
    enqueue(Q, 70);

    // 10. Display queue (Output: Queue: 30 40 50 60 70)
    display(Q);

    return 0;
}