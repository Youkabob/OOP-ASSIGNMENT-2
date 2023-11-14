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
        //0x11 0x22 it takes the "11"
        value = value.substr(2,2);
        //it takes "22"
        memory.setslot(address,value);
    }
}
void Machine::displaystatus() {
    cout<<"The following list contains the 16 register: "<<endl;
    ins.displayregister();
    cout<<"the following list includes the 256 memory slots: "<<endl;
    memory.displaymemory();
}
