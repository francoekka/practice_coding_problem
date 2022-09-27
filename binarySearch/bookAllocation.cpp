#include<bits/stdc++.h>
using namespace std;

int allocation(int arr[],int n,int k){
    
    int low = INT_MIN;
    for(int i=0;i<n;i++){
        if(low<arr[i]) low=arr[i];
    }

    int high = 0;
    for(int i=0;i<n;i++){
        high+=arr[i];
    }
    int min_max = INT_MAX;

    
    

    

    while(low<=high){
        int mid = low + (high-low)/2;
        int allocated=1;
        bool check = true;
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum+= arr[i];
            if(sum>mid){
                allocated++;
                sum = arr[i];
                if(allocated>k) {
                    check = false;
                    break;
                }  
            }
        }
        if(check){
            min_max = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return min_max;
}

int main(){
    int n = 4;
    int arr[]={10,5,20,4};
    int k = 2;
    cout<<allocation(arr,n,k);
}