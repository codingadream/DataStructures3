#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(int size) {
    arr = new int[size];
    front = 0;
    rear = -1;
    capacity = size;
    count = 0;
}

Queue::~Queue() {
    delete[] arr;
}

// Inserts a new element at the rear
void Queue::enqueue(int item) {
    if (isFull()) {
        cout << "Queue is full\n";
        return;
    }
    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

// Removes the front element and returns it
int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return -1;
    }
    int item = arr[front];
    front = (front + 1) % capacity;
    count--;
    return item;
}

// Returns the front element without removing it
int Queue::peek() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return -1;
    }
    return arr[front];
}


bool Queue::isEmpty() {
    return count == 0;
}


int Queue::size() {
    return count;
}

// Sees if the queue is full
bool Queue::isFull() {
    return count == capacity;
}