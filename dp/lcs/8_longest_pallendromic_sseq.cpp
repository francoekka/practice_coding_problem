#include<bits/stdc++.h>
using namespace std;

int longest_pallindrome(string s1, int n){

    string s2 = s1;
    reverse(s2.begin(),s2.end());
    int m=n;


    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }


    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]= 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main(){
    string s1,s2;
    cin>>s1;
    int n = size(s1);
    cout<<longest_pallindrome(s1,n);
}