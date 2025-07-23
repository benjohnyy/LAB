#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
    return rear == SIZE - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full, cannot enqueue %d\n", value);
    } else {
        if (front == -1) { 
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("%d enqueued successfully\n", value);
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty, cannot dequeue\n");
        return -1;
    } else {
        int dequeuedValue = queue[front];
        front++;
        if (front > rear) {  
            front = rear = -1;
        }
        return dequeuedValue;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    printf("Dequeued: %d\n", dequeue());
    display();

    enqueue(40);
    enqueue(50);
    display();

    return 0;
}
