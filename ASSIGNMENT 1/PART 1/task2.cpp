////Task 2: Write a simple calculator to calculate & display the summation, subtraction, division, modulus,
////multiplication of two numbers
#include <iostream>
using namespace std;
int main(){
    double a, b;
    cout <<"Please enter 2 numbers: ";
    cin >>a>>b;
    //summation

    double sum, sub, div, mul;
    int mod;
    sum = a + b;
    cout << "The summation of two numbers is "<<a<<" + "<<b<<" = "<<sum <<endl;
    sub = a - b;
    cout << "The subtraction of two numbers is "<<a<<" - "<<b<<" = "<<sub<<endl;
    mul = a*b;
    cout << "The multiplication of two numbers is "<<a<<" * "<<b<<" = "<<mul<<endl;
    if(b != 0){
        div = a/b;
        cout << "The division of two numbers is "<<a<<" / "<<b<<" = "<<div<<endl;
        mod = int(a)%int(b);
        cout << "The modulus of two numbers is "<< a <<" % "<<b<<" = "<<mod<<endl;
    }
    else cout <<"The division and modulus have an error: Division by zero"<<endl;
       return 0;
}
