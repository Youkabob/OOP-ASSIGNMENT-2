//
// Created by lolow on 10/30/2023.
//

#ifndef A2_TASK2_S6_20221025_BIGREAL_H
#define A2_TASK2_S6_20221025_BIGREAL_H

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class BigReal{
    friend ostream& operator<<(ostream& out,const BigReal& bigint);
public:
    BigReal (double realNumber=0.0); // Default constructor
    BigReal (string realNumber); // Initialize from string
    BigReal (const BigReal &other);//copy constructor
    BigReal& operator= (const BigReal &num);// Assignment operator

    char getSign() const;
    void setSign(char Sign);
    int size() const;

private:
    string number;
   deque<char> whole;
    string fraction="";
    char sign;  // to store the sign
    bool isValidReal (); // True if correct real
    static void matchSize(BigReal& LHS,BigReal& RHS);
};

#endif //A2_TASK2_S6_20221025_BIGREAL_H