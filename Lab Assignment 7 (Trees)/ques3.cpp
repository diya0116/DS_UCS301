// Write a program for binary search tree (BST) having functions for the following operations: 
// (a) Insert an element (no duplicates are allowed), 
// (b) Delete an existing element, 
// (c) Maximum depth of BST 
// (d) Minimum depth of

#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* t = new Node();
    t->data = val;
    t->left = t->right = NULL;
    return t;
}

Node* insert(Node* root, int val) {
    if (root == NULL) return newNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        if (root->left == NULL) {
            Node* t = root->right;
            delete root;
            return t;
        }
        else if (root->right == NULL) {
            Node* t = root->left;
            delete root;
            return t;
        }
        Node* minRight = findMin(root->right);
        root->data = minRight->data;
        root->right = deleteNode(root->right, minRight->data);
    }
    return root;
}

int maxDepth(Node* root) {
    if (root == NULL) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root) {
    if (root == NULL) return 0;
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main() {
    Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);

    cout << "Max Depth: " << maxDepth(root) << endl;
    cout << "Min Depth: " << minDepth(root) << endl;

    root = deleteNode(root, 30);
    cout << "Deleted 30" << endl;

    return 0;
}
