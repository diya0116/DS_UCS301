#include <iostream>
using namespace std;

int stackArr[100], top = -1, n;

void push(int x) {
    if(top == n-1) {
        cout << "Stack Full\n";
        return;
    }
    top++;
    stackArr[top] = x;
}

void pop() {
    if(top == -1) {
        cout << "Stack Empty\n";
        return;
    }
    cout << "Popped: " << stackArr[top] << endl;
    top--;
}

void isEmpty() {
    if(top == -1) cout << "Stack is Empty\n";
    else cout << "Not Empty\n";
}

void isFull() {
    if(top == n-1) cout << "Stack is Full\n";
    else cout << "Not Full\n";
}

void display() {
    if(top == -1) {
        cout << "Stack Empty\n";
        return;
    }
    for(int i = top; i >= 0; i--) cout << stackArr[i] << " ";
    cout << endl;
}

void peek() {
    if(top == -1) cout << "Stack Empty\n";
    else cout << "Top: " << stackArr[top] << endl;
}

int main() {
    cout << "Enter size: ";
    cin >> n;

    int ch, x;
    while(true) {
        cout << "\n1 Push\n2 Pop\n3 isEmpty\n4 isFull\n5 Display\n6 Peek\n7 Exit\n";
        cin >> ch;
        if(ch == 1) { cin >> x; push(x); }
        else if(ch == 2) pop();
        else if(ch == 3) isEmpty();
        else if(ch == 4) isFull();
        else if(ch == 5) display();
        else if(ch == 6) peek();
        else break;
    }
}