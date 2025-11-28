// Implement following functions for Binary Search Trees 
// (a) Search a given item (Recursive & Non-Recursive) 
// (b) Maximum element of the BST 
// (c) Minimum element of the BST 
// (d) In-order successor of a given node the BST 
// (e) In-order predecessor of a given node the BST

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int val) {
    if (root == NULL) {
        Node* temp = new Node();
        temp->data = val;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

// Recursive Search
Node* searchRec(Node* root, int key) {
    if (root == NULL || root->data == key) return root;
    if (key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

// Non-Recursive Search
Node* searchNonRec(Node* root, int key) {
    while (root != NULL) {
        if (root->data == key) return root;
        else if (key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

// Find Min
Node* findMin(Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Find Max
Node* findMax(Node* root) {
    while (root && root->right != NULL)
        root = root->right;
    return root;
}

// Inorder Successor
Node* inorderSuccessor(Node* root, int key) {
    Node* curr = searchRec(root, key);
    if (!curr) return NULL;

    if (curr->right)
        return findMin(curr->right);

    Node* succ = NULL;
    Node* ancestor = root;
    while (ancestor != curr) {
        if (curr->data < ancestor->data) {
            succ = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }
    return succ;
}

// Inorder Predecessor
Node* inorderPredecessor(Node* root, int key) {
    Node* curr = searchRec(root, key);
    if (!curr) return NULL;

    if (curr->left)
        return findMax(curr->left);

    Node* pred = NULL;
    Node* ancestor = root;
    while (ancestor != curr) {
        if (curr->data > ancestor->data) {
            pred = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }
    return pred;
}