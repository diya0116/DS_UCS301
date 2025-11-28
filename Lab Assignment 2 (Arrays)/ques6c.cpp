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

    if (A[0][1] != B[0][0]) {
        cout << "\nMultiplication not possible!";
        return 0;
    }

    int t1 = A[0][2];
    int t2 = B[0][2];

    int k = 1;

    C[0][0] = A[0][0];
    C[0][1] = B[0][1];

    for (int i = 1; i <= t1; i++) {
        for (int j = 1; j <= t2; j++) {

            if (A[i][1] == B[j][0]) {

                int r = A[i][0];
                int c = B[j][1];
                int v = A[i][2] * B[j][2];

                int found = 0;

                for (int x = 1; x < k; x++) {
                    if (C[x][0] == r && C[x][1] == c) {
                        C[x][2] += v;
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    C[k][0] = r;
                    C[k][1] = c;
                    C[k][2] = v;
                    k++;
                }
            }
        }
    }

    C[0][2] = k - 1;

    cout << "\nResult of Multiplication:\n";
    cout << "Row Col Val\n";
    for (int i = 0; i <= C[0][2]; i++)
        cout << C[i][0] << "  " << C[i][1] << "  " << C[i][2] << endl;

    return 0;
}