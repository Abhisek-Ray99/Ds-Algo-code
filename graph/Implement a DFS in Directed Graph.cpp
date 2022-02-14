#include<bits/stdc++.h>
using namespace std;

void dfsHelper(vector<vector<int> > adjacency_list, int node, vector<int> &dfsStore, vector<int> &visited){
    dfsStore.push_back(node);
    visited[node] = 1;
    for(auto it:adjacency_list[node]){
        if(!visited[it]){
            dfsHelper(adjacency_list,it,dfsStore,visited);
        }
    }
}

vector<int> dfs(vector<vector<int> > adjacency_list, int vertices){
    vector<int> dfsStore;
    vector<int> visited(vertices+1,0);
    for(int start=1; start<=vertices; start++){
        if(!visited[start]){
            dfsHelper(adjacency_list,start,dfsStore,visited);
        }
    }
    return dfsStore;
}

int main(){
    int vertices,edges;
    cout<<"Enter number of vertices & edges: ";
    cin>>vertices>>edges;

    vector<vector<int> > adjacency_list(vertices+1);
    for(int start=0; start<edges; start++){
        int node_f,node_t;
        cin>>node_f>>node_t;
        adjacency_list[node_f].push_back(node_t);
    }

    vector<int> storedfs = dfs(adjacency_list,vertices);
    for(auto it:storedfs){
        cout<<it<<" ";
    }

    return 0;
}
