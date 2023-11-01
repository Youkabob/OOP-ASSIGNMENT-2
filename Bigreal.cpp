//
// Created by alaa wael on 10/30/2023.
//
#include <bits/stdc++.h>
#include "Bigreal.h"
#include <iostream>
#include <regex>
using namespace std;

//***************************** checking validity **********************************************************
bool BigReal ::isValidReal (string number){
    if (count(number.begin(), number.end(),'.')>1||
        count(number.begin(), number.end(),' ')>0||number[1]=='+'||number[1]=='-') {
        return 0;
    }
    return 1;
}


//***************************** assign number ********************************************************
BigReal ::BigReal(string realNumber){
    if (isValidReal(realNumber)){
        whole= setWhole(realNumber);
        fraction= setFraction(realNumber);
        sign= setSign(realNumber[0]);
        Size=realNumber.size()-2;
    }
    else{
        whole="0";
        fraction="0";
        sign='+';
        Size=0;
    }
}

//***************************** whole setter **********************************************************
string BigReal::setWhole(const string &number) {
    string wholePart ="";
    for (const char& i : number) {
        if(i=='.') {
           point=1;
            break;
        }
        wholePart+=i;
    }
    return wholePart;
}

//***************************** fraction setter *******************************************************
string BigReal::setFraction(const string &number){
    string fracpart="";
    bool dot=0;
    for (const char& i : number) {
        if(i=='.')
            dot=1;
        else if (dot)
        fracpart+=i;
    }
    point=dot;
    return fracpart;
}

//***************************** sign setter ***********************************************************
char BigReal::setSign(char Sign) {
    if(Sign=='-'||Sign=='+') {
        return Sign;
    }
    else
        return '+';
}



//***************************** Copy Constructor **********************************************************
BigReal::BigReal(const BigReal &other) {

    sign=other.sign;
    whole=other.whole;
    fraction=other.fraction;
    Size=other.Size;
    point=other.point;

}

//******************************* Assignment "=" Operator  ************************************************
BigReal& BigReal::operator=(const BigReal &num) {// Assignment operator
    if(this == &num)
        return *this;

    this->whole.clear(); // clear the object
    this->fraction.clear(); // clear the object
    this->sign=num.getSign(); // copy the sign
    this->point=num.point;
    // copy the digits
    for (const char& i : num.whole) {
        whole.push_back(i);
    }
    for (const char& i : num.fraction) {
        fraction.push_back(i);
    }
    return *this;
}


char BigReal::getSign() const {
    return  sign;
}
bool BigReal::operator<(BigReal rhs) {
    if ( sign == '+' && rhs.sign == '-' )
        return false ;
    if ( sign == '-' && rhs.sign == '+' )
        return true ;
    if ( sign == '+' && rhs.sign == '+' )
        return (( rhs.whole + '.' + rhs.fraction ) > ( whole + '.' + fraction )) ;
    else if ( sign == '-' && rhs.sign == '-' )
        return (( rhs.whole + '.' + rhs.fraction ) < ( whole + '.' + fraction )) ;
}
**********************************************************************************************************
bool BigReal::operator>(BigReal rhs) {
    if ( sign == '+' && rhs.sign == '-' )
        return true ;
    if ( sign == '-' && rhs.sign == '+' )
        return false;
    if ( sign == '+' && rhs.sign == '+' )
        return (( rhs.whole + '.' + rhs.fraction ) < ( whole + '.' + fraction )) ;
    else if ( sign == '-' && rhs.sign == '-' )
        return (( rhs.whole + '.' + rhs.fraction ) > ( whole + '.' + fraction )) ;
}
***********************************************************************************************************
bool BigReal::operator==(BigReal anotherReal) {
    if(sign!=anotherReal.sign){
        return false;
    }
    if(sign==anotherReal.sign){
        if(whole==anotherReal.whole){
            if(fraction==anotherReal.fraction){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
}
************************************************************************************************************

ostream& operator<<(ostream &out, BigReal num) {
    // output the sign first
        out << num.sign;
    // then output the digits

        out << num.whole;
    if (num.point) out<<'.';
    out<<num.fraction;
    return out;
}
//*********************************************************************************************************
