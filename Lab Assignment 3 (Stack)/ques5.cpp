#include <iostream>
using namespace std;

int st[100], top5 = -1;

void push5(int x) { st[++top5] = x; }
int pop5() { return st[top5--]; }

int main() {
    char exp[100];
    cin >> exp;

    for(int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        if(c>='0' && c<='9') push5(c - '0');
        else {
            int b = pop5();
            int a = pop5();
            int r;

            if(c=='+') r = a + b;
            else if(c=='-') r = a - b;
            else if(c=='*') r = a * b;
            else if(c=='/') r = a / b;

            push5(r);
        }
    }

    cout << st[top5];
}