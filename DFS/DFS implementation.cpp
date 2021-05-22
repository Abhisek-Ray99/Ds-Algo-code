#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> &storeDFS, vector<int> adj[]){
    storeDFS.push_back(node);
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it,vis,storeDFS,adj);
        }
    }
}

vector<int> findDFS(vector<int> adj[], int v){
    vector<int> storeDFS;
    vector<int> vis(v+1,0);
    for(int s=0; s<=v; s++){
        if(!vis[s]){
            dfs(s,vis,storeDFS,adj);
        }
    }
    return storeDFS;
}

int main(){
    int n,m;
    cout<<"Enter the vertices & edges : ";
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int s=0; s<m; s++){
        int u,v;
        cout<<"Enter u & v: ";
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> temp;
    temp = findDFS(adj,n);
    for(int s=0; s<temp.size()-1; s++){
        cout<<temp[s]<<" ";
    }

}