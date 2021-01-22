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

int maxValue(BTNode<int> *root){
    if(root == NULL) return INT_MIN;
    int leftMax = maxValue(root->left);
    int rightMax = maxValue(root->right);
    return max(root->data,max(leftMax,rightMax));
}

int main(){
    BTNode<int> *root = new BTNode<int>(100);
    root->left = new BTNode<int>(80);
    root->right = new BTNode<int>(90);
    root->left->left = new BTNode<int>(70);
    root->left->right = new BTNode<int>(600);
    root->right->left = new BTNode<int>(50);
    root->right->right = new BTNode<int>(40);
    
    int result = maxValue(root);
    cout<<"The maximum value in the Binary Tree is : "<<result;

    return 0;
}