#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

void printBinaryTree(TreeNode *root){
    if(root == NULL) return;
    cout<<root->data<<": ";
    if(root->left != NULL){
        cout<<"L-> "<<root->left->data<<" ";
    }
    if(root->right != NULL){
        cout<<"R-> "<<root->right->data;
    }
    cout<<endl;
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}

int main(){
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);
    TreeNode *root = n1;
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n3->right = n5;
    printBinaryTree(root);

    return 0;
}
