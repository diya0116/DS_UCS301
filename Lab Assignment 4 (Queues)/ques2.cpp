#include <iostream>
using namespace std;

int cq[100], front2 = -1, rear2 = -1, n2;

void enqueue2(int x) {
    if((front2 == 0 && rear2 == n2-1) || (rear2+1 == front2)) {
        cout << "Full\n";
        return;
    }
    if(front2 == -1) front2 = 0;
    rear2 = (rear2 + 1) % n2;
    cq[rear2] = x;
}
void dequeue2() {
    if(front2 == -1) {
        cout << "Empty\n";
        return;
    }
    cout << "Deleted: " << cq[front2] << endl;
    if(front2 == rear2) front2 = rear2 = -1;
    else front2 = (front2 + 1) % n2;
}
void isEmpty2() {
    if(front2 == -1) cout << "Empty\n";
    else cout << "Not Empty\n";
}
void isFull2() {
    if((front2 == 0 && rear2 == n2-1) || (rear2+1 == front2)) cout << "Full\n";
    else cout << "Not Full\n";
}
void display2() {
    if(front2 == -1) {
        cout << "Empty\n"; return;
    }
    int i = front2;
    while(true) {
        cout << cq[i] << " ";
        if(i == rear2) break;
        i = (i + 1) % n2;
    }
    cout << endl;
}
void peek2() {
    if(front2 == -1) cout << "Empty\n";
    else cout << cq[front2] << endl;
}

int main() {
    cout << "Enter size: ";
    cin >> n2;

    int ch, x;
    while(true) {
        cout << "1 Enqueue\n2 Dequeue\n3 isEmpty\n4 isFull\n5 Display\n6 Peek\n7 Exit\n";
        cin >> ch;
        if(ch == 1) { cin >> x; enqueue2(x); }
        else if(ch == 2) dequeue2();
        else if(ch == 3) isEmpty2();
        else if(ch == 4) isFull2();
        else if(ch == 5) display2();
        else if(ch == 6) peek2();
        else break;
    }
}
