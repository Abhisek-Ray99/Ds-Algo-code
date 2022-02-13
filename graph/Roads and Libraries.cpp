#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int> > cities,vector<int> &visited,int &start,long &visit_city){
    visit_city++;
    visited[start] = 1;
    for(auto it:cities[start]){
        if(!visited[it]){
            bfs(cities,visited,it,visit_city);
        }
    }
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    vector<long> store; 
    long cost = 0;
    vector<int> visited(n+1,0);
    for(int start=1; start<=n; start++){
        if(!visited[start]){
            long visit_city = 0;
            bfs(cities,visited,start,visit_city);
            cost = cost + c_lib;
            if(c_road > c_lib){
                cost = cost+(c_lib*(visit_city-1));
            }else{
                cost = cost+(c_road*(visit_city-1));
            }
        }
    }
    return cost;
}

int main(){
    int n_graph = 1;
    while(n_graph--){
        int vertices, edges;
        cout<<"Enter number of vertices: ";
        cin>>vertices;
        cout<<"Enter number fo edges: ";
        cin>>edges;
        int c_lib,c_road;
        cout<<"Enter library cost & road cost ";
        cin>>c_lib>>c_road;

        vector<vector<int> > cities(vertices+1);
        for(int start=0; start<edges; start++){
            int node1, node2;
            cin>>node1>>node2;
            cities[node1].push_back(node2);
            cities[node2].push_back(node1);
        }
        cout<<roadsAndLibraries(vertices,c_lib,c_road,cities);
    }
    

    return 0;
}
