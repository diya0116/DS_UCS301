#include <iostream>
using namespace std;

int main() {
    char str[50];
    cout << "Enter string: ";
    cin >> str;

    int end = 0;
    while(str[end] != '\0') end++;

    cout << "Reversed string: ";
    for(int i=end-1; i>=0; i--)
        cout << str[i];

    return 0;
}