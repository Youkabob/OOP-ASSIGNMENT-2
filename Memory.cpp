#include "bits/stdc++.h"
#include"Memory.h"
using namespace std;
void Memory::setslot(std::string &address, std::string value) {
    int idx=stoi(address, nullptr,16);
    slots[idx]=value;
}
string Memory::getslot(std::string &address) {
 int idx=stoi(address, nullptr,16);
 return slots[idx];
}
