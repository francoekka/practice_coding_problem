/*
https://leetcode.com/problems/online-stock-span/
7
100 80 60 70 60 75 85
output:
1 1 1 2 1 4 6 
*/

#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &v){

    vector<int>result;
    stack<pair<int,int>> s;

    for(int i=0; i<v.size(); i++){
        if(s.empty()){
            result.push_back(i+1);
            s.push({v[i],i});
        }
        else{
            while(v[i]>=s.top().first){
                s.pop();
                if(s.empty()){
                    result.push_back(i+1);
                }
            }
            if(v[i]<s.top().first){
                result.push_back(i-s.top().second);
                s.push({v[i],i});
            }
        }
    }

    for(auto x:result){
        cout<<x<<" ";
    }
}

int main(){
    int n,temp;
    vector<int> v;
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>temp;
        v.push_back(temp);
    }

    solve(v);
}