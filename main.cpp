#include <iostream>
#include "bits/stdc++.h"

using namespace std;
#include "Machine.h"
#include "Instructions.h"
#include "Memory.h"
int main() {
    Machine m("input.txt");
    m.run();
    m.displaystatus();
}
