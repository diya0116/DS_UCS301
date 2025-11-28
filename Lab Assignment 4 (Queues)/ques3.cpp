#include <iostream>
using namespace std;

int main() {
    int q[100], n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> q[i];

    int half = n/2;
    int a[100], b[100], k = 0;

    for(int i = 0; i < half; i++) a[i] = q[i];
    for(int i = half; i < n; i++) b[i-half] = q[i];

    for(int i = 0; i < half; i++) {
        cout << a[i] << " " << b[i] << " ";
    }
}