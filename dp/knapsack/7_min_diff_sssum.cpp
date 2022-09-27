#include<bits/stdc++.h>
using namespace std;

int min_diff(int arr[],int range,int n){

//initializing table
    bool dp[n+1][range+1];
    for(int i=0;i<=range;i++){
        dp[0][i]= false;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]= true;
    }

//filling with boolean values
    for(int i=1;i<=n;i++){
        for(int j=1;j<=range;j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

//extracting the index value having true
    vector<int> v;
    for(int j=0;j<=range/2;j++){
        if(dp[n][j]==true){
            v.push_back(j);
        }
    }

//calculating min diff
    int min_dif = INT_MAX;
    for(auto x : v){
        min_dif = min(min_dif,range-(2*(v[x])));
    }

    // for(int i=0;i<v.size();i++){
    //     min_dif = min(min_dif,range-(2*v[i]));
    // }

    return min_dif;
}

int main(){
    int arr[]={1,2,7};
    int n = size(arr);
    cout<<min_diff(arr,accumulate(arr,arr+n,0),n);
}