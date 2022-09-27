// https://www.geeksforgeeks.org/largest-rectangle-under-histogram/

#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &v){
    vector<int> result1;
    vector<int> result2;
    vector<int> result;
    stack<pair<int,int>> s;
    stack<pair<int,int>> s2;
    int temp=0;

    for(int i=0;i<v.size();i++){
        if(s.empty()){
            temp = 1;
            s.push({v[i],temp});
        }
        else{
            while(v[i]<=s.top().first){
                temp = temp + s.top().second;
                s.pop();
                if(s.empty()){
                    temp++;
                    s.push({v[i],temp});
                    break;
                }
            }
            if(v[i]>s.top().first){
                temp++;
                s.push({v[i],temp});
            }
        }
        result1.push_back(temp);
        temp=0;
    }

    // for(auto x: result1){
    //     cout<<x<<" ";
    // }
    // cout<<endl;


/////////////////////////////////////////////
     for(int i=v.size()-1;i>=0;i--){
        if(s2.empty()){
            temp = 1;
            s2.push({v[i],temp});
        }
        else{
            while(v[i]<=s2.top().first){
                temp = temp + s2.top().second;
                s2.pop();
                if(s2.empty()){
                    temp++;
                    s2.push({v[i],temp});
                    break;
                }
            }
            if(v[i]>s2.top().first){
                temp++;
                s2.push({v[i],temp});
            }
        }
        result2.push_back(temp);
        temp=0;
    }
    reverse(result2.begin(),result2.end());

    // for(auto x: result2){
    //     cout<<x<<" ";
    // }
    // cout<<endl;

    for(int i=0;i<v.size();i++){
        result.push_back(((result1[i]+result2[i])-1)*v[i]);
    }
    for(auto x: result){
        cout<<x<<" ";
    }

}

int main(){
    int n,temp;
    cin>>n;
    vector<int>v;

    for(int i=0;i<n;i++){
        cin>>temp;
        v.push_back(temp);
    }

    solve(v);
}