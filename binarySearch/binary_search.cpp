#include<iostream>
#include<vector>
using namespace std;

void binary_search(vector<int>arr,int n, int s){
    int start = 0;
    int end = n-1;
    
    while(start<=end){
        int mid = start + ((end-start)/2);
        if(arr[mid]==s){
            cout<<"found";
            return;
        }
        else if(arr[mid]<s){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    cout<<"not found";
    return;
}

int main(){
    int n,s;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        cin>>s;
        arr.push_back(s);
    }
    cout<<"search for : ";
    cin>>s;
    binary_search(arr,n,s);
}