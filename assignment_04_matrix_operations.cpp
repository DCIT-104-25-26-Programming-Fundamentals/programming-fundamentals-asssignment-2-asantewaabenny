// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function to print a matrix nicely in a grid
void printMatrix(int mat[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

// Function to read values into a matrix
void readMatrix(int mat[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

// PART A: Transpose a matrix (rows become columns)
void transposeMatrix(int mat[10][10], int rows, int cols) {
    int transposed[10][10];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = mat[i][j];
        }
    }

    cout << "\nTransposed Matrix:\n";
    printMatrix(transposed, cols, rows);
}

// PART B: Add two matrices (element-by-element)
void addMatrices(int A[10][10], int B[10][10], int rows, int cols) {
    int sum[10][10];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "\nSum of Matrices (A + B):\n";
    printMatrix(sum, rows, cols);
}

// PART C: Multiply two matrices (A: M x N, B: N x P)
void multiplyMatrices(int A[10][10], int rA, int cA, int B[10][10], int rB, int cB) {
    if (cA != rB) {
        cout << "\nError: Multiplication not possible! Columns of A must match Rows of B.\n";
        return;
    }

    int result[10][10];

    // Initialize result matrix with zeros
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            result[i][j] = 0;
        }
    }

    // Matrix multiplication using 3 nested loops
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            for (int k = 0; k < cA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nProduct of Matrices (A x B):\n";
    printMatrix(result, rA, cB);
}

int main() {
    int rA, cA, rB, cB;
    int A[10][10], B[10][10];

    // --- PART A & FIRST MATRIX INPUT ---
    cout << "=== MATRIX A INPUT ===" << endl;
    cout << "Enter number of rows for Matrix A: ";
    cin >> rA;
    cout << "Enter number of columns for Matrix A: ";
    cin >> cA;

    readMatrix(A, rA, cA);

    cout << "\nOriginal Matrix A:\n";
    printMatrix(A, rA, cA);

    // Run Part A
    transposeMatrix(A, rA, cA);

    // --- PART B & SECOND MATRIX INPUT ---
    cout << "\n=== MATRIX B INPUT ===" << endl;
    cout << "Enter number of rows for Matrix B: ";
    cin >> rB;
    cout << "Enter number of columns for Matrix B: ";
    cin >> cB;

    readMatrix(B, rB, cB);

    cout << "\nOriginal Matrix B:\n";
    printMatrix(B, rB, cB);

    // Run Part B (Requires both matrices to have identical dimensions)
    if (rA == rB && cA == cB) {
        addMatrices(A, B, rA, cA);
    } else {
        cout << "\nCannot add matrices: Dimensions must be identical.\n";
    }

    // --- PART C ---
    // Run Part C (Requires columns of A == rows of B)
    multiplyMatrices(A, rA, cA, B, rB, cB);

    return 0;
}