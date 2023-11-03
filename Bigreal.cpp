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

//***************************** default constructor **************************************************
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



//***************************** assign number ********************************************************
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
    if (this->sign != other.sign) {
        // Signs are different, perform subtraction
        if (*this>other) {
            BigReal negOther = other;
            negOther.sign = (other.sign == '+') ? '-' : '+';
            realnum = *this - negOther;
        }
        else{
            BigReal negOther = *this;
            negOther.sign = (this->sign == '+') ? '-' : '+';
            realnum = other - negOther;
        }
    }
    else {
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
        for (auto &i: result) {
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
        for (auto &i: result) {
            realnum.whole.push_back(i);
        }

        // Copy other properties
        realnum.Size = this->Size;
        realnum.sign = this->sign;
        realnum.point = this->point;
    }
    return realnum;
}

// ******************************** Subtraction "-" Operator *******************************************
BigReal BigReal::operator- (const BigReal& other) {
    BigReal result;
    if(this->sign==other.sign) {
    if (this->whole == other.whole) {
        if(this->fraction==other.fraction){
            result.sign=' ';
            result.whole="0";
            result.fraction='0';
            return result;
        }
    }
}
    if (this->sign != other.sign) {
        BigReal negOther = other;
        negOther.sign = (other.sign == '+') ? '-' : '+';
        result = *this + negOther;
    } else {
        if (*this < other) {
            BigReal temp = other;
            result = temp - *this;
            result.sign = (this->sign == '+') ? '-' : '+';
            return result;
        }

        string lhs = this->fraction, rhs = other.fraction;
        matchFractionSize(lhs, rhs);

        int borrow = 0;
        deque<char> diff;
        for (int i = lhs.size() - 1; i >= 0; --i) {
            int lhsDigit = lhs[i] - '0' - borrow;
            int rhsDigit = rhs[i] - '0';
            if (lhsDigit < 0) {
                lhsDigit += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            int digitDiff = lhsDigit - rhsDigit;
            if (digitDiff < 0) {
                digitDiff += 10;
                borrow = 1;
            }
            diff.push_front(digitDiff + '0');
        }

        for (auto &i : diff) {
            result.fraction.push_back(i);
        }

        diff.clear();

        std::string lhsWhole = this->whole, rhsWhole = other.whole;
        matchwholeSize(lhsWhole, rhsWhole);

        for (int i = lhsWhole.size() - 1; i >= 0; --i) {
            int lhsDigit = lhsWhole[i] - '0' - borrow;
            int rhsDigit = rhsWhole[i] - '0';
            if (lhsDigit < 0) {
                lhsDigit += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            int digitDiff = lhsDigit - rhsDigit;
            if (digitDiff < 0) {
                digitDiff += 10;
                borrow = 1;
            }
            diff.push_front(digitDiff + '0');
        }

        for (auto &i : diff) {
            result.whole.push_back(i);
        }

        result.removeLeadingZeros();
        result.Size = result.whole.size() + result.fraction.size();
        result.point = !result.fraction.empty();
        result.sign = this->sign;
    }

    return result;
}

// ******************************** "<" Operator ****************************************************
bool BigReal::operator<(const BigReal& anotherReal)const {

    if (this->sign == '-' && anotherReal.sign == '+')
        return true;
    // if the first number have a positive sign and the second number have negative sign function will return false
    if (this->sign == '+' && anotherReal.sign == '-')
        return false;


    string LHSwhol = this->whole;
    string RHSwhole = anotherReal.whole;
    matchwholeSize(LHSwhol, RHSwhole); // add zeros to the right

    if (this->whole == anotherReal.whole) {
        string LHSfraction = this->fraction;
        string RHSfraction = anotherReal.fraction;
        matchFractionSize(LHSfraction, RHSfraction); // add zeros to the right

        if (this->sign == '-')
            return (LHSfraction > RHSfraction);
        else
            return (LHSfraction < RHSfraction);
    } else {
        if (this->sign == '-')
        return (this->whole > anotherReal.whole);
        else   return (this->whole < anotherReal.whole);

    }
}

// ******************************** ">" Operator ****************************************************
bool BigReal::operator>(const BigReal &anotherReal)const{
    if(this->sign=='-'&&anotherReal.sign=='+')
        return false;
    // if the first number have a positive sign and the second number have negative sign function will return false
    if(this->sign=='+'&&anotherReal.sign=='-')
        return true;


    string LHSwhol = this->whole;
    string RHSwhole = anotherReal.whole;
    matchwholeSize(LHSwhol, RHSwhole); // add zeros to the right

    if (this->whole == anotherReal.whole) {
        string LHSfraction = this->fraction;
        string RHSfraction = anotherReal.fraction;
        matchFractionSize(LHSfraction, RHSfraction); // add zeros to the right

        if (this->sign == '-')
            return (LHSfraction < RHSfraction);
        else
            return (LHSfraction > RHSfraction);
    } else {
        if (this->sign == '-')
            return (this->whole < anotherReal.whole);
        else   return (this->whole > anotherReal.whole);

    }
}

// ******************************** "==" Operator ***************************************************
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

void BigReal::removeLeadingZeros() {
    while (!fraction.empty() && fraction.front() == '0') {
        fraction.erase(fraction.begin());
    }
    if (fraction.empty()) {
        point = false;
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
