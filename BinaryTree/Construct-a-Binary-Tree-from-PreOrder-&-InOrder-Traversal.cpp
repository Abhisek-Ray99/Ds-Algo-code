//make a binary tree from inorder & preorder Traversal

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

BTNode<int> *builtTreeHelper(vector<int> inOrder,vector<int> preOrder,int inS,int inE,int preS,int preE){
    if(inS > inE) return NULL;
    int rootData = preOrder[preS];
    int rootIndex = -1;
    for(int i=inS; i<=inE; i++){
        if(inOrder[i] == rootData){
            rootIndex = i;
            break;
        }
    }
    int leftinS = inS;
    int leftinE = rootIndex - 1;
    int leftpreS = preS + 1;
    int leftpreE = leftpreS + leftinE - leftinS;

    int rightinS = rootIndex + 1;
    int rightinE = inE;
    int rightpreS = leftpreE + 1;
    int rightpreE = preE;

    BTNode<int> *root = new BTNode<int>(rootData);

    root->left = builtTreeHelper(inOrder,preOrder,leftinS,leftinE,leftpreS,leftpreE);

    root->right = builtTreeHelper(inOrder,preOrder,rightinS,rightinE,rightpreS,rightpreE);

    return root;
}

BTNode<int> *builtTree(vector<int> &inOrder,vector<int> &preOrder){
    int n = inOrder.size();
    return builtTreeHelper(inOrder,preOrder,0,n-1,0,n-1);
}

void preOrderPrint(BTNode<int> *root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

int main(){
    vector<int> inOrder = {3,9,20,15,7};
    vector<int> preOrder = {9,3,15,20,7};

    BTNode<int> *root = builtTree(inOrder,preOrder);
    preOrderPrint(root);

    return 0;
}