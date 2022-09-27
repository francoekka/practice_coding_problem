#include<iostream>
using namespace std;

int find_path(int n,int m){
    if(n==1 || m==1) return 1;
    return find_path(n-1,m)+find_path(n,m-1);
}


int main(){
    int n = 4, m = 3;
    cout<<find_path(n,m);
}