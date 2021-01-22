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

bool FindNode(BTNode<int> *root,int node){
    if(root == NULL) return false;
    if(root->data == node) return true;
    return FindNode(root->left,node) || FindNode(root->right,node);
}

int main(){
    BTNode<int> *root = new BTNode<int>(1);
    root->left = new BTNode<int>(2);
    root->right = new BTNode<int>(3);
    root->left->left = new BTNode<int>(4);
    root->left->right = new BTNode<int>(5);
    root->right->left = new BTNode<int>(6);
    root->right->right = new BTNode<int>(7);
    int node = 1;
    (FindNode(root,node) == 1) ? cout<<"Node found"
                          : cout<<"Node not found";

    return 0;
}