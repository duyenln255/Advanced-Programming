//Task 2: Write a simple software that keeps asking the user to make a guess of a secret number
//between 0 and 20 (the program knows this number, but the user does not). At each iteration the
//program gives the feedback on the screen (greater or smaller) when comparing the user guess with the
//secret number. The program finishes when the user guesses the secret number correctly.
// Created by MacBook Pro on 26/02/2024.
#include <iostream>
using namespace std;
int main() {
    const int secretNumber = 14;
    int guess;
    cout << "Welcome to the Guessing Game!" << endl;
    cout << "Guess a number between 0 and 20." << endl;
    do {
        cout << "Enter your guess and remember it must be a number in the range of 0 to 20: ";
        cin >> guess;
        while(guess < 0 || guess > 20){
            cout<<"Invalid number! Please retry, it must be a number in the range of 0 to 20: ";
            cin>>guess;
        }
        if (guess == secretNumber) cout << "Congratulations! You guessed the secret number." << endl;
        else if (guess < secretNumber)  cout << "Try again. Your guess is smaller than the secret number." << endl;
        else   cout << "Try again. Your guess is greater than the secret number." << endl;
    } while (guess != secretNumber);
    return 0;
}
