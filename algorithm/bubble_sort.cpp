#include<iostream>
using namespace std;

void swapit(int arr[],int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSort(int arr[],int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swapit(arr,j,j+1);
            }
        }
    }
}


int main(){
    int arr[5]={5,2,6,4,7};
    int n = 5;
    bubbleSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}