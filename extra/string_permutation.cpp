#include<iostream>
#include<string>
using namespace std;

string swapit(string s,int a, int b){
    char temp = s[a];
    s[a] = s[b];
    s[b] = temp;
    return s;
}

void permute(string s, int low, int high){
    if(low==high){
        cout<<s<<" ";
        return;
    }
    for(int i=low;i<=high;i++){
        s = swapit(s,low,i);
        permute(s,low+1,high);
        s = swapit(s,low,i);
    }
}

int main(){
    string s = "ABC";
    int n=3;
    permute(s,0,n-1);
}