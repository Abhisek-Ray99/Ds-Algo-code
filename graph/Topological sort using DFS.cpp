#include<bits/stdc++.h>
using namespace std;

void topologicalDFS(int node, vector<vector<int>> adjacency_list,vector<int> &visited, stack<int> &s){
    visited[node] = 1;
    for(auto it:adjacency_list[node]){
        if(!visited[it]){
            topologicalDFS(it,adjacency_list,visited,s);
        }
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int> > adjacency_list,int vertices){
    vector<int> visited(vertices+1, 0);
    stack<int> s;
    for(int start=1; start<=vertices; start++){
        if(!visited[start]){
            topologicalDFS(start,adjacency_list,visited,s);
        }
    }
    vector<int> storeSort;
    while(!s.empty()){
        storeSort.push_back(s.top());
        s.pop();
    }
    return storeSort;
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
    vector<int> temp = topologicalSort(adjacency_list,vertices);
    for(auto it:temp){
        cout<<it<<" -> ";
    }

    return 0;
}
