#include <iostream>
#include "bits/stdc++.h"
using namespace std;
string s,m;
int l=1;
static void binaryPrint(int n){
    if(n==0&&l==1){
        m="0";
        cout<<m;
        return;
    }
    if(n==0&&l==0){
        reverse(s.begin(),s.end());
        cout<<s;
    }
else {
    l=0;
        s += to_string(n % 2);

        binaryPrint(n / 2);

    }
}static void numbers(string prefix,int x){
     if(x==0){
         cout<<prefix<<endl;
         return;
     }
     else{
         for (int i = 0; i <= 1; ++i) {
             numbers(prefix+ to_string(i),x-1);
         }
     }


}
int main() {
  string prefix;
  int j;
  cin>>prefix>>j;
    numbers(prefix,j);
}
