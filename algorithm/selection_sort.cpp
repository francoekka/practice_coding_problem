#include<iostream>
using namespace std;

void swapit(int arr[],int min,int i){
    int temp = arr[min];
    arr[min]=arr[i];
    arr[i]=temp;
}

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        if(min != i){
            swapit(arr,min,i);
        }
    }
}

int main(){
    int arr[5]={4,2,6,7,3};
    int n = 5;
    selectionSort(arr,n);
    for(auto x : arr){
        cout<<x<<" ";
    }
}