#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number: \n";
    cin >> n;
    bool is_Prime[n + 1];  // A boolean array to store primality

    for (int i = 0; i <= n; ++i) {              // Initialize all numbers as prime
        is_Prime[i] = true;
    }

    is_Prime[0] = is_Prime[1] = false;  // excluding 0 and 1


    for (int p = 2; p * p <= n; ++p) {          // applying the algorithm
        if (is_Prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_Prime[i] = false;
            }
        }
    }


    for (int i = 2; i <= n; ++i) {           // Printing prime numbers only
        if (is_Prime[i]) {
            cout << i << " ";
        }
    }
}
