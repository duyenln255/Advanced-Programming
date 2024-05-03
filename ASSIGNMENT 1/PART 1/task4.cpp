//Task 4: Write a simple program to calculate and display x percentage of a number y.
// Created by MacBook Pro on 26/02/2024.
//
#include <iostream>
using namespace std;
int main(){
    double x, y;
    // Input the number y and the percentage x
    cout << "Enter the number (y): "; cin >> y;
    cout << "Enter the percentage (x): "; cin >> x;
    // Calculate the percentage
    double result = (x / 100) * y;
    // Display the result
    cout << x << "% of " << y << " is: " << result << endl;
    return 0;
}
