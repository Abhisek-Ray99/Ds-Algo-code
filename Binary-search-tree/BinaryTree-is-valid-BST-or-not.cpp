// The Binary Tree is BST or not

#include<iostream>
using namespace std;

template<typename T>
class BTNode{
    public:
        T data;
        BTNode *left;
        BTNode *right;
        BTNode(T data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

void PrintTree(BTNode<int> *root){
    if(root == NULL) return;
    cout<<root->data<<": ";
    if(root->left) cout<<"L->"<<root->left->data<<", ";
    if(root->left) cout<<"R->"<<root->left->data;
    cout<<endl;
    PrintTree(root->left);
    PrintTree(root->right);
}

bool isBSTUtil(BTNode<int> *root,BTNode<int> *&prev){
    if(root){
        if(!isBSTUtil(root->left,prev)) return false;
        if(prev != NULL && root->data <= prev->data){
            return false;
        }
        prev = root;
        return isBSTUtil(root->right,prev);
    }
    return true;
}

bool isBST(BTNode<int> *root){
    BTNode<int> *prev = NULL;
    return isBSTUtil(root,prev);
}

int main(){
    BTNode<int> *root = new BTNode<int>(10);
    root->left = new BTNode<int>(5);
    root->right = new BTNode<int>(20);
    root->left->left = new BTNode<int>(3);
    root->left->right = new BTNode<int>(7);
    root->right->left = new BTNode<int>(15);

    cout<<"The binary tree is : "<<endl;
    PrintTree(root);
    (isBST(root) == 1) ? cout<<"\nThe tree is BST"
                       : cout<<"\nThe tree is not a BST";

    return 0;
}