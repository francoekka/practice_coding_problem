#include<iostream>
#include<string>
using namespace std;

void powerset(string s,int i,string res){
    if(i==s.length()){
        cout<<res<<" ";
        return;
    }

    powerset(s,i+1,res+s[i]);
    powerset(s,i+1,res);
}

int main(){
    string s = "abc";
    string res = "";
    powerset(s,0,res);
}