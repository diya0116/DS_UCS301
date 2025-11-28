#include <iostream>
using namespace std;

int main() {
    char str[50], out[50];
    cout << "Enter string: ";
    cin >> str;

    int j=0;
    for(int i=0; str[i]!='\0'; i++) {
        if(!(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'
          ||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'))
            out[j++] = str[i];
    }
    out[j] = '\0';

    cout << "After removing vowels: " << out;
    return 0;
}
