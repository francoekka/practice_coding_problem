#include<iostream>
using namespace std;

void stock_extraspace(int arr[],int n){
    int maxProfit= INT_MIN;
    int maxArr[n];
    maxArr[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        if(arr[i]>maxArr[i+1]){
            maxArr[i] = arr[i];
        }
        else
            maxArr[i] = maxArr[i+1];
    }
    for(int i=0;i<n;i++){
        if(maxProfit< maxArr[i]-arr[i])
            maxProfit = maxArr[i]-arr[i];
    }
    cout<<maxProfit<<endl;
}

void stock(int arr[], int n){
    int maxProfit = INT_MIN;
    int currMin = arr[1];

    for(int i=0;i<n;i++){
        if(arr[i] < currMin){
            currMin = arr[i];
        }
        if(maxProfit < arr[i]-currMin){
            maxProfit = arr[i]-currMin;
        }
    }

    cout<<maxProfit<<endl;
}


int main(){
    int arr[]={3,1,4,8,7,2,5};
    int n = 7;
    stock_extraspace(arr,n);
    stock(arr,n);
}