// Design the logic to remove the duplicate elements from an Array and after the deletion the array should containtheunique elements.

#include <iostream>
using namespace std;   

const int MAX = 100;

void createArray(int arr[], int &size) {
    cout << "Enter number of elements: ";
    cin >> size;
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void displayArray(int arr[], int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void removeDuplicates(int arr[], int &size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; ) {
            if (arr[i] == arr[j]) {
                // Shift elements to the left to remove duplicate
                for (int k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                size--; // Reduce size after removing duplicate
            } else {
                j++; // Only increment j if no deletion occurred
            }
        }
    }
}

int main() {

    int arr[MAX];
    int size;

    createArray(arr, size);
    cout << "Original ";
    displayArray(arr, size);

    removeDuplicates(arr, size);
    cout << "Array after removing duplicates: ";
    displayArray(arr, size);

    return 0;

}