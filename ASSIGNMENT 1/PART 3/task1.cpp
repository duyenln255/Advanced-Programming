//Task 1: Write a simple software that asks for user’s age then calculates the zoo ticket cost based on
//the given age: if age < 5 then ticket is free, if age is between 5 and 10 then ticket costs $10, if age is
//between 11 and 16 then ticket costs $20, if age is greater than 16 then ticket costs $25. Display the
//ticket price information for the user to see
#include <iostream>
using namespace std;
int main(){
    int age, ticketPrice;
    cout <<"Enter your age: "; cin >> age;
    if(age < 5) ticketPrice = 0;
    else if(age>= 5 && age <=10) ticketPrice = 10;
    else if(age >=11 && age <=16)   ticketPrice = 20;
    else ticketPrice = 25;
    cout <<"Your ticket price is $"<<ticketPrice<<endl;
    return 0;
}