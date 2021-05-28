#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool bipartite(int s, vector<int> adj[], int color[]){
    queue<int> q;
    q.push(s);
    color[s] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it: adj[node]){
            if(color[it] == -1){
                color[it] = 1-color[node];
                q.push(it);
            }else if(color[it] == color[node]){
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<int> adj[],int v){
    int color[v];
    memset(color, -1, sizeof color);
    for(int s=0; s<v; s++){
        if(color[s] == -1){
            if(!bipartite(s,adj,color)){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n,m;
    cout<<"Enter the vertices & edges : ";
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int s=0; s<m; s++){
        int u,v;
        cout<<"Enter u & v:";
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    (isBipartite(adj,n)) ? cout<<"Valid Bipartite" : cout<<"Not a valid Bipartite";

    return 0;
}
