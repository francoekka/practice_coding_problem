#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int mcm(int arr[],int i,int j){
    
    if(i>=j){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int mn = INT_MAX;
    for(int k=i;k<j;k++){
        int temp = mcm(arr,i,k)+mcm(arr,k+1,j)+arr[i-1]*arr[i]*arr[j];
        mn = min(temp,mn);
    }

    return dp[i][j] = mn;

}

int main(){
    int arr[]={2,3,4,2};
    memset(dp,-1,sizeof(dp));
    cout<<mcm(arr,1,size(arr)-1);
}