#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001][2];

int parenthesis(string s,int i, int j,bool isTrue){
    if(i>j){
        return false;
    }

    if(i==j){
        if(isTrue==true){
            return s[i]=='T';
        }
        else{
            return s[i]=='F';
        }
    }

    if (dp[i][j][isTrue]!=-1){
        return dp[i][j][isTrue];
    }
    int ans=0;
    for(int k=i+1;k<j;k=k+2){

        int lt = parenthesis(s,i,k-1,true);
        int lf = parenthesis(s,i,k-1,false);
        int rt = parenthesis(s,k+1,j,true);
        int rf = parenthesis(s,k+1,j,false);

        if(s[k]=='&'){
            if(isTrue==true){
                ans+= lt*rt;
            }
            else{
                ans+= lt*rf + rt*lf + lf*rf; 
            }
        }

        if(s[k]=='^'){
            if(isTrue==true){
                ans+= lt*rf + lf*rt;
            }
            else{
                ans+= lt*rt + rf*lf; 
            }
        }

        if(s[k]=='|'){
            if(isTrue==true){
                ans+= lt*rf + lf*rt + lt*rt;
            }
            else{
                ans+= rf*lf; 
            }
        }

    }
    return dp[i][j][isTrue]= ans;
}

int main(){
    string s;
    cin>>s;
    memset(dp,-1,sizeof(dp));
    cout<<parenthesis(s,0,s.length()-1,true)%1003;
}