#include<bits/stdc++.h>
using namespace std;

bool ispallindrome(string s,int i,int j){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        else{
            i++;
            j--;
        }
    }
    return true;
}

int pallindrome_part(string s,int i,int j){
    if(i==j || ispallindrome(s,i,j)){
        return 0;
    }
    int mn = INT_MAX;
    for(int k=i;k<j;k++){
        int temp = 1+ pallindrome_part(s,i,k)+pallindrome_part(s,k+1,j);
        mn = min(temp,mn);
    }
    return mn;
}

int main(){
    string s;
    getline(cin,s);
    cout<<pallindrome_part(s,0,s.length()-1);
}