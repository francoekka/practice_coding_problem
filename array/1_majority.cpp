#include<bits/stdc++.h>
using namespace std;


//using map---> O(nlogn)

// int main(){
//     int arr[]={1,2,3,2,2,1,1,1,2,1,1,1,3};
//     int n= sizeof(arr)/sizeof(arr[0]);
//     map<int,int> m;
//     int temp;
//     for(int i=0;i<n;i++){
//         temp= arr[i];
//         m[temp]++;
//         if(m[temp]>n/2){
//             cout<<temp;
//             break;
//         }
//     }

// }

int main(){
    int arr[]={2,1,2,3,2,2,2,3,1};
    int candidate = arr[0];
    int votes = 1;
    int n= sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]==candidate){
            votes++;
        }
        else{
            votes--;
            if(votes==0){
                candidate = arr[i];
                //cout<<candidate<<" current candidate"<<endl;
                votes++;
            }
        }
    }
    cout<<candidate;
}