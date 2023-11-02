#include <bits/stdc++.h>
#include "Bigreal.h"
#include "Bigreal.cpp"
using namespace std;

int main() {
    string s1, s2;
    start:

    cout << "enter the first number: ";
    cin >> s1;
    BigReal num1(s1);
    cout << "\nenter the second number: ";
    cin >> s2;
    BigReal num2(s2);

    cout << "num 1 : " << num1 << "\n";
    cout << "num 2 : " << num2 << "\n";

    BigReal num3 = num1 + num2;
    cout << "num 1 + num 2 = " << num3 << '\n';

    if (num1 == num2)
        cout << "num1 = num2\n";
    else if (num1 > num2)
        cout << "num1 > num2\n";
    else
        cout << "num1 < num2\n";

    // repeat window
    choose:
    cout << "do you want to exit ? (y/n) : ";
    char c;
    cin >> c;

    if (c == 'y')
        exit(0);
    else if (c == 'n')
        goto start;
    else {
        cout << "invalid input please try again!\n";
        goto choose;
    }
}
