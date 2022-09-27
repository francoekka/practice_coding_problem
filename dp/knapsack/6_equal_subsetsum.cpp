#include<bits/stdc++.h>
using namespace std;

bool subset(int arr[],int sum,int n){
    int dp[n+1][sum+1];
    for(int i=0;i<=sum;i++){
        dp[0][i]= false ;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]= true;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j]= dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

bool equal_subset(int arr[],int n){
    int sum= accumulate(arr,arr+n,0);
    if(sum%2!=0){
        return false;
    }
    else{
        return subset(arr,sum/2,n);
    }
    return false;
}

int main(){
    int arr[]={1,5,11,5};
    int n = size(arr);
    cout<<equal_subset(arr,n);
}