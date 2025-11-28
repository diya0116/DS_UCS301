#include <iostream>
#include <cstring>
using namespace std;

char st[100];
int top4 = -1;

void push4(char c) { st[++top4] = c; }
char pop4() { return st[top4--]; }
char topv4() { return st[top4]; }
int prec(char c) {
    if(c=='^') return 3;
    if(c=='*' || c=='/') return 2;
    if(c=='+' || c=='-') return 1;
    return 0;
}

int main() {
    char in[100], post[100];
    cin >> in;

    int j = 0;
    for(int i = 0; in[i] != '\0'; i++) {
        char c = in[i];

        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')) post[j++] = c;

        else if(c=='(') push4(c);

        else if(c==')') {
            while(top4 != -1 && topv4()!='(') post[j++] = pop4();
            pop4();
        }
        else {
            while(top4 != -1 && prec(topv4()) >= prec(c)) post[j++] = pop4();
            push4(c);
        }
    }

    while(top4 != -1) post[j++] = pop4();
    post[j] = '\0';

    cout << post;
}