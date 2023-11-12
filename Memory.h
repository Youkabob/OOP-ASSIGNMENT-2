#include "bits/stdc++.h"
using namespace std;

#ifndef MACHINE_SIMULATOR_YOUKA_MEMORY_H
#define MACHINE_SIMULATOR_YOUKA_MEMORY_H
class Memory{
private:
    string slots[256];
public:
string getslot(string& address);

void setslot(string& address,string value);

};
#endif //MACHINE_SIMULATOR_YOUKA_MEMORY_H
