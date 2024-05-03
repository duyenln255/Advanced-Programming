//Task 3: Write a simple calculator that asks for user input for two numbers and their choice of an
//operator (+, -, *, /) then calculates and displays the information accordingly.
// Created by MacBook Pro on 26/02/2024.
#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char op;
    cout << "Enter first number: ";     cin >> num1;
    cout << "Enter second number: ";    cin >> num2;
    cout << "Enter the operator (+, -, *, /): ";    cin >> op;
    switch(op) {
        case '+':
            cout << "Result: " <<num1<<" + "<< num2 <<" = "<< num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " <<num1<<" - "<< num2 <<" = "<< num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: "<<num1<<" * "<< num2 <<" = " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) cout << "Result: 4." <<num1<<" / "<< num2 <<" = "<< num1 / num2 << endl;
            else  cout << "Error: Division by zero!" << endl;
            break;
        default:
            cout << "Error: Invalid operator!" << endl;
            break;
    }
    return 0;
}
