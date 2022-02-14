#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int> > adjacency_list, int vertices){
    vector<int> bfsStore;
    vector<int> visited(vertices+1,0);
    for(int start=1; start<=vertices; start++){
        if(!visited[start]){
            queue<int> qStore;
            qStore.push(start);
            visited[start] = 1;
            while(!qStore.empty()){
                int node = qStore.front();
                qStore.pop();
                bfsStore.push_back(node);
                for(auto it:adjacency_list[node]){
                    if(!visited[it]){
                        qStore.push(it);
                        visited[it] = 1;
                    }
                }
            }
        }
    }
    return bfsStore;
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

    vector<int> storebfs = bfs(adjacency_list,vertices);
    for(auto it:storebfs){
        cout<<it<<" ";
    }

    return 0;
}
