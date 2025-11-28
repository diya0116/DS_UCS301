#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

void push(int x) {
    q.push(x);
    int s = q.size();
    for(int i = 1; i < s; i++) {
        q.push(q.front());
        q.pop();
    }
}
int pop() {
    int x = q.front();
    q.pop();
    return x;
}

int main() {
    push(4);
    push(8);
    push(1);
    cout << pop() << " ";
    cout << pop() << " ";
}