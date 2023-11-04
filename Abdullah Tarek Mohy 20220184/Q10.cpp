#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
int main() {
    const string inputFileName = "input.txt";
    const string outputFileName = "output.txt";
    map<string, string> wordReplacements;
    ifstream lookupFile("lookup_table.txt");
    if (!lookupFile.is_open()) {
        cerr << "Failed to open lookup table file." << endl;   // printing error if look up table file cannot be opened 
        return 1;                                              // (note: must be in cmake build debug if using clion)
    }

    string line;
    while (getline(lookupFile, line)) {   // declaring kewwords and alteernative by using spaces
        size_t spacePos = line.find(' ');
        if (spacePos != string::npos) {
            string word = line.substr(0, spacePos);
            string alternative = line.substr(spacePos + 1);
            wordReplacements[word] = alternative;
        }
    }
    lookupFile.close();

    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {                       
        cerr << "Failed to open input file." << endl;   // printing error if input table file cannot be opened
        return 1;
    }
    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        cerr << "Failed to create output file." << endl;   // printing error if output table file cannot be opened
        return 1;
    }
    string word;
    while (inputFile >> word) {                // replacing the word if it exist in the map with its alternatives
        auto it = wordReplacements.find(word);
        if (it != wordReplacements.end()) {
            outputFile << it->second << " ";
        } else {
            outputFile << word << " ";
        }
    }
    inputFile.close();
    outputFile.close();
    cout << "Message alteration completed. The result is in 'output.txt'." << endl;
    return 0;
}