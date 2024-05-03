//● Task 2: Write a simple software that takes from the user input elements of a 4x4 square matrix and
//store them in a two-dimensional array. Display on the screen the matrix with all of its elements in a nice
//table format, the sum of all elements in the matrix, the sum of all elements in each row, the sum of all
//elements in each column, and the sum of all elements in each diagonal. The first easier approach is to
//manually indicate each element’s index. The second approach is to use for loops to go through the
//correct elements automatically
// Created by LND on 26/02/2024.
#include <iostream>
#include <iomanip>
using namespace std;
const int size = 4;
void displayMatrix(int matrix[][size]) {
    cout << "Matrix:" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
int main() {
    int matrix[size][size];
    cout << "Enter elements of the 4x4 matrix:" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << "Enter element at position (" << i << ", " << j << "): ";
            cin >> matrix[i][j];
        }
    }
    displayMatrix(matrix);
    int totalSum = 0;
    int rowSums[size] = {0};
    int colSums[size] = {0};
    int diagonalSum1 = 0;
    int diagonalSum2 = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            totalSum += matrix[i][j];
            rowSums[i] += matrix[i][j];
            colSums[j] += matrix[i][j];
            if (i == j) diagonalSum1 += matrix[i][j];
            if (i + j == size - 1) diagonalSum2 += matrix[i][j];
        }
    }
    cout << "Total sum of all elements: " << totalSum << endl;
    cout << "Sum of elements in each row:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Row " << i + 1 << ": " << rowSums[i] << endl;
    }
    cout << "Sum of elements in each column:" << endl;
    for (int j = 0; j < size; ++j) {
        cout << "Column " << j + 1 << ": " << colSums[j] << endl;
    }
    cout << "Sum of elements in the main diagonal: " << diagonalSum1 << endl;
    cout << "Sum of elements in the secondary diagonal: " << diagonalSum2 << endl;
    return 0;
}
