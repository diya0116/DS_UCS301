#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n-1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;

        else if(arr[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38};
    int n = 7;

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int pos = binarySearch(arr, n, key);

    if(pos == -1)
        cout << "Element not found";
    else
        cout << "Element found at index " << pos;

    return 0;
}