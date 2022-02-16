#include<bits/stdc++.h>
using namespace std;

class DisJointSet{
    int *rank, *parent, size;
    public:
        DisJointSet(int size){
            rank = new int[size];
            parent = new int[size];
            this->size = size;
            makeSet();
        }
        void makeSet(){
            for(int start=1; start<=size; start++){
                parent[start] = start;
                rank[start] = 0;
            }
        }

        int findParent(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }

        void Union(int node1,int node2){
            node1 = findParent(node1);
            node2 = findParent(node2);
            if(rank[node1] < rank[node2]){
                parent[node1] = node2;
            }else if(rank[node2] < rank[node1]){
                parent[node2] = node1;
            }else{
                parent[node2] = node1;
                rank[node1]++;
            }
        }
};


int main(){
    cout<<"Enter the no. of node to create: ";
    int numberofNode;
    cin>>numberofNode;
    DisJointSet d(numberofNode+1);
    d.Union(1,2);
    d.Union(2,3);
    d.Union(4,5);
    d.Union(6,7);
    d.Union(5,6);
    d.Union(3,7);
     if (d.findParent(3) == d.findParent(6))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
