#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

void insertEnd(int x) {
    Node* t = new Node;
    t->data = x;
    t->next = NULL;
    if(head == NULL) { head = t; return; }
    Node* p = head;
    while(p->next) p = p->next;
    p->next = t;
}

int main() {

    int n, x, key;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        insertEnd(x);
    }

    cin >> key;

    int count = 0;
    Node* p = head;
    while(p) {
        if(p->data == key) count++;
        p = p->next;
    }
    
    cout << count << " ";

    while(head && head->data == key) {
        Node* t = head;
        head = head->next;
        delete t;
    }

    p = head;
    while(p && p->next) {
        if(p->next->data == key) {
            Node* t = p->next;
            p->next = t->next;
            delete t;
        } else p = p->next;
    }

    p = head;
    while(p) {
        cout << p->data << " ";
        p = p->next;
    }
}