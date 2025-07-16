#include<iostream>
#include<cmath>
using namespace std;


int main(){
    cout<<"<---SIMPLE CALCULATOR--->\n";
    int a,b;
    cout<<"Enter the first number(a) :\n";
    cin>>a;
    cout<<"Enter the second number(b) :\n";
    cin>>b;
    char opt;
    cout<<"Enter the operetor :\n";
    cin>>opt;
    switch (opt)
    {
    case '*':
        cout<<"a*b = "<<a*b<<endl;
        break;
    case '+':
        cout<<"a+b = "<<a+b<<endl;
        break;
    case '-':
        cout<<"a-b = "<<a-b<<endl;
        break;
    case '/':
        cout<<"a/b = "<<a/b<<endl;
        break;    
    default:
        break;
    }


}