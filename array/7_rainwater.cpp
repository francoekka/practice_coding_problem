#include<iostream>
using namespace std;

void rain(int arr[],int n){
    int maxLeft[n],maxRight[n];
    maxLeft[0]= arr[0];
    maxRight[n-1] = arr[n-1];
    int sum=0;


    for(int i=1;i<n;i++){
        if(arr[i]<maxLeft[i-1]){
            maxLeft[i] = maxLeft[i-1];
        }
        else maxLeft[i] = arr[i];
    }

    for(int i=n-2;i>=0;i--){
        if(arr[i]<maxRight[i+1]){
            maxRight[i] = maxRight[i+1];
        }
        else maxRight[i] = arr[i];
    }

    for(int i=0;i<n;i++){
        sum+= min(maxLeft[i],maxRight[i])-arr[i];
    }
    cout<<sum;

}

int main(){
    int arr[]={1,1,2,4,0,1,3,2};
    int n=8;
    rain(arr,n);
}