#include <iostream>
#include <cstring>
using namespace std;

char st[100];
int top3 = -1;

void push3(char c) { st[++top3] = c; }
char pop3() { return st[top3--]; }
char topv() { return st[top3]; }

int main() {
    char exp[100];
    cin >> exp;
    int len = strlen(exp);

    for(int i = 0; i < len; i++) {
        char c = exp[i];
        if(c=='(' || c=='{' || c=='[') push3(c);
        else if(c==')' || c=='}' || c==']') {
            if(top3 == -1) {
                cout << "Not Balanced";
                return 0;
            }
            char t = pop3();
            if((c==')' && t!='(') || (c=='}' && t!='{') || (c==']' && t!='[')) {
                cout << "Not Balanced";
                return 0;
            }
        }
    }

    if(top3 == -1) cout << "Balanced";
    else cout << "Not Balanced";
}