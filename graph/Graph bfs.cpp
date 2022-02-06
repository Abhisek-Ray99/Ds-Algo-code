#include<bits/stdc++.h>
using namespace std;

vector<int> printBFS(vector<int> adjacentList[],int vertices){
    vector<int> bfsStore;
    queue<int> q;
    vector<int> visited(vertices+1,0);
    for(int start=1; start<=vertices; start++){
        if(!visited[start]){
            q.push(start);
            visited[start] = 1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfsStore.push_back(node);
                for(auto it:adjacentList[node]){
                    if(!visited[it]){
                        q.push(it);
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
    cout<<"Enter number of vertices: ";
    cin>>vertices;
    cout<<"Enter number of edges: ";
    cin>>edges;

    vector<int> adjacentList[vertices+1];
    for(int start=0; start<edges; start++){
        int node1,node2;
        cin>>node1>>node2;
        adjacentList[node1].push_back(node2);
        adjacentList[node2].push_back(node1);
    }
    vector<int> bfs = printBFS(adjacentList,vertices);
    for(auto it:bfs){
        cout<<it<<" ";
    }

    return 0;
}