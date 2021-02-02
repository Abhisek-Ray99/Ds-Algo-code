// Largest BST in Binary tree


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

class info{
    public:
    int min;
    int max;
    int size;
    bool isBST;
};

info LargeBST(BTNode<int> *root){
    info tree;
    if(root == NULL){
        tree.min = INT_MAX;
        tree.max = INT_MIN;
        tree.size = 0;
        tree.isBST = true;
        return tree;
    }
    if(root->left == NULL && root->right == NULL){
        tree.min = root->data;
        tree.max = root->data;
        tree.size = 1;
        tree.isBST = true;
        return tree;
    }
    info LeftTree = LargeBST(root->left);
    info RightTree = LargeBST(root->right);

    tree.min = min(LeftTree.min, min(RightTree.min,root->data));
    tree.max = max(LeftTree.max, max(RightTree.max,root->data));

    if(LeftTree.isBST && RightTree.isBST && root->data >= LeftTree.max && root->data <= RightTree.min){
        tree.isBST = true;
        tree.size = LeftTree.size + RightTree.size + 1;
        return tree;
    }
    tree.isBST = false;
    tree.size = max(LeftTree.size,RightTree.size);
    return tree;
}

int main(){
    BTNode<int> *root = new BTNode<int>(12);
    root->left = new BTNode<int>(8);
    root->right = new BTNode<int>(16);
    root->left->left = new BTNode<int>(3);
    root->left->right = new BTNode<int>(10);
    root->right->left = new BTNode<int>(14);
    root->right->right = new BTNode<int>(20);
    root->right->left->left = new BTNode<int>(11);

    info result = LargeBST(root);
    cout<<"The size of largest BST in Binary tree is : "<<result.size;
    

    return 0;
}