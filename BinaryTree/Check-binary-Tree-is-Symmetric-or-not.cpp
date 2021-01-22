//check binary tree is symmetric or not

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

bool helper(BTNode<int> *leftTree, BTNode<int> *rightTree){
    //if leftNode and rightnode are null then return true;
    if(leftTree == NULL && rightTree == NULL) return true;
    if(leftTree != NULL && rightTree != NULL){
        return (leftTree->data == rightTree->data) && 
               helper(leftTree->left, rightTree->right) &&
               helper(leftTree->right, rightTree->left);
    }
    return false;
}

bool isSymmetric(BTNode<int> *root){
    if(root == NULL) return true;
    return helper(root->left, root->right);
}

int main(){
    BTNode<int> *root = new BTNode<int>(1);
    root->left = new BTNode<int>(2);
    // root->right = new BTNode<int>(2);
    // root->left->right = new BTNode<int>(3);
    // root->right->right = new BTNode<int>(3);

    (isSymmetric(root) == 1) ? cout<<"The tree is Symmetric"
                             : cout<<"The tree is not Symmetric";

    return 0;
}