#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool detectCycle(int s,int v,vector<int> adj[], vector<int> &vis){
    queue<pair<int,int> > q;
    vis[s] = true;
    q.push({s,-1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = true;
                q.push({it,node});
            }else if(parent != it){
                return true;
            }
        }
    }
    return false;
}

bool findCycle(int v,vector<int> adj[]){
    vector<int> vis(v+1, 0);
    for(int s=0; s<=v; s++){
        if(!vis[s]){
            if(detectCycle(s,v,adj,vis)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n,m;
    cout<<"Enter the number of vertices & edges : ";
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int s=0; s<m; s++){
        int u,v;
        cout<<"Enter u & v :";
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<findCycle(n,adj);

    return 0;
}
