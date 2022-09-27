#include<bits/stdc++.h>
using namespace std;

class Graph{

    private:
    bool isbipartite(int node,vector<int>adj[],vector<int>&color){
        color[node]=1;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int cnode = q.front();
            q.pop();
            for(auto it : adj[cnode]){
                if(color[it]==-1){
                    color[it]=1-color[cnode];
                    q.push(it);
                }
                else if(color[it]==color[cnode]) return false;
            }
        }
        return true;
    }

    public:
    bool checkBipartite(int n,vector<int>adj[]){
        vector<int> color(n+1,-1);
        for(int i=1;i<n;i++){
            if(color[i]==-1){
                if(!isbipartite(i,adj,color)) return false;
            }
            
        }
        return true;
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
    cout<<g.checkBipartite(n,adj);
}