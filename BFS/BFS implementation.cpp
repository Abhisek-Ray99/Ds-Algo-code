#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> findbfs(vector<int> adj[], int v){
    vector<int> bfs;
    vector<int> vis(v+1);
    for(int s=0; s<=v; s++){
        if(!vis[s]){
            queue<int> q;
            q.push(s);
            vis[s] = 1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for(auto it: adj[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }
    return bfs;
}

int main(){
    int n,m;
    cout<<"Enter the number of vertices & edges : "<<endl;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int s=0; s<m; s++){
        int u,v;
        cout<<"Enter u & v: "<<endl;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> temp;
    temp = findbfs(adj,n);
    for(int s=0; s<temp.size()-1; s++){
        cout<<temp[s]<<" ";
    }

    return 0;
}