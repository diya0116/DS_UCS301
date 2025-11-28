// 4. Write a program to determine whether a given binary tree is a BST or not.

#include <iostream>
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

bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (root == NULL) return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT32_MIN, INT32_MAX);
}

int main() {
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(20);
    root->left->left = newNode(1);

    if (isBST(root))
        cout << "Tree is a BST";
    else
        cout << "Tree is NOT a BST";

    return 0;
}