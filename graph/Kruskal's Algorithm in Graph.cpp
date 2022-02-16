#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int node1,node2,weight;
        node(int node1,int node2,int weight){
            this->node1 = node1;
            this->node2 = node2;
            this->weight = weight;
        }
};

int compare(node n1,node n2){
    return n1.weight < n2.weight;
}

int findParent(int node, vector<int> &parent){
    if(node == parent[node]) return node;
    return findParent(parent[node], parent);
}

void Union(int n1,int n2, vector<int> &parent, vector<int> &rank){
    n1 = findParent(n1,parent);
    n2 = findParent(n2,parent);
    if(rank[n1] < rank[n2]){
        parent[n1] = n2;
    }else if(rank[n2] < rank[n1]){
        parent[n2] = n1;
    }else{
        parent[n2] = n1;
        rank[n1]++; 
    }
}

void kruskal_s_algo(vector<node> adj, int vertices){
    sort(adj.begin(),adj.end(),compare);
    vector<int> parent(vertices+1);
    vector<int> rank(vertices+1,0);
    for(int start=1; start<=vertices; start++){
        parent[start] = start;
    }
    int cost = 0;
    vector<pair<int,int> > MST;
    for(auto it:adj){
        if(findParent(it.node1,parent) != findParent(it.node2,parent)){
            cost += it.weight;
            MST.push_back({it.node1, it.node2});
            Union(it.node1,it.node2,parent,rank);
        }
    }
    cout<<"Minimum Cost: "<<cost<<endl;
    for(auto it: MST){
        cout<<it.first<<" - "<<it.second<<endl;
    }
}

int main(){
    int vertices, edges;
    cout<<"Enter number of vertices & edges : ";
    cin>>vertices>>edges;

    vector<node> adj;
    for(int start=0; start<edges; start++){
        int node_f,node_t,weight;
        cin>>node_f>>node_t>>weight;
        adj.push_back(node(node_f,node_t,weight));
    }

    kruskal_s_algo(adj,vertices);

    return 0;
}
