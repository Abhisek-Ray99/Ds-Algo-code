#include<bits/stdc++.h>
using namespace std;

void dfsTopo_sort(int node,vector<vector<pair<int,int>>> adjacency_list,vector<int> &visited, stack<int> &s){
    visited[node] = 1;
    for(auto it:adjacency_list[node]){
        if(!visited[it.first]){
            dfsTopo_sort(it.first,adjacency_list,visited,s);
        }
    }
    s.push(node);
}

void shortestPath_DAG(vector<vector<pair<int,int>>> adjacency_list, int vertices){
    vector<int> visited(vertices+1, 0);
    stack<int> s;
    for(int start=1; start<=vertices; start++){
        if(!visited[start]){
            dfsTopo_sort(start, adjacency_list, visited, s);
        }
    }
    vector<int> distance(vertices+1, INT_MAX);
    distance[1] = 0;
    while(!s.empty()){
        int node = s.top();
        s.pop();
        if(distance[node] != INT_MAX){
            for(auto it:adjacency_list[node]){
                if(distance[node] + it.second < distance[it.first]){
                    distance[it.first] = distance[node]+it.second;
                }
            }
        }
    }
    for(int start=1; start<=vertices; start++){
        cout<<distance[start]<<" ";
    }
}

int main(){
    int vertices,edges;
    cout<<"Enter number of vertices & edges: ";
    cin>>vertices>>edges;

    vector<vector<pair<int,int>>> adjacency_list(vertices+1);
    for(int start=0; start<edges; start++){
        int node_f,node_t,weight;
        cin>>node_f>>node_t>>weight;
        adjacency_list[node_f].push_back({node_t,weight});
    }

    shortestPath_DAG(adjacency_list,vertices);
    

    return 0;
}
