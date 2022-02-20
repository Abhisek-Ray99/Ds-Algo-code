#include<bits/stdc++.h>
using namespace std;

void dijkstra_s_algo(vector<vector<pair<int,int>>> adjacency_list,int vertices,int source){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> distance(vertices+1, INT_MAX);
    distance[source] = 0;
    pq.push({0,source});
    while(!pq.empty()){
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();
        for(auto it:adjacency_list[prev]){
            int next = it.first;
            int nextDist = it.second;
            if(distance[next] > distance[prev]+ nextDist){
                distance[next] = distance[prev]+nextDist;
                pq.push({distance[next],next});
            }
        }
    }
    cout<<"The distance from source "<<source<<" are: "<<endl;
    for(int start=1; start<=vertices; start++){
        cout<<start<<" - "<<distance[start]<<endl;
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
        adjacency_list[node_t].push_back({node_f,weight});
    }

    cout<<"Enter the source node: ";
    int source;
    cin>>source;

    dijkstra_s_algo(adjacency_list,vertices,source);

    return 0;
}
