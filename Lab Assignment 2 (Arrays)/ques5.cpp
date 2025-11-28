#include <iostream>
using namespace std;

void diagonalMatrix() {
    int n;
    cout << "\nEnter dimension of Diagonal Matrix: ";
    cin >> n;

    int *D = new int[n];

    cout << "Enter diagonal elements:\n";
    for(int i = 0; i < n; i++)
        cin >> D[i];

    cout << "\nStored Diagonal Matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j)
                cout << D[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    delete[] D;
}

void triDiagonalMatrix() {
    int n;
    cout << "\nEnter dimension of Tri-Diagonal Matrix: ";
    cin >> n;

    int size = 3*n - 2;
    int *T = new int[size];

    cout << "Enter tri-diagonal elements row-wise:\n";
    for(int i=0; i<size; i++)
        cin >> T[i];

    cout << "\nStored Tri-Diagonal Matrix:\n";
    int k = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(j == i-1 || j == i || j == i+1)
                cout << T[k++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    delete[] T;
}

void lowerTriangularMatrix() {
    int n;
    cout << "\nEnter dimension of Lower Triangular Matrix: ";
    cin >> n;

    int size = n * (n + 1) / 2;
    int *L = new int[size];

    cout << "Enter lower triangular elements (row-wise):\n";
    for(int i=0; i<size; i++)
        cin >> L[i];

    cout << "\nStored Lower Triangular Matrix:\n";
    int k = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(j <= i)
                cout << L[k++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    delete[] L;
}

void upperTriangularMatrix() {
    int n;
    cout << "\nEnter dimension of Upper Triangular Matrix: ";
    cin >> n;

    int size = n * (n + 1) / 2;
    int *U = new int[size];

    cout << "Enter upper triangular elements (row-wise):\n";
    for(int i=0; i<size; i++)
        cin >> U[i];

    cout << "\nStored Upper Triangular Matrix:\n";
    int k = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(j >= i)
                cout << U[k++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    delete[] U;
}

void symmetricMatrix() {
    int n;
    cout << "\nEnter dimension of Symmetric Matrix: ";
    cin >> n;

    int size = n * (n + 1) / 2;
    int *S = new int[size];

    cout << "Enter lower triangular part row-wise:\n";
    for(int i=0; i<size; i++)
        cin >> S[i];

    cout << "\nStored Symmetric Matrix:\n";
    int k = 0;
    int idx;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {

            // calculate index of S[] for (i,j)
            if(j <= i) {
                idx = i*(i+1)/2 + j;
                cout << S[idx] << " ";
            }
            else {
                idx = j*(j+1)/2 + i;
                cout << S[idx] << " ";
            }
        }
        cout << endl;
    }

    delete[] S;
}

int main() {

    cout << "\nMATRIX STORAGE MENU\n";
    cout << "1. Diagonal Matrix\n";
    cout << "2. Tri-diagonal Matrix\n";
    cout << "3. Lower Triangular Matrix\n";
    cout << "4. Upper Triangular Matrix\n";
    cout << "5. Symmetric Matrix\n";

    int ch;
    cout << "\nEnter choice: ";
    cin >> ch;

    switch(ch) {
        case 1: diagonalMatrix(); break;
        case 2: triDiagonalMatrix(); break;
        case 3: lowerTriangularMatrix(); break;
        case 4: upperTriangularMatrix(); break;
        case 5: symmetricMatrix(); break;
        default: cout << "Invalid choice entered!";
    }

    return 0;
}