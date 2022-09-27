#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,val,k;
    cin>>n>>k;
    int *arr = new int(n);

    for(int i=0;i<n;i++){
        cin>>val;
        arr[i]=val;
    }

    int bitsize = 8*sizeof(int);
    int count[bitsize];
    memset(count,0,sizeof(count));

    for(int i=0;i<bitsize;i++){
        for(int j=0;j<n;j++){
            if((arr[j]&(1<<i))!=0){
                count[i]+=1;
            }
        }
    }
    // for(auto x : count){
    //     cout<<x<<" ";
    // }
    int res=0;
    for(int i=0;i<bitsize;i++){
        if(count[i]%k!=0){
            res += pow(2,i); 
        }
    }
    cout<<res;

}