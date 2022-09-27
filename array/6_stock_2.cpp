#include<iostream>
using namespace std;

void multipleStock(int arr[],int n){
    if(n==1) {
        cout<<"0";
        return;
    }
    int maxProfit = 0;
    int j=n-1;
    int i=n-2;
    while(i>=0){
        if(arr[j]>arr[i]){
            maxProfit += arr[j]-arr[i];
            j--;
            i--;
        }
        else{
            j=i;
            i--;
        }
    }
    cout<<maxProfit;
}

int main(){
    int arr[] = {5,2,7,3,6,1,2,4};
    int n = 8;
    multipleStock(arr,n);
}