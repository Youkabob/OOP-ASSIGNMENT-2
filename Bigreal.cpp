//
// Created by alaa wael on 10/30/2023.
//
#include "Bigreal.h"
#include <bits/stdc++.h>
#include <iostream>
#include <regex>
using namespace std;



BigReal::BigReal(const BigReal &&other) {
    this->whole = other.whole;
    this->fraction = other.fraction;
}

BigReal::BigReal (const string &realNumber){
    setWhole(realNumber);
    setFraction(realNumber);
}

//***********************************************************************************************************



void BigReal::setFraction(const string &number){
    int pointIdx = -1;
    string fractionPart;
    for (int i = 0; i <number.size(); ++i) {
        if (number[i] == '.' && pointIdx == -1){
            pointIdx = i;
        }
        else if (pointIdx != -1){  // found the decimal point
            fractionPart+=number[i];
        }
    }

    if(pointIdx==-1 || fractionPart.empty() || !regex_match(fractionPart, regex("\\d+") ) ){
        this->fraction ="0";
        return;
    }

    // remove trailing zeros
    for (int i = fractionPart.size()-1; i>=0 ; --i){
        if(fractionPart[i]!='0'){
            break;
        }
        fractionPart.erase(i,1);
    }

    if(fractionPart.empty())
        this->fraction = "0";
    else
        this->fraction = fractionPart;
}



void BigReal::setWhole(const string &number) {
    string wholePart ;
    for (const char& i : number) {
        if(i=='.')
            break;
        wholePart+=i;
    }
    this->whole = wholePart;
}


int BigReal::size()const{
    return fraction.size() + whole.size();
}

//***********************************************************************************************************
char BigReal::Sign()const{
    return  sign;
}


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

BigReal BigReal :: operator+ (const BigReal& other)const {
string carry;

}


ostream& operator << ( ostream& out,const BigReal& num){
    out<<num.whole<<"." << num.fraction;
    return  out;
}

//***********************************************************************************************************