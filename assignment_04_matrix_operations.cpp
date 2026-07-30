#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void readMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[10][10], int rows, int cols, int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(int matrixA[10][10], int matrixB[10][10], int rows, int cols, int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void multiplyMatrices(int matrixA[10][10], int matrixB[10][10], int m, int n, int p, int result[10][10]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += matrixA[i][k] * matrixB[k][j];
            }
            result[i][j] = sum;
        }
    }
}

int main() {
    // ----- Part A: Transpose -----
    cout << "=== Part A: Transpose a Matrix ===" << endl;
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int matrix[10][10];
    cout << "Enter Matrix:" << endl;
    readMatrix(matrix, rows, cols);

    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(matrix, rows, cols);

    int transposed[10][10];
    transposeMatrix(matrix, rows, cols, transposed);

    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(transposed, cols, rows);

    // ----- Part B: Addition -----
    cout << "\n=== Part B: Add Two Matrices ===" << endl;
    int matrixA[10][10], matrixB[10][10];
    cout << "Enter Matrix A (" << rows << "x" << cols << "):" << endl;
    readMatrix(matrixA, rows, cols);
    cout << "Enter Matrix B (" << rows << "x" << cols << "):" << endl;
    readMatrix(matrixB, rows, cols);

    int sumMatrix[10][10];
    addMatrices(matrixA, matrixB, rows, cols, sumMatrix);

    cout << "\nSum of Matrices:" << endl;
    displayMatrix(sumMatrix, rows, cols);

    // ----- Part C: Multiplication -----
    cout << "\n=== Part C: Multiply Two Matrices ===" << endl;
    int m, n, p;
    cout << "Enter rows of Matrix A: ";
    cin >> m;
    cout << "Enter columns of Matrix A / rows of Matrix B: ";
    cin >> n;
    cout << "Enter columns of Matrix B: ";
    cin >> p;

    int matA[10][10], matB[10][10];
    cout << "Enter Matrix A (" << m << "x" << n << "):" << endl;
    readMatrix(matA, m, n);
    cout << "Enter Matrix B (" << n << "x" << p << "):" << endl;
    readMatrix(matB, n, p);

    int product[10][10];
    multiplyMatrices(matA, matB, m, n, p, product);

    cout << "\nProduct of Matrices (A x B):" << endl;
    displayMatrix(product, m, p);

    return 0;
}
