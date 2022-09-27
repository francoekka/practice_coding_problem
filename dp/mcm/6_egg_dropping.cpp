#include<bits/stdc++.h>
using namespace std;


int solve(int egg,int floor){

    if(floor==0 || floor==1){
        return floor;
    }
    if(egg==1){
        return floor;
    }

    int mn = INT_MAX;
    for(int i=1;i<=floor;i++){
        int temp = 1 + max(solve(egg-1,i-1),solve(egg,floor-i));
        mn = min(temp,mn);
    }

    return mn;

}


int main(){
    int egg,floor;
    cin>>egg>>floor;
    cout<<solve(egg,floor);
}