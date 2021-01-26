// find distance between two nodes in a Binary Tree

#include<iostream>
using namespace std;

template<typename T>
class BTNode{
    public:
        int data;
        BTNode *left;
        BTNode *right;
        BTNode(T data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

BTNode<int> *lca(BTNode<int> *root,int node1,int node2){
    if(root == NULL) return NULL;
    if(root->data == node1 || root->data == node2) return root;
    BTNode<int> *left = lca(root->left,node1,node2);
    BTNode<int> *right = lca(root->right,node1,node2);
    if(left && right) return root;
    if(left) return left;
    else return right;
}

int distHelper(BTNode<int> *root,int node){
    if(root == NULL) return 0;
    if(root->data == node) return 1;
    int dist1 = distHelper(root->left,node);
    int dist2 = distHelper(root->right,node);
    if(!dist1 && !dist2) return 0;
    else return dist1+dist2+1;
}

int findDistance(BTNode<int> *root,int node1,int node2){
    BTNode<int> *LCA = lca(root,node1,node2);
    int dist1 = distHelper(LCA,node1);
    int dist2 = distHelper(LCA,node2);
    return dist1+dist2-2;
}

int main(){
    BTNode<int> *root = new BTNode<int>(1);
    root->left = new BTNode<int>(2);
    root->right = new BTNode<int>(3);
    root->left->left = new BTNode<int>(4);
    root->left->right = new BTNode<int>(5);
    root->right->left = new BTNode<int>(6);
    root->right->right = new BTNode<int>(7);
    cout<<"\nThe distance between 5 & 6 : "<<findDistance(root,5,6);
    cout<<"\nThe distance between 4 & 7 : "<<findDistance(root,4,7);
    cout<<"\nThe distance between 2 & 3 : "<<findDistance(root,2,3);

    return 0;
}