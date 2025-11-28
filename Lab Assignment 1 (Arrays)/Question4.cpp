// Implement the logic to
// a. Reverse the elements of an array
// b. Find the matrix multiplication
// c. Find the Transpose of a Matrix

#include <iostream> 
using namespace std;

const int MAX = 100;

void createMatrix(int matrix[MAX][MAX], int &rows, int &cols) {
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;
    cout << "Enter elements of the matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    cout << "Matrix elements:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[MAX][MAX], int &rows, int &cols) {
    int transposed[MAX][MAX];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    swap(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = transposed[i][j];
        }
    }
}

int main() {
    
    int matrix[MAX][MAX];
    int rows, cols;

    createMatrix(matrix, rows, cols);
    cout << "Original ";
    displayMatrix(matrix, rows, cols);

    transposeMatrix(matrix, rows, cols);
    cout << "Transposed ";
    displayMatrix(matrix, rows, cols);

    return 0;
}