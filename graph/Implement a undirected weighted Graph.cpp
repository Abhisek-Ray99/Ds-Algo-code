#include<bits/stdc++.h>
using namespace std;

void weightedGraph(vector<vector<pair<int,int>>> adjacency_list, int vertices){
    for(int start=1; start<=vertices; start++){
        cout<<start<<" : ";
        for(auto it:adjacency_list[start]){
            cout<<"{"<<it.first<<", "<<it.second<<"}, ";
        }
        cout<<endl;
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
    
    weightedGraph(adjacency_list,vertices);

    return 0;
}
