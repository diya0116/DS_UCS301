#include <iostream>
using namespace std;

int countDistinctSimple(int arr[], int n) {
    int count = 0;

    for(int i = 0; i < n; i++) {
        bool found = false;

        for(int j = 0; j < i; j++) {
            if(arr[i] == arr[j]) {
                found = true;
                break;
            }
        }

        if(!found) count++;
    }

    return count;
}

int main() {
    int arr[100], n;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    int distinct = countDistinctSimple(arr, n);

    cout << "\nTotal distinct elements: " << distinct;

    return 0;
}
