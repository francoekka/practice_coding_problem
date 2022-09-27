#include<bits/stdc++.h>
using namespace std;

class Graph{

    private:
    bool isCycle(int node,int parent,vector<int>adj[],vector<int>&visited){
        visited[node]=1;
        for(auto it : adj[node]){
            if(!visited[it]){
                return isCycle(it,node,adj,visited);
            }
            else if(it !=parent) return true;
        }
        return false;
    }

    public:

    bool detectCycle(int n, vector<int>adj[]){
        vector<int> visited(n+1,0);
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                return isCycle(i,-1,adj,visited);
            }
        }
        return false;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    Graph g;
    cout<<g.detectCycle(n,adj);

}