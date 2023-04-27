#ifndef QUEUE_H
#define QUEUE_H

class Queue {
private:
    int* arr; // dynamic array to store the elements
    int front, rear; // indices of the front and rear elements
    int capacity; // maximum number of elements the queue can hold
    int count; // current number of elements in the queue
    
public:
    Queue(int size);
    ~Queue();

    // Inserts a new element at the rear
    void enqueue(int item);

    // Removes the front element and returns it
    int dequeue();

    // Returns the front element without removing it
    int peek();

    // Sees if the queue is empty
    bool isEmpty();

    // Returns the total number of elements 
    int size();

    // Sees if the queue is full
    bool isFull();
};

#endif