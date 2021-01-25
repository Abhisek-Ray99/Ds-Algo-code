// Find LCA(lowest common ancestor) in a binary Tree

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

BTNode<int> *FindLCA(BTNode<int> *root,int num1,int num2){
    if(root == NULL) return NULL;
    if(root->data == num1 || root->data == num2) return root;
    BTNode<int> *left = FindLCA(root->left,num1,num2);
    BTNode<int> *right = FindLCA(root->right,num1,num2);
    if(left && right) return root;
    if(left) return left;
    else return right;
}

int main(){
    BTNode<int> *root = new BTNode<int>(1);
    root->left = new BTNode<int>(2);
    root->right = new BTNode<int>(3);
    root->left->left = new BTNode<int>(6);
    root->left->right = new BTNode<int>(7);
    root->right->right = new BTNode<int>(4);
    root->left->right->right = new BTNode<int>(8);
    root->right->right->right = new BTNode<int>(5);

    cout<<"\nLCA of (6,5) : "<<FindLCA(root,6,5)->data;
    cout<<"\nLCA of (2,8) : "<<FindLCA(root,2,8)->data;
    cout<<"\nLCA of (6,7) : "<<FindLCA(root,6,7)->data;

    return 0;
}