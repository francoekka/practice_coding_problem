#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph{
    public:

    vector<int>bfs(int n, vector<int> adj[]){
            vector<int>result;
            vector<int> visited(n+1,0);
            for(int i=1;i<=n;i++){
                if(visited[i]==0){
                    queue<int> q;
                    q.push(i);
                    while(!q.empty()){
                        int curr = q.front();
                        q.pop();
                        if(visited[curr]==0){
                                result.push_back(curr);
                                visited[curr]=1;
                                for(auto it : adj[curr]){
                                q.push(it);
                            }
                        }

                    }
                }

            }
            return result;

        }
};






int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<int>result;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Graph g;
    result = g.bfs(n,adj);
    for(auto x : result){
        cout<<x<<" ";
    }
    return 0;
}