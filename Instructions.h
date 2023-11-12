#include "bits/stdc++.h"
#include "Memory.h"
using namespace std;

#ifndef MACHINE_SIMULATOR_YOUKA_INSTRUCTIONS_H
#define MACHINE_SIMULATOR_YOUKA_INSTRUCTIONS_H
class Instructions{
private:
    string registers[16];
private:
 string changeAddress(const string&address,int x);
public:
    void loadregister(string  &address,string value);

    string getregister(string  &address);

    string fetch(string &address,Memory& memory);

    void excute(string &instruction,Memory &memory,string &address);

    void start(string &counter, Memory &memory);
    void first_op(string &instruction,Memory &memory);
};
#endif //MACHINE_SIMULATOR_YOUKA_INSTRUCTIONS_H
