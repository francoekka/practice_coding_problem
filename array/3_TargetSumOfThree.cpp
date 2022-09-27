#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr , int target_sum){
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        int start = i+1;
        int end = arr.size()-1;
        int sum=0;
        while(start<end){
            sum = arr[start]+arr[end];
            if(sum==target_sum-arr[i]){
                return 1;
            }
            else if(sum>target_sum-arr[i]){
                end--;
            }
            else{
                start++;
            }
        }
    }
    return 0;
}


int main(){

    int target_sum;
    cin>>target_sum;
    int n;
    cin>>n;
    vector<int> arr;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        arr.push_back(temp);
    }

    cout<<solve(arr,target_sum);
}