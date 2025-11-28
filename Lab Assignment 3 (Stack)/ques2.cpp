#include <iostream>
#include <cstring>
using namespace std;

char st[100];
int top2 = -1;

void push2(char c) { st[++top2] = c; }
char pop2() { return st[top2--]; }

int main() {
    char s[100];
    cin >> s;

    int len = strlen(s);
    for(int i = 0; i < len; i++) push2(s[i]);
    for(int i = 0; i < len; i++) cout << pop2();
}