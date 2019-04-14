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
            cout << "QUEUE IS FULL" << endl;
            return;
        }

        rear = (rear + 1) % MAX_SIZE;
        ar[rear] = val;
        size++;

    }

    int get_front() {
        if (isEmpty()) {
            cout << "QUEUE IS EMPTY" << endl;
            return -1;
        }

        return ar[front];
    }

    int get_rear() {
        if (isEmpty()) {
            cout << "QUEUE IS EMPTY" << endl;
            return -1;
        }

        return ar[rear];
    }

    int dequeue() {

        if (isEmpty()) {
            cout << "QUEUE IS EMPTY" << endl;
            return -1;
        }

        int front_var = get_front();

        front = (front + 1) % MAX_SIZE;

        --size;

        return front_var;
    }

    void print() {
        for (int i = 0; i < get_size(); ++i) {
            cout << ar[(front + i) % MAX_SIZE] << " ";
        }

        cout << "\n";
    }

};

int main() {

    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);
    q.enqueue(90);
    q.enqueue(100);
    q.enqueue(110);

    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.enqueue(200);
    q.enqueue(210);
    q.enqueue(300);
    q.enqueue(310);

    q.print();

    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.print();


    return 0;
}