#include<iostream>
using namespace std;

void Merge(int arr[],int low,int high){

    int mid = (low+high)/2;

    int len1 = (mid-low)+1;
    int len2 = (high-mid);

    int *arr1 = new int(len1);
    int *arr2 = new int(len2);

    int sortedIndex=low;

    for(int i=0;i<len1;i++){
        arr1[i] = arr[sortedIndex++];
    }

    sortedIndex = mid+1; 

    for(int i=0;i<len2;i++){
        arr2[i] = arr[sortedIndex++];
    }

    int index1 = 0;
    int index2 = 0;
    sortedIndex = low;

    while(index1<len1 && index2<len2){
        if(arr1[index1]<arr2[index2]){
            arr[sortedIndex++] = arr1[index1++];
        }
        else
            arr[sortedIndex++] = arr2[index2++];
    }

    while(index1 < len1){
        arr[sortedIndex++] = arr1[index1++];
    }
    while(index2<len2){
        arr[sortedIndex++] = arr2[index2++];
    }
}

void mergesort(int arr[],int low,int high){
    if(low>=high) return;

    int mid = (low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    Merge(arr,low,high);

}

int main(){
    int arr[]={3,5,2,6,7,8,1};
    int n=7;
    mergesort(arr,0,n-1);
    for(auto x : arr){
        cout<<x<<" ";
    }
}