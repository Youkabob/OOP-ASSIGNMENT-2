#include <iostream>
#include "bits/stdc++.h"
using namespace std;
vector<string>v;
vector<int>index;
int l=0;
string s;
char k;
vector<string>split(string target,string delimiter){
    for (int i = 0; i < delimiter.size(); ++i) {
        k=delimiter[i];
    }
    for (int i = 0; i < target.size(); ++i) {
        if(target[i]==k){
            index.push_back(i);
        }
    }
    for (int i = 0; i <= index.size(); ++i) {
        if(i!=0) {s = target.substr(l, index[i] - index[i - 1] - 1);
        }
        else{
            s = target.substr(l, index[i]);
        }
        v.push_back(s);
        l=index[i]+1;
    }
    return v;
}
int main() {
string m;
string d;
    getline(cin,m);
getline(cin,d);
split(m,d);
    for (int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<" ";
    }
}

