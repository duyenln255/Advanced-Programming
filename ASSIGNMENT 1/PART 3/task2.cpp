//Task 2: Write a simple software that asks for user input for the amount of money in VND, then asking
//their choice of currency conversion to AUD or USD: (1) for AUD and (2) for USD. Do the calculation
//and show the corresponding information based on their choice.
// Created by LND on 26/02/2024.
#include <iostream>
using namespace std;
int main(){
    int choice;
    int VND;
    double convertedAmount;
    double VNDtoAUD = 0.000061, VNDtoUSD = 0.000041;
    cout << "Enter 1 or 2 to choose VND currency conversion.\n(1) for AUD  \n(2) for USD\n";    cin>>choice;
    while(choice != 1 && choice != 2){
        cout << "INVALID NUMBER. Only the numbers 1 or 2 1are accepted.\n";
        cin>>choice;
    }
    cout <<"Enter the amount of money in VND: ";cin>>VND;
    if(choice == 1){
        convertedAmount = double(VND *VNDtoAUD);
        cout<<"Converted amount: "<<convertedAmount<<" AUD";
    }
    else {
        convertedAmount = double(VND *VNDtoUSD);
        cout<<"Converted amount: "<<convertedAmount<<" USD";}
    return 0;
}
