// https://practice.geeksforgeeks.org/problems/max-rectangle/1

#include<bits/stdc++.h>
using namespace std;


int solve2(vector<int> &v){
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

    for(int i=0;i<v.size();i++){
        result.push_back(((result1[i]+result2[i])-1)*v[i]);
    }
    return *max_element(result.begin(),result.end());

}


void solve(int arr[4][4]){
    vector<int> v;
    //int rows = sizeof(arr)/sizeof(arr[0]);
    //int columns = sizeof(arr[0])/sizeof(arr[0][0]);
    for(int j=0;j<4;j++){
        v.push_back(arr[0][j]);
    }

        int mx = solve2(v);
    for(int i=1;i<4;i++){
        for(int j=0;j<4;j++){
            if(arr[i][j]==0){
                v[j] = 0;
            }
            else{
                v[j]++;
            }

        }
        mx = max(solve2(v),mx);
    }
    cout<<mx<<endl;
}

int main(){
    int arr[][4]={{0,1,1,0},{1,1,1,1},{1,1,1,1},{0,1,1,0}};
    solve(arr);
}