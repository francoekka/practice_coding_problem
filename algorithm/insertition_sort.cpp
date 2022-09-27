#include<iostream>
using namespace std;

void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]> temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

int main(){
    int arr[5]={4,2,7,8,5};
    int n = 5;

    insertionSort(arr,n);
    for(auto x : arr){
        cout<<x<<" ";
    }
}