/*
 File: A2_S6_20221025_8.cpp
 Purpose: Fractal Pattern
 Author: alaa wael mohamed
 Section: s6
 ID: 20221025
 TA:  TA: Nardeen Mokhless Khela - Maya Ahmed
 Date: 12 Oct 2023
 */

#include <iostream>
using namespace std;
class pattern_cl {
public:
    static void pattern(int n, int i) {
        if (i == 0) return;
        // upper part
        pattern(n, i / 2);

        for (int j = 0; j < n; j++) cout << "  ";
        for (int j = 0; j < i; j++) cout << "* ";// Center
        cout << endl;
        // lower part
        pattern(n + i / 2, i / 2);
    }
};

int main()
{
    int n;
    cout << "Enter n (a power of 2):";   cin >> n;
    pattern_cl::pattern(0,n);
}
