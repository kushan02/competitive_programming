#include<iostream>

using namespace std;

class BST {

private:
    struct Node {
        int key;
        Node *left_child;
        Node *right_child;
    } *root = NULL;

    Node *create_node(int val) {
        Node *node = new Node;
        node->left_child = NULL;
        node->right_child = NULL;
        node->key = val;
        return node;
    }

    bool search_node(Node *node, int val) {
        if (node == NULL)
            return false;

        if (node->key == val)
            return true;
        if (val > node->key)
            return search_node(node->right_child, val);
        else
            return search_node(node->left_child, val);
    }

    void insert_node(Node *node, int val) {
        if (node == NULL)
            return;

        if (val == node->key)
            return; // duplicate values are not allowed
        if (val > node->key) {
            if (node->right_child == NULL)
                node->right_child = create_node(val);
            else
                insert_node(node->right_child, val);
        } else {
            if (node->left_child == NULL)
                node->left_child = create_node(val);
            else
                insert_node(node->left_child, val);
        }
    }

    void inOrder(Node *node) {
        if (node == NULL)
            return;

        inOrder(node->left_child);
        cout << node->key << "\n";
        inOrder(node->right_child);
    }

    void preOrder(Node *node) {
        if (node == NULL)
            return;

        cout << node->key << "\n";
        preOrder(node->left_child);
        preOrder(node->right_child);
    }

    void postOrder(Node *node) {
        if (node == NULL)
            return;

        postOrder(node->left_child);
        postOrder(node->right_child);
        cout << node->key << "\n";
    }

public:


    bool search_node(int val) {
        return search_node(root, val);
    }


    void insert_node(int val) {

        if (root == NULL) {
            root = create_node(val);
            return;
        }

        insert_node(root, val);
    }

    void inOrder() {
        inOrder(root);
    }

    void preOrder() {
        preOrder(root);
    }

    void postOrder() {
        postOrder(root);
    }


};

int main() {

    BST bst;
    bst.insert_node(50);
    bst.insert_node(30);
    bst.insert_node(20);
    bst.insert_node(40);
    bst.insert_node(70);
    bst.insert_node(60);
    bst.insert_node(80);

    bst.inOrder();

    return 0;
}