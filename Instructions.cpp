#include "bits/stdc++.h"
#include "Instructions.h"
#define isOn(n,k) (((n) >> (k)) & 1)
using namespace std;
string Instructions::changeAddress(const string &address, int x) {
    int Address= stoi(address, nullptr,16);
    stringstream ss;
    ss << hex << Address + x;
    string s = ss.str();
    if (s.size() == 1)
        s = "0" + s;
    return s;
}
void Instructions::loadregister(string &address, string value) {
    int idx = stoi(address, nullptr, 16);//convert to integer base hexadecimal
    registers[idx] = value;
}
string Instructions::getregister(string &address) {
    int idx = stoi(address, nullptr, 16);
   return registers[idx];
}
string Instructions::fetch(string &address, Memory &memory) {
    string ins = memory.getslot((string &)address);
    string s = changeAddress(address,1);
    ins += memory.getslot((string &) s);
    return ins;
}
void Instructions::excute(std::string &instruction, Memory &memory, string &address) {
    char op=instruction[0];
    if(op=='1'){
        first_op(instruction,memory);
        address= changeAddress(address,2);
    }
    if(op=='2'){}
    if(op=='3'){}
    if(op=='4'){}
    if(op=='5'){}
    if(op=='B'||op=='b'){}
}
void Instructions::start(string &counter, Memory &memory) {
string address=counter;
string instruction= fetch(address,memory);
while(instruction!="C000"){
    excute(instruction,memory,address);
    instruction=fetch(address,memory);
}
}
void Instructions::first_op(std::string &instruction, Memory &memory) {
    //0x11 0x13
    //0x12 0x24
    string memoryIndex = instruction.substr(2,2);
    //he takes the memory index "24"
    string registerIndex = instruction.substr(1,1);
    //he takes the register index "3"
    string value = memory.getslot(memoryIndex);
    //he gets the value inside the memory slot and stores it in the register
    loadregister(registerIndex, value);
}