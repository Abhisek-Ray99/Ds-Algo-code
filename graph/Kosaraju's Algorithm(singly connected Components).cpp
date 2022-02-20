#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<vector<int>> adjacency_list,vector<int> &visited,stack<int> &s){
    visited[node] = 1;
    for(auto it:adjacency_list[node]){
        if(!visited[it]){
            dfs(it,adjacency_list,visited,s);
        }
    }
    s.push(node);
}

void printSCC(int node,vector<vector<int>> transpose,vector<int> &visited){
    cout<<node<<" ";
    visited[node] = 1;
    for(auto it:transpose[node]){
        if(!visited[it]){
            printSCC(it,transpose,visited);
        }
    }
}

void kosaraju_s_algo(vector<vector<int>> adjacency_list,int vertices){
    stack<int> s;
    vector<int> visited(vertices+1, 0);
    for(int start=1; start<=vertices; start++){
        if(!visited[start]){
            dfs(start,adjacency_list,visited,s);
        }
    }
    // reverse the direction of edges in the graph
    vector<vector<int>> transpose(vertices+1);
    for(int start=1; start<=vertices; start++){
        visited[start] = 0;
        for(auto it:adjacency_list[start]){
            transpose[it].push_back(start);
        }
    }
    for(int start=1; start<=vertices; start++){
        if(!visited[start]){
            printSCC(start,transpose,visited);
            cout<<endl;
        }
    }
}

int main(){
    int vertices,edges;
    cout<<"Enter number of vertices & edges: ";
    cin>>vertices>>edges;

    vector<vector<int>> adjacency_list(vertices+1);
    for(int start=0; start<edges; start++){
        int node_f,node_t;
        cin>>node_f>>node_t;
        adjacency_list[node_f].push_back(node_t);
    }

    kosaraju_s_algo(adjacency_list,vertices);

}
