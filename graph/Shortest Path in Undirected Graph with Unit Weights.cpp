#include<bits/stdc++.h>
using namespace std;

void shortestPath(vector<vector<int>> adjacency_list, int vertices){
    vector<int> distance(vertices+1, INT_MAX);
    queue<int> q;
    distance[1] = 0;
    q.push(1);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it:adjacency_list[node]){
            if(distance[node] + 1 < distance[it]){
                distance[it] = distance[node]+1;
                q.push(it);
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

    vector<vector<int> > adjacency_list(vertices+1);
    for(int start=0; start<edges; start++){
        int node_f,node_t;
        cin>>node_f>>node_t;
        adjacency_list[node_f].push_back(node_t);
        adjacency_list[node_t].push_back(node_f);
    }

    shortestPath(adjacency_list,vertices);
    

    return 0;
}
