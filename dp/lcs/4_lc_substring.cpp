#include<bits/stdc++.h>
using namespace std;

int substring(string s1, string s2, int n, int m){
    
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }

    int count =0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                count = max(dp[i][j],count);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    return count;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<substring(s1,s2,s1.length(),s2.length());
}