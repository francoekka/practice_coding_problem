#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int i,int j){
    if(i>=j){
        return 0;
    }

    int mn = INT_MAX;
    for(int k=i;k<j;k++){
        int temp = solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[i]*arr[j];
        if(temp<mn){
            mn = temp;
        }
    }
    return mn;
}

int main(){
    int arr[]={40,20,30,10,30};
    cout<<solve(arr,1,size(arr)-1);
}