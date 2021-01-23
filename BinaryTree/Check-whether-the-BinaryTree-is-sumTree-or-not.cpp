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

int sum(BTNode<int> *root){
    if(!root) return 0;
    return sum(root->left) + root->data + sum(root->right);
}

bool isSumTree(BTNode<int> *root){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return 1;
    }
    int leftTree = sum(root->left);
    int rightTree = sum(root->right);
    if((root->data == leftTree+rightTree) && isSumTree(root->left) && isSumTree(root->right)){
        return 1;
    }
    return 0;
}



int main(){
    BTNode<int> *root = new BTNode<int>(20);
    root->left = new BTNode<int>(6);
    root->right = new BTNode<int>(4);
    root->left->left = new BTNode<int>(1);
    root->left->right = new BTNode<int>(5);
    root->right->left = new BTNode<int>(2);
    root->right->right = new BTNode<int>(2);

    (isSumTree(root) == 1) ? cout<<"Yahoo ! it is a sum Tree"
                           : cout<<"OH no ! it is not a sum Tree";

    return 0;
}