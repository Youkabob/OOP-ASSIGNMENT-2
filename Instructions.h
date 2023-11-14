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
    Instructions(){
        fill(registers,registers+16,"00");
    }
    void loadregister(string  &address,string value);

    string getregister(string  &address);

    string fetch(string &address,Memory& memory);

    void excute(string &instruction,Memory &memory,string &address);

    void start(string &counter, Memory &memory);

    void first_op(string &instruction,Memory &memory);

    void second_op(string &instruction);

    void third_op(string &instruction,Memory &memory);

    void fourth_op(string &instruction);

    void fifth_op(string &instruction);

    string jump_op(string &instruction);

    void displayregister();
};
#endif //MACHINE_SIMULATOR_YOUKA_INSTRUCTIONS_H
