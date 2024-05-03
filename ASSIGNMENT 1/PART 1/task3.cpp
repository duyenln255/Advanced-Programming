// Created by LND on 26/02/2024.
// Task 3: Write a simple program to display your personal information in a nice presentation that you design.
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    // Display personal information
    cout << "******************************************" << endl;
    cout << "*          Personal Information          *" << endl;
    cout << "******************************************" << endl;
    cout << left << setw(15) << "Name:" << "Lê Ngọc Duyên" << endl;
    cout << left << setw(15) << "Birthday:" << "25/05/2001" << endl;
    cout << left << setw(15) << "Address:" << "149 Bành Văn Trân street" << endl;
    cout << left << setw(15) << "City:" << "Ho Chi Minh city" << endl;
    cout << left << setw(15) << "Country:" << "Viet Nam" << endl;
    cout << left << setw(15) <<"Social Link: "<<"facebook.com/irisle255"<<endl;
    cout << "******************************************" << endl;

    return 0;
}
