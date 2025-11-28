#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBeg(int x) {
    Node* t = new Node;
    t->data = x;
    t->next = head;
    head = t;
}

void insertEnd(int x) {
    Node* t = new Node;
    t->data = x;
    t->next = NULL;

    if(head == NULL) { 
        head = t; 
        return; 
    }

    Node* p = head;
    while(p->next) p = p->next;
    p->next = t;
}

void insertBefore(int val, int x) {

    if(head == NULL) return;

    if(head->data == val) { 
        insertBeg(x); 
        return; 
    }
    Node* p = head;
    while(p->next && p->next->data != val) p = p->next;

    if(p->next) {
        Node* t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

void insertAfter(int val, int x) {

    Node* p = head;
    while(p && p->data != val) p = p->next;
    if(p) {
        Node* t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

void deleteBeg() {
    if(head == NULL) return;
    Node* t = head;
    head = head->next;
    delete t;
}

void deleteEnd() {
    if(head == NULL) return;
    if(head->next == NULL) { 
        delete head; 
        head = NULL; 
        return; 
    }
    Node* p = head;
    while(p->next->next) p = p->next;
    delete p->next;
    p->next = NULL;
}

void deleteVal(int val) {

    if(head == NULL) return;
    if(head->data == val) { 
        deleteBeg(); 
        return; 
    }
    Node* p = head;
    while(p->next && p->next->data != val) p = p->next;
    if(p->next) {
        Node* t = p->next;
        p->next = t->next;
        delete t;
    }
}

void searchNode(int val) {
    int pos = 1;
    Node* p = head;
    while(p) {
        if(p->data == val) { 
            cout << pos << endl; 
            return; 
        }
        pos++;
        p = p->next;
    }
    cout << -1 << endl;
}

void display() {
    Node* p = head;
    while(p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int ch, x, val;
    while(true) {
        cin >> ch;
        if(ch == 1) { cin >> x; insertBeg(x); }
        else if(ch == 2) { cin >> x; insertEnd(x); }
        else if(ch == 3) { cin >> val >> x; insertBefore(val,x); }
        else if(ch == 4) { cin >> val >> x; insertAfter(val,x); }
        else if(ch == 5) deleteBeg();
        else if(ch == 6) deleteEnd();
        else if(ch == 7) { cin >> x; deleteVal(x); }
        else if(ch == 8) { cin >> x; searchNode(x); }
        else if(ch == 9) display();
        else break;
    }
}