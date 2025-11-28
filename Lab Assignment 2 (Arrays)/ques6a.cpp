#include <iostream>
using namespace std;

int main() {

    int A[50][3], T[50][3];

    cout << "Enter rows, cols and non-zero count: ";
    cin >> A[0][0] >> A[0][1] >> A[0][2];

    cout << "Enter row col value for each non-zero element:\n";
    for(int i = 1; i <= A[0][2]; i++)
        cin >> A[i][0] >> A[i][1] >> A[i][2];

    int rows = A[0][0];
    int cols = A[0][1];
    int t = A[0][2];

    T[0][0] = cols;
    T[0][1] = rows;
    T[0][2] = t;

    int k = 1;

    for (int c = 0; c < cols; c++) {
        for (int i = 1; i <= t; i++) {
            if (A[i][1] == c) {
                T[k][0] = A[i][1];
                T[k][1] = A[i][0];
                T[k][2] = A[i][2];
                k++;
            }
        }
    }

    cout << "\nTranspose (Triplet Format):\n";
    cout << "Row Col Val\n";

    for (int i = 0; i <= T[0][2]; i++)
        cout << T[i][0] << "  " << T[i][1] << "  " << T[i][2] << endl;

    return 0;
}