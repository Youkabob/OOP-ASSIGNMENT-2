#include <bits/stdc++.h>
#include "BigReal.h"
#include "BigReal.cpp"
using namespace std;

int main() {
    string s1,s2;
    cout<<"enter the first number: ";
    cin>>s1;
    cin>>s2;
    BigReal num1 (s1);
    BigReal num2(s2);

    if(num1==num2){
        cout<<"THEY ARE EQUAL"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
if(num1<num2){
    cout<<"Num2 is greater";
}
else{
    cout<<"NO"<<endl;
}
if(num1>num2){
    cout<<"Num1 is greater";
}
else{
    cout<<"NO";
}

}
