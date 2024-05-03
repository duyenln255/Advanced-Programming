// Task 1: Write three functions sumTripple, mulTripple, aveTriple that take three input parameters which
//are three float numbers then calculate and return the sum, the multiplication, and the average of three
//numbers. Write a program that keeps asking for three numbers from user input, then calls the three
//functions above to calculate the return values, after that displays the return values on the screen. This
//process is finished when the user enters ‘-1’.
// Created by LND on 26/02/2024.
//
#include <iostream>
using namespace std;
float sumTriple(float a, float b, float c) {return a + b + c;}
float mulTriple(float a, float b, float c) {return a * b * c;}
float aveTriple(float a, float b, float c) {return (a + b + c) / 3.0;}
int main() {
    float num1, num2, num3;
    while (true) {
        cout << "Enter three numbers (or '-1' to stop): ";
        cin >> num1;
        if (num1 == -1) break;
        cin >> num2 >> num3;
        cout << "Sum of the three numbers: " << sumTriple(num1, num2, num3) << endl;
        cout << "Product of the three numbers: " << mulTriple(num1, num2, num3) << endl;
        cout << "Average of the three numbers: " << aveTriple(num1, num2, num3) << endl;
    }
    return 0;
}
