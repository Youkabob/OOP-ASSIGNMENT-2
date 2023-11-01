//
// Created by alaa wael on 10/30/2023.
//
#include "Bigreal.h"
#include <bits/stdc++.h>
#include <iostream>
#include <regex>
using namespace std;

BigReal ::BigReal(double realNumber) {//set to 0.0
    int temp = realNumber;
    if (realNumber == 0) {
        whole.push_back('0');
        setSign('+');
    } else if (realNumber < 0) {
        setSign('-');
        temp *= -1;
    } else
        setSign('+');
    while (temp) {
        int digit = temp % 10;
        temp /= 10;
        whole.push_front(digit + '0');
    }
}

BigReal ::BigReal(string realNumber){
    number=realNumber;
}

// ***************************** Copy Constructor ***********************************************
BigReal::BigReal(const BigReal &other) {

    // extracting  digits
    for (int i = 0; i < other.size(); ++i) {
        this->whole.push_back(other.whole[i]);
    }
    //setting sign
    setSign(other.getSign());
}

// ******************************* Assignment "=" Operator  ***************************************
BigReal& BigReal::operator=(const BigReal &num) {// Assignment operator
    if(this == &num)
        return *this;

    this->whole.clear(); // clear the object
    this->setSign(num.getSign()); // copy the sign

    // copy the digits
    for (const char& i : num.whole) {
        whole.push_back(i);
    }
    return *this;
}

char BigReal::getSign() const {
    return  sign;
}

bool BigReal ::isValidReal (){
    if (count(number.begin(), number.end(),'.')>1||
        count(number.begin(), number.end(),' ')>0||number[1]=='+'||number[1]=='-') {
        return 0;
    }
    return 1;
}


void BigReal::setSign(char Sign) {
    if(!isdigit(Sign)) {
        this->sign = Sign;
    }
    else
        this->sign = '+';
}
int BigReal::size() const {
    // return deque's size
    return  whole.size();
}
void BigReal::matchSize(BigReal& LHS, BigReal& RHS){
    long long diff = abs(RHS.size() - LHS.size() );
    for(long long i = 0; i < diff; i++){
        // add leading zeros to the shorter number to facilitate operations
        if(RHS.size() > LHS.size()){
            LHS.whole.push_front('0');
        }
        else{
            RHS.whole.push_front('0');
        }
    }
}

/*
BigReal :: BigReal (string realNumber) {
    number=realNumber;
    if (count(number.begin(), number.end(),'.')>1||
        count(number.begin(), number.end(),' ')>0) {
        whole='0';
        fraction='0';
        sign='+';
    }

    else{
        if (number[0]=='-'||number[0]=='+')
        sign = number[0];
        for (auto i: number) {
            if (i == '.') break;
            if (i == '+' || i == '-') continue;
            whole += i;
        }
        if (number.size()>whole.size()+1)
        fraction=number.substr(whole.size()+1,number.size()-1);
    }
}
*/
ostream& operator<<(ostream& out,const BigReal& bigint) {
    // if the object negative from check it's sign output the sign first
    if(bigint.getSign()=='-')
        out << '-';
    // then output the digits
    for (char i : bigint.whole) {
        out << i ;
    }
    return out;
}
//***********************************************************************************************************