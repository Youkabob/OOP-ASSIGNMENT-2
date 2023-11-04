#include "bits/stdc++.h"
using namespace std;
map<string,int>val;
void initial(){
    val["amazon"]=2;
    val["official"]=2;
    val["bank"]=1;
    val["security"]=1;
    val["urgent"]=1;
    val["alert"]=1;
    val["important"]=1;
    val["information"]=2;
    val["ebay"]=3;
    val["password"]=3;
    val["credit"]=3;
    val["verify"]=1;
    val["confirm"]=1;
    val["account"]=1;
    val["bill"]=1;
    val["immediately"]=1;
    val["address"]=2;
    val["telephone"]=2;
    val["ssn"]=3;
    val["charity"]=2;
    val["check"]=1;
    val["secure"]=1;
    val["personal"]=1;
    val["confidential"]=1;
    val["atm"]=2;
    val["warning"]=2;
    val["fraud"]=2;
    val["citibank"]=2;
    val["irs"]=2;
    val["paypal"]=1;
}

int main()
{
    int value=0;
    initial();
    char line[100];
    map<string,int>counting;
    ifstream Myfile;
    Myfile.open("Email.txt");
    while(!Myfile.eof()){
        Myfile.getline(line,100);
        string s;
        Myfile>>s;
        for (int i = 0; i < strlen(line); ++i) {
            if (line[i] == ' ') {
                if (val[s] != 0) {
                    counting[s]++;
                    value += val[s];

                }
                s.clear();
            }
                else{
                    s+= tolower(line[i]);
                }

        }
        if(val[s]!=0){
            counting[s]++;
            value+=val[s];
        }

    }
    Myfile.close();
    for(auto&it:counting){
        cout<<it.first<<" Repeated "<<it.second<<" time(S) , spamscore -> "<<it.second*val[it.first]<<'\n';
    }
    cout<<endl;
    cout<<"Total Score: "<<value;


}
