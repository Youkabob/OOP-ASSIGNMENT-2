#include <iostream>
#include "bits/stdc++.h"
using namespace std;
static  bool bears(int n){
    if(n%2==0&&bears(n/2)){
        return true;
    }
    if((n%3==0||n%4==0)&&bears(n-((n%10)*((n % 100) / 10)))) {
        return true;
    }
    if(n%5==0&&bears(n-42)) {
        return true;
    }
    if(n==42){
        return true;

    }
    else{
        return false;
    }
}
int main() {
int n;
cin>>n;
    cout<<bears(n);
}
