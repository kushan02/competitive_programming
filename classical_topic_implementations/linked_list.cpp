#include<iostream>

using namespace std;

// Search by value
// Delete by value
// Print all values
// Insert a new value

// Single Linked List
// Circular LinkedList
// Doubly LinkedList


// Single Linked List
struct Node {
    Node *next;
    int value;
};

// In circular Linked List, we just make the last element point to HEAD instead of NULL

// In doubly linked List we have pointers to both the adjacent values of linkedlist

Node *HEAD = NULL;

Node *create_node(int val) {
    Node *node = new Node;
    node->next = NULL;
    node->value = val;
    return node;
}

void insert_node(int val) {

    if (HEAD == NULL) { // The linked List is empty, intialize it
        HEAD = create_node(val);
    } else { // The head already exists, traverse to the last element and insert there

        Node *itr = NULL;
        for (itr = HEAD; itr->next != NULL; itr = itr->next); // traverse to the last element

        itr->next = create_node(val);
    }
}

Node *get_searched_node(int val) {

    Node *itr = NULL;
    for (itr = HEAD; itr != NULL; itr = itr->next) {
        if (itr->value == val)
            return itr;
    }

    return NULL;
}

bool search(int val) {
    if (get_searched_node(val) == NULL)
        return false;
    return true;
}

void delete_node(int val) {

    Node *itr = NULL, *prev_itr;

    for (itr = prev_itr = HEAD; itr != NULL; prev_itr = itr, itr = itr->next) {

        if (itr->value == val) {
            if (itr == HEAD) {
                Node *tmp = itr;
                HEAD = itr->next;
                delete tmp;
                return;
            } else {
                Node *tmp = itr;
                prev_itr->next = itr->next;
                delete tmp;
                return;
            }
        }

    }
}

void print_list() {

    for (Node *itr = HEAD; itr != NULL; itr = itr->next) {
        cout << itr->value << ", ";
    }
    cout << endl;
}


int main() {

    insert_node(1);
    insert_node(2);
    insert_node(3);
    insert_node(4);
    insert_node(5);
    print_list();
    // cout<<search(7)<<endl<<search(3)<<endl<<search(5)<<endl<<search(1)<<endl;
    delete_node(1);
    print_list();
    delete_node(3);
    print_list();
    delete_node(5);
    print_list();
    insert_node(3281);
    print_list();


    return 0;
}