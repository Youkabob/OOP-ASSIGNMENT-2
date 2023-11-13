#include "Machine.h"

Machine::Machine(std::string name) {
    fileName = name;
    this->loadprog();
}

void Machine::run()
{
    string initialCounter;
    cout << "Enter the initial value of the program counter: ";
    cin >> initialCounter;

    ins.start(initialCounter, memory);
}

void Machine::loadprog() {
    ifstream file;
    file.open(fileName);
    while (!file.eof()) {
        string address, value;
        file >> address >> value;
        address = address.substr(2,2);
        value = value.substr(2,2);
        memory.setslot(address,value);
    }
}
