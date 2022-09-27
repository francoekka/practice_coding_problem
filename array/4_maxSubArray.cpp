#include<iostream>
using namespace std;

void maxSubarray(int arr[], int n){
    int maxSum = INT_MIN;
    int currSum = 0;

    for(int i=0;i<n; i++){
        currSum+=arr[i];
        if(maxSum<currSum){
            maxSum = currSum;
        }
        if(currSum<0){
            currSum=0;
        }
    }

    cout<<maxSum;
}

int main(){
    int arr[]={-5,4,6,-3,4,-1};
    int n = 6;
    maxSubarray(arr,n);
}