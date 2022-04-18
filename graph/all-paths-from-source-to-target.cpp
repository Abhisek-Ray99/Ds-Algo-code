#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int>& path, vector<vector<int>>& store, vector<vector<int> > adjacency_list){
    path.push_back(node);
    if(node == adjacency_list.size()-1){
        store.push_back(path);
    }else{
        for(auto it: adjacency_list[node]){
            dfs(it, path, store, adjacency_list);
        }
    }
    path.pop_back();
}
vector<vector<int> > allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int> > store;
    vector<int> path;
    dfs(0, path, store, graph);
    return store;
}

int main(){
    vector<vector<int> > graph = {{1,2},{3},{3},{}};
    vector<vector<int> > temp = allPathsSourceTarget(graph);
    
    for(int s1=0; s1<temp.size(); s1++){
        for(int s2=0; s2<temp[s1].size(); s2++){
            cout<<temp[s1][s2];
        }
        cout<<endl;
    }

    return 0;
}
