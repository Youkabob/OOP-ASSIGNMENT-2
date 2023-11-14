#include "bits/stdc++.h"
#include "Instructions.h"
#include "Memory.h"
#include "Machine.h"

using namespace std;
string Instructions::changeAddress(const string &address, int x) {
    int Address= stoi(address, nullptr,16);
    stringstream ss;
    ss << hex << Address + x;//converts to integer then adds "x" then converts to hex then to string
    string s = ss.str();
    if (s.size() == 1)
        s = "0" + s;//if s="6" for example we will store it "06"
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
    if(op=='2'){
        second_op(instruction);
        address= changeAddress(address,2);
    }
    if(op=='3'){
        third_op(instruction,memory);
        address= changeAddress(address,2);
    }
    if(op=='4'){
        fourth_op(instruction);
        address= changeAddress(address,2);
    }
    if(op=='5'){
        fifth_op(instruction);
        address= changeAddress(address,2);
    }
    if(op=='B'||op=='b'){
        if(jump_op(instruction) == "")
            address = changeAddress(address, 2);
        else
            address = jump_op(instruction);
    }
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
void Instructions::second_op(std::string &instruction) {
    string value = instruction.substr(2,2);
    string registerIndex = instruction.substr(1,1);
    loadregister(registerIndex,value);
}
void Instructions::fourth_op(string &instruction) {
    string reg1Index = instruction.substr(2,1);
    string reg2Index = instruction.substr(3,1);
    loadregister(reg2Index, getregister(reg1Index));
}
void Instructions::fifth_op(string &instruction) {

    string reg1 = instruction.substr(2,1);
    string reg2 = instruction.substr(3,1);
    string target_register = instruction.substr(1,1);

    string num1 = getregister(reg1);
    string num2 = getregister(reg2);

    int n1 = stoi(num1, nullptr, 16);
    int n2 = stoi(num2, nullptr, 16);

    int sum = n1 + n2;

    stringstream result;
    result << hex << sum;
    string res = result.str();
    if(res.size() == 1)
        res = "0" + res;
    loadregister(target_register,res);
}
string Instructions::jump_op(std::string &instruction) {

    string reg1 = instruction.substr(1, 1);
    string reg0 = registers[0];

    if (getregister(reg1) == reg0) {
        string target_address = instruction.substr(2, 2);
        return target_address;
    } else return "";

}
void Instructions::third_op(string &instruction,Memory &memory) {
    string address= instruction.substr(2,2);
    string reg=instruction.substr(1,1);
    if(address=="00"){
        cout<<getregister(reg)<<endl;
    }
    else{
    string value= getregister(reg);
    memory.setslot(address,value);
    }
}
void Instructions::displayregister() {
    for (int i = 0; i < 16; i++) {
        stringstream ss;
        ss<<hex<<i;
        string hex=ss.str();
        cout<<"Register "<<hex<<" = "<<registers[i]<<endl;
    }
}
