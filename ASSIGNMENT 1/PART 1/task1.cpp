////Task 1: Write a simple program to calculate & display the average of three integer numbers
#include <iostream>
using namespace std;
int main() {
    // Declare variables
    int num1, num2, num3;
    double average;
    cout << "Enter three integer numbers separated by spaces: ";
    cin >> num1 >> num2 >> num3;
    // Calculate the average
    average = (num1 + num2 + num3) / 3.0;
    cout << "The average of " << num1 << ", " << num2 << ", and " << num3 << " is: " << average << endl;
    return 0;
}
