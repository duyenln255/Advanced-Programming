//Task 1: Write a simple software that takes the scores of 10 students (using for loop), then calculate the
//average score and display on the screen
// Created by LND on 26/02/2024.
#include <iostream>
using namespace std;
int main() {
    const int n = 10;
    int scores[n], totalScore = 0;
    cout << "Enter the scores of " << n << " students:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Enter score for student " << (i + 1) << ": ";
        cin >> scores[i];
        totalScore += scores[i];
    }
    cout << "Average score of " << n << " students: " << static_cast<double>(totalScore) / n << endl;
    return 0;
}
