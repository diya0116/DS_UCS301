#include <iostream>
using namespace std;

int main() {

    int A[50][3], B[50][3], C[50][3];

    cout << "Matrix A: Enter rows cols and non-zero count: ";
    cin >> A[0][0] >> A[0][1] >> A[0][2];

    cout << "Enter row col value for A:\n";
    for (int i = 1; i <= A[0][2]; i++)
        cin >> A[i][0] >> A[i][1] >> A[i][2];

    cout << "\nMatrix B: Enter rows cols and non-zero count: ";
    cin >> B[0][0] >> B[0][1] >> B[0][2];

    cout << "Enter row col value for B:\n";
    for (int i = 1; i <= B[0][2]; i++)
        cin >> B[i][0] >> B[i][1] >> B[i][2];

    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "\nAddition not possible!";
        return 0;
    }

    int t1 = A[0][2], t2 = B[0][2];
    int i = 1, j = 1, k = 1;

    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    while (i <= t1 && j <= t2) {

        if (A[i][0] < B[j][0] ||
           (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {

            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        }

        else if (B[j][0] < A[i][0] ||
           (B[j][0] == A[i][0] && B[j][1] < A[i][1])) {

            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        }

        else {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] + B[j][2];
            i++; j++; k++;
        }
    }

    while (i <= t1) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++; k++;
    }

    while (j <= t2) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++; k++;
    }

    C[0][2] = k - 1;

    cout << "\nResult of Addition:\n";
    cout << "Row Col Val\n";

    for (int x = 0; x <= C[0][2]; x++)
        cout << C[x][0] << "  " << C[x][1] << "  " << C[x][2] << endl;

    return 0;
}