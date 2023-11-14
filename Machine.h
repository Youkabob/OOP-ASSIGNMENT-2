#include "bits/stdc++.h"
using namespace std;

#ifndef MACHINE_SIMULATOR_YOUKA_MACHINE_H
#define MACHINE_SIMULATOR_YOUKA_MACHINE_H
#include "Memory.h"
#include "Instructions.h"
class Machine{
private:
    Memory memory;
    Instructions ins;
    string fileName;
public:
    Machine(string filename);

    void loadprog();

    void run();
    void displaystatus();
};
#endif //MACHINE_SIMULATOR_YOUKA_MACHINE_H


