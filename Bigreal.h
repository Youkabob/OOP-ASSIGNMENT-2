//
// Created by lolow on 10/30/2023.
//

#ifndef A2_TASK2_S6_20221025_BIGREAL_H
#define A2_TASK2_S6_20221025_BIGREAL_H

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class BigReal {
    friend ostream& operator << (ostream& out, BigReal num);
public:
    BigReal(double realNumber = 0.0); // Default constructor

    BigReal(string realNumber); // Initialize from string

    BigReal(const BigReal &other);//copy constructor
    BigReal &operator=(const BigReal &num);// Assignment operator

    BigReal operator+(BigReal &other);

    char getSign() const;


private:
    string fraction;
    string whole;
    bool point;
    char sign;  // to store the sign
    int Size;

    bool isValidReal(string number); // True if correct real
    static void matchwholeSize(BigReal &LHS, BigReal &RHS);

    static void matchFractionSize(string &LHS, string &RHS);

    string setFraction(const string &number);

    string setWhole(const string &number);

    char setSign(char Sign);
};

#endif //A2_TASK2_S6_20221025_BIGREAL_H