#include<bits/stdc++.h>
using namespace std;

int subset(int wt[],int W,int n){
    if(n==0)
        return 0;
    if(W==wt[n-1])
        return 1;
    if(wt[n-1]<W){
        return subset(wt,W-wt[n-1],n-1) + subset(wt,W,n-1);
    }
    else if(wt[n-1]>W){
        return subset(wt,W,n-1);
    }
    return 0;
}

int main(){
    int wt[]={2,3,7,8,10};
    int sum = 11;
    int n=5;
    int result = subset(wt,sum,n);
    if(result==0)
        cout<<"no";
    else
        cout<<"yes";
}