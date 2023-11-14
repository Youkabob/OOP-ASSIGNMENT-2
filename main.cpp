#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "bits/stdc++.h"

using namespace std;
class Memory {
private:
    int index;
    bool used;
    string add;
    string value;

public:
    string get_val();
    int get_index();

    Memory();
    Memory(string addresses,int pc);
    void set_add(string address, string data);
};

Memory::Memory(string addresses,int pc) {
    value = '0';
    index=pc;
    add = "0";
    used = 0;
}

Memory::Memory() {
    value = '0';
    add = "0";
    used = 0;
    index=0;
}

void Memory::set_add(string address, string data) {
    used = 1;
    value = data;
    add = address;
}

string Memory::get_val() {
    if (used) {
        return value;
    }
    return "0";
}

int Memory::get_index() {
    if (used) {
        return index;
    }
    return 0;
}


class Instruction  {
protected:
    char operation;
    string registers[23];
    string addressIstruction;

public:
    string code;
    Instruction();
    Instruction(string s);
    void loadregister(int reg, string value);
    string changeAddress(const string &address, int x);
    string getregister(int idx);

    void excute(Memory &memory, Instruction &pc);

    void first_op(int reg, Memory &memory);
    void second_op(int reg, string val);
    void third_op(int reg,Memory &memory);
    void fifth_op(int reg1,int reg2,int reg3);
    void fourth_op(int reg1, int reg2);
    string jump_op(int compared_r,string mem);
};

void Instruction::loadregister(int reg, string value) {
    registers[reg] = value;
}

string Instruction::getregister(int idx) {
    return registers[idx];
}

void Instruction::excute(Memory &memory, Instruction &pc) {
    char op = operation;
    if (op == '1') {
        first_op(code[1] - '0', memory);
    }

    if (op == '2') {
        second_op(code[1] - '0', code.substr(2));
    }
    if(op=='3'){
        third_op(code[1]-'0',memory);
    }

    if (op == '4') {
        fourth_op(code[2] - '0', code[3] - '0');
    }
    if (op=='5'){
        fifth_op(code[1]-'0',code[2]-'0',code[3]-'0');
    }
    if (op=='B'){
        string s=jump_op(code[1]-'0',code.substr(2));
        int cnt=0;
        if(s != ""){

        }


    }


}

string Instruction::changeAddress(const string &address, int x) {
    int Address= stoi(address, nullptr,16);
    stringstream ss;
    ss << hex << Address + x;//converts to integer then adds "x" then converts to hex then to string
    string s = ss.str();
    if (s.size() == 1)
        s = "0" + s;//if s="6" for example we will store it "06"
    return s;
}
Instruction::Instruction(string s) {
    code = s;
    operation = s[0];
    registers[s[1] - '0'] = '0';
    addressIstruction = s.substr(2);
}

Instruction::Instruction() {
    code = "0";
    operation = '0';
    registers[0] = '0';
    addressIstruction = "0";
}

void Instruction::first_op(int reg, Memory &memory) {

    loadregister(reg, memory.get_val());


}

void Instruction::second_op(int reg, string val) {
    loadregister(reg, val);
}

void Instruction::third_op(int reg,Memory &memory) {
    string address = code.substr(2);

    if (address == "00") {
        cout << memory.get_val();  // Print the value at memory address "00"
    } else {
        string value = getregister(reg);
        memory.set_add(address, value);
    }
}

void Instruction::fourth_op(int reg1, int reg2) {
    loadregister(reg2, getregister(reg1));
}

void Instruction::fifth_op(int reg1,int reg2,int reg3) {
        string num2 = getregister(reg2);
        string num3 = getregister(reg3);

        int n2 = stoi(num2, nullptr, 16);
        int n3 = stoi(num3, nullptr, 16);

        int sum = n3 + n2;

        stringstream result;
        result << hex << sum;
        string res = result.str();
        if (res.size() == 1)
            res = "0" + res;

        loadregister(reg1, res);
    }

string Instruction::jump_op(int compared_r,string mem) {

    string reg1 = getregister(compared_r);
    string reg0 = getregister(0);

    if (reg1 == reg0) {
        string target_address = mem;
        return target_address;
    } else return "";

}
class Machine{
private:
    vector<Memory> memory;
    vector<Instruction> ins;
    string fileName;
    int pc;

public:
    void loadprog();
    void displayMemory(); // Add this line
    Machine(string &filename);
    void run();
};

Machine::Machine(string &name) {
    pc = 0;
    fileName = name;
    this->loadprog();
}

void Machine::run() {
    while (ins[pc].code!="C000") {
        ins[pc].excute(memory[pc], ins[pc]);
        pc++;
    }
}

void Machine::loadprog() {
    ifstream file;
    file.open("tsk3.txt");
    if (!file.is_open())
        cout << "error";
    int cnt=0;
    string line;
    string addCode = "", instructionCode = "";
    int in = 0, ad = 0;
    while (getline(file, line)) {
        for (int i = 2; i < 4; ++i) {
            if (ad == 0 || (ad == 1 && in == 1)) {
                ad++;
                addCode += line[i];
                addCode += line[i + 1];
                i++;
            } else
                break;
        }
        for (int i = 7; i < 9; ++i) {
            if (in == 0 || (ad == 2 && in == 1)) {
                in++;
                instructionCode += line[i];
                instructionCode += line[i + 1];
                i++;
            } else
                break;
        }
        Memory tem2(addCode,pc/2);
        memory.push_back(tem2);
        addCode = "";
        if (ad == in && in == 2) {
            ad = 0, in = 0;
            Instruction tem(instructionCode);
            ins.push_back(tem);
            instructionCode = "";
        }
    }
    file.close();
}

void Machine::displayMemory() {
    cout << "\nMemory Content:\n";

    cout << ins[pc].getregister(3) << " ";
}

int main() {
    cout << "Welcome to the Virtual Machine!\n";

    cout << "1. LOAD a value from memory\n"
         << "2. LOAD register with a bit pattern \n"
         << "3. STORE the bit pattern found in a register in a memory cell\n"
         << "4. MOVE the bit pattern found in a register to another register\n"
         << "5. ADD the bit patterns of two registers and put the result in a third one\n"
         << "B. make a condition and JUMP to the instruction located in the memory cell \n"
         << "C. Exit\n";

    string filename;
    cout << "Enter the filename of the program: ";
    cin >> filename;

    Machine virtualMachine(filename);

    // Run the virtual
    virtualMachine.run();
}