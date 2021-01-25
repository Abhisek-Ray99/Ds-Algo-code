// Print all K sum paths in a Binary Tree

#include<iostream>
#include<vector>
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


void printKPath(BTNode<int> *root,vector<int> &path,int k){
    if(root == NULL) return;
    path.push_back(root->data);
    printKPath(root->left,path,k);
    printKPath(root->right,path,k);

    int sum = 0;
    for(int j=path.size()-1; j>=0; j--){
        sum += path[j];
        if(sum == k){
            for(int m=j; m<path.size(); m++){
                cout<<path[m]<<" ";
            }
            cout<<endl;
        }
    }
    path.pop_back();
}

int main(){
    BTNode<int> *root = new BTNode<int>(1);
    root->left = new BTNode<int>(3);
    root->right = new BTNode<int>(-1);
    root->left->left = new BTNode<int>(2);
    root->left->right = new BTNode<int>(1);
    root->right->left = new BTNode<int>(4);
    root->right->right = new BTNode<int>(5);
    root->left->right->left = new BTNode<int>(1);
    root->right->left->left = new BTNode<int>(1);
    root->right->left->right = new BTNode<int>(2);
    root->right->right->right = new BTNode<int>(6);
    
    vector<int> path;
    int k = 5;
    printKPath(root,path,k);

    return 0;
}