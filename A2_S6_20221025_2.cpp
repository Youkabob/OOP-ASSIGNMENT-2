/*
File: A2_S6_20221025_2.cpp
 Purpose: converts male speech to inclusive speech that includes both male and female
 Author: alaa wael mohamed
 Section: s6
 ID: 20221025
 TA: Nardeen Mokhless Khela - Maya Ahmed
 Date: 12 Oct 2023
 */

#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() {
    string input, tem = "";
    set<std::string> s = {"him", "Him", "his", "His", "he", "He"};
    cout << "Enter your statement: ";
    getline(std::cin, input);
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == ' ') {
            tem = "";// Clear the temporary word
            continue;
        }
        tem += input[i];
        // Check for specific conditions to replace male-oriented words
        if (s.count(tem)) {
            if (tem == "his" && (i == input.size() - 1 || input[i + 1] == ' '||input[i + 1] == '?'||input[i + 1] == ',')) {
                input.replace(i - 2, 3, "his or hers");
                i += 8;
            } else if (tem == "His" && (i == input.size() - 1 || input[i + 1] == ' '||input[i + 1] == '?'||input[i + 1] == ',')) {
                input.replace(i - 2, 3, "His or hers");
                i += 8;
            } else if (tem == "him" && (i == input.size() - 1 || input[i + 1] == ' '||input[i + 1] == '?'||input[i + 1] == ',')) {
                input.replace(i - 2, 3, "him or her");
                i += 8;
            } else if (tem == "He" && (i == input.size() - 1 || input[i + 1] == ' '||input[i + 1] == '?'||input[i + 1] == ',')) {
                input.replace(i - 1, 2, "He or she");
                i += 8;
            }
            else if (tem == "he" && (i == input.size() - 1 || input[i + 1] == ' '||input[i + 1] == '?'||input[i + 1] == ',')) {
                input.replace(i - 1, 2, "he or she");
                i += 8;
            }
            else if (tem == "Him" && (i == input.size() - 1 || input[i + 1] == ' ')) {
                input.replace(i - 2, 3, "Him or her");
                i += 8;
            }
            tem = "";// Clear the temporary word
        }
    }
    cout << input;
}
