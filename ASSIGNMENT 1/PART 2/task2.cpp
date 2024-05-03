// Task 2: Write a simple software that takes the radius and height of a cylinder, then calculate its volume
//and display the information on the screen in a nice format.
// Created by LENGOCDUYEN on 26/02/2024.
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    double radius, height;
    cout << "Enter the radius of the cylinder: ";   cin >> radius;
    cout << "Enter the height of the cylinder: ";   cin >> height;
    // Calculate the volume of the cylinder
    double volume = M_PI * pow(radius, 2) * height;
    cout << "Cylinder Information:" << endl;
    cout << "Radius: " << radius << endl;
    cout << "Height: " << height << endl;
    cout << fixed << setprecision(4)<< "Volume: " << volume << endl;
    return 0;
}
