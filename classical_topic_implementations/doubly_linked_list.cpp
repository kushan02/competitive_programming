#include<iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
} *HEAD = NULL;

Node *create_node(int val) {
    Node *node = new Node;
    node->data = val;
    node->next = NULL;
    node->prev = NULL;

    return node;
}


void insert_node(int val) {

    if (HEAD == NULL) {
        HEAD = create_node(val);
        return;
    }

    Node *itr = NULL;
    for (itr = HEAD; itr->next != NULL; itr = itr->next);
    itr->next = create_node(val);
    (itr->next)->prev = itr;
}

void delete_node(int val) {

    Node *itr = NULL;

    for (itr = HEAD; itr != NULL; itr = itr->next) {

        if (itr->data == val) {

            if (itr == HEAD) {
                Node *tmp = itr;
                HEAD = itr->next;
                delete tmp;
                return;
            } else {
                (itr->prev)->next = itr->next;

                if (itr->next != NULL)
                    (itr->next)->prev = itr->prev;

                delete itr;
                return;
            }
        }

    }
}


void print_list() {

    for (Node *itr = HEAD; itr != NULL; itr = itr->next) {
        cout << itr->data << ", ";
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