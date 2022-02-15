#include<bits/stdc++.h>
using namespace std;

void prim_s_algo(vector<vector<pair<int,int>>> adjacency_list,int vertices){
    vector<int> key(vertices+1, INT_MAX);
    vector<int> isMST(vertices+1, 0);
    vector<int> parent(vertices+1, -1);
    priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int>>> pq;
    
    key[1] = 0;
    parent[1] = -1;
    pq.push({0,1});
    for(int start=1; start<=vertices; start++){
        int node = pq.top().second;
        pq.pop();
        isMST[node] = 1;
        for(auto it:adjacency_list[node]){
            int vertex = it.first;
            int weight = it.second;
            if(isMST[vertex] == false && weight < key[vertex]){
                parent[vertex] = node;
                pq.push({key[vertex],vertex});
                key[vertex] = weight;
            }
        }
    }
    for(int start=1; start<=vertices; start++){
        cout<<"P-> "<<parent[start]<<" -  C-> "<<start<<endl;
    }
}

int main(){
    int vertices,edges;
    cout<<"Enter the number of vertices & edges: ";
    cin>>vertices>>edges;

    vector<vector<pair<int,int>>> adjacency_list(vertices+1);
    for(int start=0; start<edges; start++){
        int node_f,node_t, weight;
        cin>>node_f>>node_t>>weight;
        adjacency_list[node_f].push_back({node_t,weight});
        adjacency_list[node_t].push_back({node_f,weight});
    }
    prim_s_algo(adjacency_list,vertices);
    

    return 0;
}
