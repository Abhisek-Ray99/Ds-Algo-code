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

int minValue(BTNode<int> *root){
    if(root == NULL) return INT_MAX;
    int leftMin = minValue(root->left);
    int rightMin = minValue(root->right);
    return min(root->data,min(leftMin,rightMin));
}

int main(){
    BTNode<int> *root = new BTNode<int>(100);
    root->left = new BTNode<int>(80);
    root->right = new BTNode<int>(90);
    root->left->left = new BTNode<int>(70);
    root->left->right = new BTNode<int>(60);
    root->right->left = new BTNode<int>(50);
    root->right->right = new BTNode<int>(40);
    
    int result = minValue(root);
    cout<<"The minimum value in the Binary Tree is : "<<result;

    return 0;
}