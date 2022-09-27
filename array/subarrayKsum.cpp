#include<iostream>
#include<unordered_map>
using namespace std;

void subarrayKsum(int arr[],int n, int sum){
    int start = 0;
    int end = -1;
    int current = 0;

    unordered_map<int,int> um;

    for(int i=0;i<n;i++){
        current+= arr[i];

        if(current-sum==0){
            end=i;
            cout<<"0"<<" "<<end;
            break;
        }

        auto it = um.find(current-sum);
        if(it != um.end()){
            start = um[current-sum]+1;
            end = i;
            cout<<start<<" "<<end;
            break;
        }
        else{
            um[current] = i;
        }

    }
    

    if(end==-1) cout<<"-1";
}

int main(){
    int arr[]={10,15,-5,15,-10,5};
    int n=6;
    int sum = 35;
    subarrayKsum(arr,n,sum);
}