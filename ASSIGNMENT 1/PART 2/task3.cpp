//Task 3: Write a simple calculator that takes one number from the user then calculates and displays its
//abs, sin, cos, tan, log, log10, sqrt, exp.
// Created by LENGOCDUYEN on 26/02/2024.
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    double number;
    cout << "Enter a number: ";
    cin >> number;
    // Calculate and display results
    cout << "Absolute value: " << abs(number) << endl;
    cout << "Sine: " << sin(number) << endl;
    cout << "Cosine: " << cos(number) << endl;
    cout << "Tangent: " << tan(number) << endl;
    cout << "Natural logarithm: " << log(number) << endl;
    cout << "Base-10 logarithm: " << log10(number) << endl;
    cout << "Square root: " << sqrt(number) << endl;
    cout << "Exponential: " << exp(number) << endl;
    return 0;
}
