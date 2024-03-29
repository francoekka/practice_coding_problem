#include<bits/stdc++.h>
using namespace std;

int coinChange(int coins[], int amount,int n) {
        
        int t[n+1][amount+1];  

        for(int j=0; j <= amount; j++)
            t[0][j] = amount+1;
        for(int i=0; i <= n; i++)
            t[i][0] = 0;
        
        for(int i=1; i <= n; i++){
            for(int j=1; j <= amount; j++) {
                if(coins[i-1] <= j)
                    t[i][j] = min(1 + t[i][j-coins[i-1]], t[i-1][j]);
                else
                    t[i][j] = t[i-1][j];
            }
        }
        
        return t[n][amount] > amount ? -1 : t[n][amount];
    }

int main(){
    int coin[]={2,2,3};
    int sum =5;
    int n = size(coin);
    cout<<coinChange(coin,sum,n);
}