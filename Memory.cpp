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
void Memory::displaymemory() {
    cout << "   ";
    for (int i = 0; i < 16; ++i) {
        stringstream ss;
        ss << hex << i;

        string hex = ss.str();

        if (isalpha(hex.front())) {//if it is a char print uppercase
            hex[0] = toupper(hex[0]);
        }
        hex+="0"; //make it like A0

        cout << hex << ' ';
    }
    cout << '\n';
    for (int i = 0; i < 16; ++i) {
        stringstream ss;
        ss << hex << i;

        string hex = ss.str();

        if (isalpha(hex.front())) {
            hex[0] = toupper(hex[0]);
        }

        if (hex.size() == 1) {
            hex = "0" + hex;
        }
        cout << hex << ' ';
        for (int j = 0; j < 16; ++j) {
            cout << slots[(i*16) + j] << ' '; //checks every address if i=0 j=1 slots[1] , if i=1 j=2 slots[18] like that
        }
        cout << '\n';
    }
}

