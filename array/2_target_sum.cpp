#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int target_sum){
    sort(arr.begin(),arr.end());
    int start = 0;
    int end = arr.size()-1;
    int sum;
    while(start<end){

        sum= arr[start]+arr[end];
        if(sum==target_sum){
            return 1;
        }
        else if(sum>target_sum){
            end--;
        }
        else{
            start++;
        }

    }
    return 0;
}

int main(){


    int target_sum;
    cout<<"enter the target sum: ";
    cin>>target_sum;

    int n;
    cout<<"enter the number of element in the array :";
    cin>>n;
    

    vector<int> arr;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        arr.push_back(temp);
    }

    cout<<solve(arr,target_sum);
}