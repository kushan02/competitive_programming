#include<iostream>

using namespace std;

// enqueue (used to insert data from one end)
// dequeue (used to delete data from one end)
// peek - returns data in the front of the queue
// front - get the front item from the queue
// rear - get the rear item from the queue
// isFull
// isEmpty

class Queue {

private:
    int front = 0;
    int rear = -1;
    int size = 0;
    const int MAX_SIZE = 10;
    int *ar;

public:
    Queue() {
        ar = new int[MAX_SIZE];
    }

    int get_size() {
        return size;
    }

    bool isFull() {
        return size == MAX_SIZE;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "QUEUE IS FULL";
            return;
        }

        ar[++rear] = val;
        size++;

    }

    int get_front() {
        if (isEmpty()) {
            cout << "QUEUE IS EMPTY";
            return -1;
        }

        return ar[front];
    }

    int get_rear() {
        if (isEmpty()) {
            cout << "QUEUE IS EMPTY";
            return -1;
        }

        return ar[rear];
    }

    int dequeue() {

        if (isEmpty()) {
            cout << "QUEUE IS EMPTY";
            return -1;
        }

        int front_var = get_front();

        // shift the queue back to remove the front
        for (int i = 1; i <= rear; ++i) {
            ar[i - 1] = ar[i];
        }
        --rear;
        --size;

        return front_var;
    }

    void print() {
        for (int i = 0; i < size; ++i)
            cout << ar[i] << ", ";
        cout << endl;
    }
    
};

int main() {

    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.print();

    q.dequeue();
    q.print();
    q.enqueue(50);
    q.print();
    q.dequeue();
    q.print();


    return 0;
}