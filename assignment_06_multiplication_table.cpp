// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;
// PART A: Function to print a single multiplication table from 1 to 12
void printTable(int number) {
    cout << "\nMultiplication Table for " << number << ":\n";
    for (int i = 1; i <= 12; i++) {
        cout << number << "  x  " << i << "  =  " << (number * i) << endl;
    }
}

// PART B: Function to print tables for all numbers from 1 to N
void printTablesUpTo(int n) {
    for (int i = 1; i <= n; i++) {
        printTable(i); // Reuses Part A's function!
        cout << "---------------------------" << endl;
    }
}

int main() {
    int num, maxN;

    // --- PART A ---
    cout << "=== PART A ===" << endl;
    cout << "Enter a number for single table: ";
    cin >> num;

    // Validate input
    if (num <= 0) {
        cout << "Error: Number must be a positive integer." << endl;
        return 1;
    }

    printTable(num);

    // --- PART B ---
    cout << "\n=== PART B ===" << endl;
    cout << "Enter N to print tables from 1 to N: ";
    cin >> maxN;

    // Validate input
    if (maxN <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 1;
    }

    printTablesUpTo(maxN);

    return 0;
}
