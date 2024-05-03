//Task 2: Write four functions that calculate and return the areas of a square, a rectangle, a circle, and a
//triangle. You need to decide the appropriate peters for each of these four functions. Write a
//software that lets the user choose each of these four functionalities and use it (you also need to let the
//user enter appropriate peters for the chosen function). This process is finished when the user
//enters ‘-1’
// Created by LND on 26/02/2024.
//
#include <iostream>
#include <cmath>
using namespace std;
const float PI = 3.14159;
float areaSquare(float side) {return side * side;}
float areaRectangle(float length, float width) {return length * width;}
float areaCircle(float radius) {return PI * radius * radius;}
float areaTriangle(float a, float b, float c) {
    float s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
int main() {
    int c;
    float p1, p2;
    float side1, side2, side3;
    while (true) {
        cout << "Choose an option:" << endl<< "1. Calculate area of a square" << endl<< "2. Calculate area of a rectangle" << endl << "3. Calculate area of a circle" << endl<< "4. Calculate area of a triangle" << endl;
        cout << "Enter your choice (or '-1' to stop): ";
        cin >> c;
        if (c == -1) break;
        switch (c) {
            case 1:
                cout << "Enter the side length of the square: ";
                cin >> p1;
                cout << "Area of the square: " << areaSquare(p1) << endl;
                break;
            case 2:
                cout << "Enter the length and width of the rectangle: ";
                cin >> p1 >> p2;
                cout << "Area of the rectangle: " << areaRectangle(p1, p2) << endl;
                break;
            case 3:
                cout << "Enter the radius of the circle: ";
                cin >> p1;
                cout << "Area of the circle: " << areaCircle(p1) << endl;
                break;
            case 4:
                cout << "Enter the lengths of the three sides of the triangle: ";
                cin >> side1 >> side2 >> side3;
                if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1) {
                    cout << "Area of the triangle: " << areaTriangle(side1, side2, side3) << endl;
                } else {
                    cout << "Invalid triangle! The sum of any two sides must be greater than the third side." << endl;
                }
                break;
            default:
                cout << "Invalid c! Please try again." << endl;
        }
    }
    return 0;
}
