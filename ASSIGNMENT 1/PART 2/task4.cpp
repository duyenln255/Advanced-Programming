//Task 4: Write a simple software that takes from user input basic information of a student including full
//name, day of birth, hometown, major, … then display this information on the screen in a nice format.
// Created by LENGOCDUYEN on 26/02/2024.
#include <iostream>
#include <string>
using namespace std;
struct Student {string fullName, dateOfBirth, hometown, major, ID;};
int main() {
    Student student;
    // Get student information from user input
    cout << "Enter student's full name: ";
    getline(cin, student.fullName);
    cout << "Enter student's date of birth (YYYY-MM-DD): ";
    getline(cin, student.dateOfBirth);
    cout << "Enter student's hometown: ";
    getline(cin, student.hometown);
    cout << "Enter student's major: ";
    getline(cin, student.major);
    cout << "Enter student's ID: ";
    getline(cin, student.ID);
    // Display student information
    cout << "-------------------Student Information-------------------" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "Full Name: " << student.fullName << endl;
    cout << "Date of Birth: " << student.dateOfBirth << endl;
    cout << "Hometown: " << student.hometown << endl;
    cout << "Major: " << student.major << endl;
    cout << "Student ID: " << student.ID << endl;
    cout << "---------------------------------------------------------" << endl;
    return 0;
}



