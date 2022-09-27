#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph{
    private:
    bool isCycle(int node,vector<int>adj[],vector<int>&visited){
        visited[node]=1;
        queue<pair<int,int>> q;
        q.push({node,-1});

        while(!q.empty()){
            int cnode = q.front().first;
            int pnode = q.front().second;
            q.pop();
            for(auto it : adj[cnode]){
                if(visited[it]==0){
                    visited[it]=1;
                    q.push({it,cnode});
                }
                else if(it != pnode) return true;
            }
        }
        return false;
    }

    public:

    bool detectCycle(int n,vector<int>adj[]){
        vector<int> visited(n+1,0);
        for(int i=1;i<=n;i++){
            if(visited[i]==0){
                if(isCycle(i,adj,visited)) return true;
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
/*
7 6
1 2
2 4
3 5
4 6
5 6
6 7
 */