//Task 1: Write a simple software that takes from the user input students’ names and their scores
//(0-100), storing these values into two arrays until the user indicates that they want to stop with ‘-1’.
//Assume that the maximum number of students is 100. Also use another array to store the status of
//passed (score >= 50) or failed (score < 50) of the above students. Once the data entering process
//finishes, display the students’ names, scores, and passed/failed status nicely in 3 columns.
// Created by LND on 26/02/2024.
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;
const int MAX_STUDENTS = 100;
const int COLUMN_WIDTH = 30;
bool isValidName(const string &name) {
    for (char c : name) {
        if (!isalpha(c) && c != ' ') return false;
    }
    return true;
}
bool isValidScore(const string &input) {
    for (char c : input) {
        if (!isdigit(c)) return false;
    }
    int score = stoi(input);
    return (score >= 0 && score <= 100);
}
int main() {
    string names[MAX_STUDENTS];
    int scores[MAX_STUDENTS];
    string status[MAX_STUDENTS];
    int numStudents = 0;
    cout << "Enter student names and their scores (0-100)." << endl;
    cout << "Enter '-1' to stop." << endl;
    while (numStudents < MAX_STUDENTS) {
        cout << "Enter student name (or '-1' to stop): ";
        getline(cin, names[numStudents]);
        if (names[numStudents] == "-1") break;
        if (!isValidName(names[numStudents])) {
            cout << "Invalid name! Name must consist of alphabetical characters and spaces only." << endl;
            continue;
        }
        cout << "Enter student score: ";
        string inputScore;
        getline(cin, inputScore);
        while (!isValidScore(inputScore)) {
            cout << "Invalid score! Score must be between 0 and 100. Enter again: ";
            getline(cin, inputScore);
        }
        scores[numStudents] = stoi(inputScore);
        status[numStudents] = (scores[numStudents] >= 50) ? "Passed" : "Failed";
        numStudents++;
    }
    cout << "-----------------------Students' Information-----------------------" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << setw(COLUMN_WIDTH) << left << "Name" << setw(COLUMN_WIDTH) << left << "Score" << setw(COLUMN_WIDTH) << left << "Status" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    for (int i = 0; i < numStudents; ++i) {
        cout << setw(COLUMN_WIDTH) << left << names[i] << setw(COLUMN_WIDTH) << left << scores[i] << setw(COLUMN_WIDTH) << left << status[i] << endl;
    }
    return 0;
}
