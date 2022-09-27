#include<iostream>
#include<vector>
using namespace std;

class Graph{

    private:
    void dfs_helper(int node,vector<int>&result,vector<int>&visited,
            vector<int> adj[],int n){
            if(visited[node]!=0) return;
            result.push_back(node);
            visited[node]=1;
            for(auto it : adj[node])
                if(visited[it]==0){
                    dfs_helper(it,result,visited,adj,n);
                }
        }
    

    public:

    vector<int> dfs(int n, vector<int> adj[]){
        vector<int> result;
        vector<int> visited(n+1,0);

        for(int i=1;i<=n;i++){
            if(visited[i]==0){
                dfs_helper(i,result,visited,adj,n);
            }
        }
        return result;
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
    vector<int> result;
    result = g.dfs(n,adj);

    for(auto it : result){
        cout<<it<<" ";
    }
    return 0;
}