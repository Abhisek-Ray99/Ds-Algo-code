#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int> > adjacency_list,int vertices){
    vector<int> indegree(vertices+1, 0);
    queue<int> q;
    // set the degrees for all individual nodes
    for(int start=1; start<=vertices; start++){
        for(auto it:adjacency_list[start]){
            indegree[it]++;
        }
    }
    for(int start=1; start<=vertices; start++){
        if(indegree[start] == 0){
            q.push(start);
        }
    }
    vector<int> topoStore;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topoStore.push_back(node);
        for(auto it:adjacency_list[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }
    return topoStore;
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
