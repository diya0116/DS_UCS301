#include <iostream>
#include <queue>
using namespace std;

queue<int> q1, q2;

void push(int x) {
    q2.push(x);
    while(!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1, q2);
}
int pop() {
    int x = q1.front();
    q1.pop();
    return x;
}

int main() {
    push(5);
    push(9);
    push(3);
    cout << pop() << " ";
    cout << pop() << " ";
}










