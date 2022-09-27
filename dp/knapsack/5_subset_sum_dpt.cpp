#include<bits/stdc++.h>
using namespace std;

bool subset(int wt[],int W,int n){
    bool dp[n+1][W+1];
    
    for(int j=0;j<=W;j++){
        dp[0][j]=false;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(wt[i-1]<=j)
                dp[i][j] =  dp[i-1][j-(wt[i-1])] || dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][W];
}


int main(){
    int wt[]={2,3,7,8,10};
    int sum = 16;
    int n=5;
    cout<<subset(wt,sum,n);
}