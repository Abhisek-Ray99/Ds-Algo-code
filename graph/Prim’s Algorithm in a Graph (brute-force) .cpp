#include<bits/stdc++.h>
using namespace std;

void prim_s_algo(vector<vector<pair<int,int>>> adjacency_list,int vertices){
    vector<int> key(vertices+1, INT_MAX);
    vector<int> isMST(vertices+1, 0);
    vector<int> parent(vertices+1, -1);
    key[1] = 0;
    parent[1] = -1;
    for(int start1=1; start1<vertices; start1++){
        int min = INT_MAX;
        int node;
        for(int start2=1; start2<vertices; start2++){
            if(isMST[start2] == false && key[start2] < min){
                min = key[start2];
                node = start2;
            }
        }
        isMST[node] = 1;
        for(auto it:adjacency_list[node]){
            int vertex = it.first;
            int weight = it.second;
            if(isMST[vertex] == false && weight < key[vertex]){
                parent[vertex] = node;
                key[vertex] = weight;
            }
        }
    }
    for(int start=1; start<=vertices; start++){
        cout<<parent[start]<<" - "<<start<<endl;
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
