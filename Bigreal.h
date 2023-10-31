//
// Created by lolow on 10/30/2023.
//

#ifndef A2_TASK2_S6_20221025_BIGREAL_H
#define A2_TASK2_S6_20221025_BIGREAL_H

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class BigReal{
    friend ostream& operator << (ostream& out,const BigReal& num);
public:
    BigReal(const BigReal &&other);
    BigReal (string realNumber);
    BigReal (double realNumber = 0.0);
    BigReal (const string &realNumber);
    BigReal (const BigReal& other);
    int size()const;
    char Sign()const;

    //    BigReal (const BigReal& other);
//    BigReal& operator= (const BigReal& other);
//    BigReal (const BigReal&& other);
//    BigReal& operator= (const BigReal&& other);
//
//
    BigReal operator+ (const BigReal& other)const;
//
//    int size()const;
//    char sign()const;

private:
    string number,
    whole="";
    string fraction="";
    char sign;  // to store the sign
    void setFraction(const string &number);
    void setWhole(const string &number);
};

#endif //A2_TASK2_S6_20221025_BIGREAL_H