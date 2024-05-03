// Task 1: Write a simple software that takes a number in USD from user input and convert it into VND
//then prints two results on the screen in a nice format.
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    const double USD_to_VND = 24655.5;
    double USDamount;
    cout <<"Enter amount in USD: $";    cin >>USDamount;
    double VNDamount = USDamount *USD_to_VND;
    cout <<fixed<<setprecision(2)<<"Amount in USD is: $"<<USDamount<<endl<<"Amount in VND is: "<<VNDamount<<" VND"<<endl;
    return 0;
}