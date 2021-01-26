// Kth ancestor of a node in binary tree

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

BTNode<int> *kthAncestor(BTNode<int> *root,int node,int &kth){
    if(root == NULL) return NULL;
    BTNode<int> *temp = NULL;
    if(root->data == node || (temp = kthAncestor(root->left,node,kth)) || (temp = kthAncestor(root->right,node,kth))){
        if(kth > 0) kth--;
        else if(kth == 0){
            cout<<"Kth ancestor is : "<<root->data;
            return NULL;
        }
        return root;
    }
    return 0;
}

int main(){
    BTNode<int> *root = new BTNode<int>(1);
    root->left = new BTNode<int>(2);
    root->right = new BTNode<int>(3);
    root->left->left = new BTNode<int>(4);
    root->left->right = new BTNode<int>(5);
    root->right->right = new BTNode<int>(6);
    root->right->left = new BTNode<int>(7);
    root->left->left->left = new BTNode<int>(8);
    root->left->left->right = new BTNode<int>(9);
    int Kth = 2;
    int node = 9;
    kthAncestor(root,node,Kth);


    return 0;
}