#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,3,4,6,7,8};
    int n = 8;

    int sum1 = 0;
    for(int i=0; i<n-1; i++)
        sum1 += arr[i];

    int sum2 = n * (n + 1) / 2;

    cout << "Missing number = " << sum2 - sum1;

    return 0;
}