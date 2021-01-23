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

int sumTree(BTNode<int> *root){
    if(!root) return 0;
    int leftNode = sumTree(root->left);
    int rightNode = sumTree(root->right);
    int rootNode = root->data;
    root->data = leftNode + rightNode;
    return leftNode + rightNode + rootNode;
}

void printInorder(BTNode<int> *root){
    if(root == NULL) return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main(){
    BTNode<int> *root = new BTNode<int>(1);
    root->left = new BTNode<int>(2);
    root->right = new BTNode<int>(3);
    root->left->left = new BTNode<int>(-4);
    root->left->right = new BTNode<int>(5);
    root->right->left = new BTNode<int>(-6);
    root->right->right = new BTNode<int>(7);

    cout<<"The Inorder Traversal of inital Tree : ";
    printInorder(root);
    sumTree(root);
    cout<<"\nThe Inorder Traversal of SUM Tree : ";
    printInorder(root);

    return 0;
}