// 1) Develop a Menu driven program to demonstrate the following operations of Arrays
// ——MENU——-
// 1.CREATE
// 2.DISPLAY
// 3.INSERT
// 4.DELETE
// 5.LINEAR SEARCH
// 6.EXIT

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

void insertElement(int arr[], int &size) {
    int element, position;
    cout << "Enter element to insert: ";
    cin >> element;
    cout << "Enter position to insert (0 to " << size << "): ";
    cin >> position;
    if (position < 0 || position > size || size >= MAX) {
        cout << "Invalid position or array full!" << endl;
        return;
    }
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    size++;
}

void deleteElement(int arr[], int &size) {
    int position;
    cout << "Enter position to delete (0 to " << size - 1 << "): ";
    cin >> position;
    if (position < 0 || position >= size) {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void linearSearch(int arr[], int size) {
    int element;
    cout << "Enter element to search: ";
    cin >> element;
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            cout << "Element found at position: " << i << endl;
            return;
        }
    }
    cout << "Element not found!" << endl;
}

int main() {
    int arr[MAX];
    int size = 0;
    int choice;

    do {
        cout << "——MENU——-" << endl;
        cout << "1. CREATE" << endl;
        cout << "2. DISPLAY" << endl;
        cout << "3. INSERT" << endl;
        cout << "4. DELETE" << endl;
        cout << "5. LINEAR SEARCH" << endl;
        cout << "6. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createArray(arr, size);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                insertElement(arr, size);
                break;
            case 4:
                deleteElement(arr, size);
                break;
            case 5:
                linearSearch(arr, size);
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

