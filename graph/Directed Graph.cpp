#include<bits/stdc++.h>
using namespace std;



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

    for(int start1=1; start1<=vertices; start1++){
        cout<<start1<<" : ";
        for(int start2=0; start2<adjacency_list[start1].size(); start2++){
            cout<<adjacency_list[start1][start2]<<", ";
        }
        cout<<endl;
    }

    return 0;
}
