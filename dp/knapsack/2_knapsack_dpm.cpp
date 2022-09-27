#include<bits/stdc++.h>
using namespace std;

int dp[100][100];


int knapsack(int wt[],int val[],int W,int n){
    if(n==0 || W==0) return 0;
    if(dp[n][W]==-1){
        if(wt[n-1]<=W) {
            dp[n][W]= max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
        }
        else 
            dp[n][W] = knapsack(wt,val,W,n-1);
    }
    return dp[n][W];
}

int main(){
    int W = 7;
    int wt[]={1,3,4,5};
    int val[]={1,4,5,7};
    int n=4;
    memset(dp,-1,sizeof(dp));

    cout<<knapsack(wt,val,W,n);
}