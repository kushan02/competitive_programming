#include<iostream>

using namespace std;

class Stack {

private:
    int *ar;
    const int MAX_SIZE = 10;
    int top = 0;

public:

    Stack() {
        ar = new int[MAX_SIZE];
    }

    int size() {
        return top;
    }

    void push(int val) {
        if (size() >= MAX_SIZE) {
            cout << "STACK IS FULL" << endl;
        } else {
            ar[top++] = val;
        }
    }

    int peek() {
        if (size() > 0) {
            return ar[top - 1];
        } else
            return -1;
    }

    int pop() {
        if (size() > 0) {
            int val = peek();
            top--;
            return val;
        } else {
            cout << "STACK IS EMPTY!" << endl;
        }

    }

    void print() {
        for (int i = 0; i < size(); ++i)
            cout << ar[i] << " ";
        cout << endl;
    }
};

int main() {

    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack.print();

    cout << stack.peek() << endl;

    stack.pop();
    stack.print();
    stack.push(4);
    stack.print();

    return 0;
}