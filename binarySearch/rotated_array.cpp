#include<iostream>
using namespace std;

int rotatedBinary(int arr[],int low, int high, int target){
    
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==target) return mid;

        if(arr[low]<arr[mid])
            {
                if(target>=arr[low] && target<arr[mid])
                { 
                    high = mid-1;
                }
                else low = mid+1;
            }
        else{
            if(target>=arr[mid] && target<arr[high]){
                low = mid+1;
            }
            else high = mid-1;
        }
    }
    return -1;
}


int main(){
    int arr[]={120,130,40,50,90,100,110};
    int arr1[]={50,60,90,100,20,30,40};
    int arr2[]{20,30,40,50,60,5,10};
    cout<<rotatedBinary(arr,0,6,120)<<endl;
    cout<<rotatedBinary(arr1,0,6,20)<<endl;
    cout<<rotatedBinary(arr2,0,6,5)<<endl;
}