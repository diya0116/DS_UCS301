#include <iostream>
using namespace std;

int countInversionsSimple(int arr[], int n) {
    int count = 0;

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                count++;
            }
        }
    }
    return count;
}

int mergeAndCount(int arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = 0;
    int temp[right - left + 1];
    int invCount = 0;

    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
        }
    }

    while(i <= mid) temp[k++] = arr[i++];
    while(j <= right) temp[k++] = arr[j++];

    for(int x = 0; x < k; x++) {
        arr[left + x] = temp[x];
    }

    return invCount;
}

int mergeSortAndCount(int arr[], int left, int right) {
    if(left >= right) return 0;

    int mid = (left + right) / 2;
    int inv = 0;

    inv += mergeSortAndCount(arr, left, mid);
    inv += mergeSortAndCount(arr, mid + 1, right);
    inv += mergeAndCount(arr, left, mid, right);

    return inv;
}

int main() {
    int arr[100], n;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int simpleCount = countInversionsSimple(arr, n);

    // For efficient count, copy array because merge-sort modifies it
    int arrCopy[100];
    for(int i = 0; i < n; i++) arrCopy[i] = arr[i];

    int efficientCount = mergeSortAndCount(arrCopy, 0, n - 1);

    cout << "\nInversions (Simple O(n^2)): " << simpleCount;
    cout << "\nInversions (Efficient O(n log n)): " << efficientCount;

    return 0;
}