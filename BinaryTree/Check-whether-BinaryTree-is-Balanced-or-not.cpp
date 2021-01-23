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

int height(BTNode<int> *root){
    if(root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(BTNode<int> *root){
    if(root == NULL) return 1;
    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right)) return 1;
    return 0;
}

int main(){
    BTNode<int> *root = new BTNode<int>(1);
    root->left = new BTNode<int>(2);
    root->right = new BTNode<int>(3);
    root->left->left = new BTNode<int>(4);
    root->left->left->right = new BTNode<int>(6);

    (isBalanced(root) == 1) ? cout<<"Yahoo ! it is balanced Tree" : cout<<"Oops ! it is not a balanced Tree";

    return 0;
}