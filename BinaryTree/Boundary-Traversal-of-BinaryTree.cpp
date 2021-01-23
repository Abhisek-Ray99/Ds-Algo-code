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

void leftTree(BTNode<int> *root,vector<int> &ans){
    if(!root) return;
    if(root->left){
        ans.push_back(root->data);
        leftTree(root->left,ans);
    }else if(root->right){
        ans.push_back(root->data);
        leftTree(root->right,ans);
    }
}
void leafNode(BTNode<int> *root,vector<int> &ans){
    if(!root) return;
    leafNode(root->left,ans);
    if(!root->left && !root->right) ans.push_back(root->data);
    leafNode(root->right,ans);
}

void rightTree(BTNode<int> *root,vector<int> &ans){
    if(!root) return;
    if(root->right){
        rightTree(root->right,ans);
        ans.push_back(root->data);
    }else if(root->left){
        rightTree(root->left,ans);
        ans.push_back(root->data);
    }
}

void printBoundary(BTNode<int> *root){
    vector<int> ans;
    ans.push_back(root->data);
    leftTree(root->left,ans);
    leafNode(root,ans);
    rightTree(root->right,ans);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    BTNode<int> *root = new BTNode<int>(1);
    root->left = new BTNode<int>(2);
    root->right = new BTNode<int>(3);
    root->left->left = new BTNode<int>(4);
    root->left->right = new BTNode<int>(5);
    root->right->left = new BTNode<int>(6);
    root->right->right = new BTNode<int>(7);
    cout<<"The boundary traversal of Binary tree is : ";
    printBoundary(root);

    return 0;
}