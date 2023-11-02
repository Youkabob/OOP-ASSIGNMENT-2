//
// Created by alaa wael on 10/30/2023.
//
#include <bits/stdc++.h>
#include "Bigreal.h"
#include <iostream>
#include <regex>
using namespace std;

//***************************** checking validity *****************************************************
bool BigReal ::isValidReal (string number){
    if (count(number.begin(), number.end(),'.')>1||
        count(number.begin(), number.end(),' ')>0||number[1]=='+'||number[1]=='-') {
        cout<<"not valid number!\n";
        return 0;
    }
    return 1;
}

//***************************** default constructor *****************************************************
BigReal::BigReal(double realNumber) {
    // Initialize your BigReal object based on the double input
    // You will need to implement this part according to your requirements.
    // You can extract the whole and fraction parts from the double.

    // For example, if you want to initialize it to 0.0 by default:
    whole = "";
    fraction = "";
    sign = '+';
    point = 1;
    Size = 0;
}



//***************************** assign number *********************************************************
BigReal ::BigReal(string realNumber) {
    if (isValidReal(realNumber)) {
        whole = setWhole(realNumber);
        fraction = setFraction(realNumber);
        sign = setSign(realNumber[0]);
        Size = realNumber.size() - 2;
    } else {
        whole = "";
        fraction = "";
        sign = '+';
        Size = 0;
        point = 0;
    }
}

//***************************** whole setter *********************************************************
string BigReal::setWhole(const string &number) {
    string wholePart = "";
    for (const char &i: number) {
        if (i == '-' || i == '+') continue;
        if (i == '.') {
            point = 1;
            break;
        }
        wholePart += i;
    }
    return wholePart;
}

//***************************** fraction setter ******************************************************
string BigReal::setFraction(const string &number){
    string fracpart="";
    bool dot=0;
    for (const char& i : number) {
        if (i=='-'||i=='+') continue;
        if(i=='.')
            dot=1;
        else if (dot)
        fracpart+=i;
    }
    point=dot;
    return fracpart;
}

//***************************** sign setter **********************************************************
char BigReal::setSign(char Sign) {
    if(Sign=='-'||Sign=='+') {
        return Sign;
    }
    else
        return '+';
}

//***************************** sign getter **********************************************************
char BigReal::getSign() const {
    return  sign;
}



//***************************** Copy Constructor *****************************************************
BigReal::BigReal(const BigReal &other) {

    sign = other.sign;
    whole = other.whole;
    fraction = other.fraction;
    Size = other.Size;
    point = other.point;

}

//******************************* Assignment "=" Operator ********************************************
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



// ******************************** Addition "+" Operator *******************************************
BigReal BigReal::operator+ ( BigReal& other) {
    BigReal realnum;
    deque<char> result;

    // Ensure the fractions have the same size by padding with zeros
    string lhs = this->fraction, rhs = other.fraction;
    matchFractionSize(lhs, rhs);

    int carry = 0;
    for (int i = lhs.size() - 1; i >= 0; --i) {
        int lhsDigit = lhs[i] - '0';
        int rhsDigit = rhs[i] - '0';
        int sum = lhsDigit + rhsDigit + carry;

        // Handle carry
        if (sum > 9) {
            carry = 1;
            sum %= 10;
        } else {
            carry = 0;
        }

        result.push_front(sum + '0');
    }

    // Set the fraction part of the result
    for (auto &i : result) {
        realnum.fraction.push_back(i);
    }

    result.clear();

    // Now, repeat a similar process for the whole parts
    lhs = this->whole;
    rhs = other.whole;
    matchwholeSize(lhs, rhs);

    for (int i = lhs.size() - 1; i >= 0; --i) {
        int lhsDigit = lhs[i] - '0';
        int rhsDigit = rhs[i] - '0';
        int sum = lhsDigit + rhsDigit + carry;

        if (sum > 9) {
            carry = 1;
            sum %= 10;
        } else {
            carry = 0;
        }

        result.push_front(sum + '0');
    }

    if (carry) {
        result.push_front(carry + '0');
    }

    // Set the whole part of the result
    for (auto &i : result) {
        realnum.whole.push_back(i);
    }

    // Copy other properties
    realnum.Size = this->Size;
    realnum.sign = this->sign;
    realnum.point = this->point;

    return realnum;
}


// ******************************** "<" Operator *******************************************
bool BigReal::operator<(const BigReal& anotherReal)const {

    if (this->sign == '-' && anotherReal.sign == '+')
        return true;
    // if the first number have a positive sign and the second number have negative sign function will return false
    if (this->sign == '+' && anotherReal.sign == '-')
        return false;


    string LHSFraction = this->fraction;
    string RHSFraction = anotherReal.fraction;
    matchFractionSize(LHSFraction, RHSFraction); // add zeros to the right

    if (this->whole == anotherReal.whole) {
        if (this->sign == '-')
            return (LHSFraction > RHSFraction);
        else
            return (LHSFraction < RHSFraction);
    } else {
        return (this->whole < anotherReal.whole);
    }
}

// ******************************** ">" Operator *******************************************
bool BigReal::operator>(const BigReal &anotherReal)const{
    if(this->sign=='-'&&anotherReal.sign=='+')
        return false;
    // if the first number have a positive sign and the second number have negative sign function will return false
    if(this->sign=='+'&&anotherReal.sign=='-')
        return true;

    string LHSFraction = this->fraction;
    string RHSFraction = anotherReal.fraction;
    matchFractionSize(LHSFraction,RHSFraction);

    if(this->whole==anotherReal.whole){
        if(this->sign=='-')
            return (LHSFraction < RHSFraction);
        else
            return (LHSFraction > RHSFraction);
    }
    else
        return (this->whole>anotherReal.whole);
}
// ******************************** "==" Operator *******************************************
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



void BigReal::matchwholeSize(string &lhs, string &rhs){
    long long diff = abs((int)rhs.size() - (int)lhs.size() );
    string zeros="",result="";
    for(long long i = 0; i < diff; i++){
       zeros.push_back('0');
    }
    if ((int)rhs.size()<(int)lhs.size()){
        result=zeros+rhs;
        rhs=result;
    }
    else{
        result=zeros+lhs;
        lhs=result;
    }
}

void BigReal::matchFractionSize(string &lhs, string &rhs){
    long long diff = abs((long long)lhs.size()-(long long)rhs.size());
    for(long long i = 0; i < diff; i++){
        // add trailing zeros to the shorter number to facilitate operations
        if(rhs.size() > lhs.size()){
            lhs.push_back('0');
        }
        else{
            rhs.push_back('0');
        }
    }
}



ostream& operator<<(ostream &out, BigReal num) {
    // output the sign first
        out << num.sign;
    // then output the digits

        out << num.whole;
    if (num.point) out<<'.';
    out<<num.fraction;
    return out;
}
//*******************************************************************************************************