#include <bits/stdc++.h>
#include <cctype>
using namespace std;

int main() {
    string sent ;
    cout<<"enter the sentence (up to 100 characters): \n";
    getline(cin,sent); //getting the whole line as a input

    bool newWord = true;
    string newSent = "";
    
    for(char c: sent) {       //editng the sentence
        if (isalpha(c)) {
            c = tolower(c);
            newWord=false;
        }
        if (isspace(c)){
            if (!newWord){
                newSent +=' ';
                newWord = true;
            }
        }
        else
            newSent += c;

    }

newSent[0]= toupper(newSent[0]); //making the first charachter capital

cout<<newSent;
}
