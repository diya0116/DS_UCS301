#include <iostream>
using namespace std;

int q[100], front = -1, rear = -1, n;

void enqueue(int x) {
    if(rear == n-1) {
        cout << "Full\n";
        return;
    }
    if(front == -1) front = 0;
    q[++rear] = x;
}
void dequeue() {
    if(front == -1 || front > rear) {
        cout << "Empty\n";
        return;
    }
    cout << "Deleted: " << q[front] << endl;
    front++;
}
void isEmpty() {
    if(front == -1 || front > rear) cout << "Empty\n";
    else cout << "Not Empty\n";
}
void isFull() {
    if(rear == n-1) cout << "Full\n";
    else cout << "Not Full\n";
}
void display() {
    if(front == -1 || front > rear) {
        cout << "Empty\n"; return;
    }
    for(int i = front; i <= rear; i++) cout << q[i] << " ";
    cout << endl;
}
void peek() {
    if(front == -1 || front > rear) cout << "Empty\n";
    else cout << q[front] << endl;
}

int main() {
    cout << "Enter size: ";
    cin >> n;

    int ch, x;
    while(true) {
        cout << "1 Enqueue\n2 Dequeue\n3 isEmpty\n4 isFull\n5 Display\n6 Peek\n7 Exit\n";
        cin >> ch;
        if(ch == 1) { cin >> x; enqueue(x); }
        else if(ch == 2) dequeue();
        else if(ch == 3) isEmpty();
        else if(ch == 4) isFull();
        else if(ch == 5) display();
        else if(ch == 6) peek();
        else break;
    }
}