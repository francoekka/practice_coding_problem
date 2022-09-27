#include<bits/stdc++.h>
using namespace std;

int csd(int arr[],int diff,int n){

    int sum = (diff+accumulate(arr,arr+n,0))/2;
    int dp[n+1][sum+1];
    for(int i=0;i<=sum;i++){
        dp[0][i] = 0;
    }
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main(){
    int arr[]={2,1,2,3};
    int n= size(arr);
    int diff = 1;
    cout<<csd(arr,diff,n);
}