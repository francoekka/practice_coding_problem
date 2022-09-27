#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    int adj_mat[n+1][n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj_mat[u][v]=1;
        adj_mat[v][u]=1;
    }
    return 0;
}