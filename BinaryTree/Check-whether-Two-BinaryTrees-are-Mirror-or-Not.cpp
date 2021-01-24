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

int isMirrorTwoTree(BTNode<int> *root1,BTNode<int> *root2){
    if(root1 == NULL && root2 == NULL) return 1;
    if(root1 == NULL || root2 == NULL) return 0;
    return root1->data == root2->data && isMirrorTwoTree(root1->left,root2->right) && isMirrorTwoTree(root1->right,root2->left);
}

int main(){
    BTNode<int> *root1 = new BTNode<int>(1);
    root1->left = new BTNode<int>(2);
    root1->right = new BTNode<int>(3);
    root1->left->left = new BTNode<int>(4);
    root1->left->right = new BTNode<int>(5);
    root1->right->left = new BTNode<int>(6);
    root1->right->right = new BTNode<int>(7);

    BTNode<int> *root2 = new BTNode<int>(1);
    root2->left = new BTNode<int>(3);
    root2->right = new BTNode<int>(2);
    root2->left->left = new BTNode<int>(7);
    root2->left->right = new BTNode<int>(6);
    root2->right->left = new BTNode<int>(5);
    root2->right->right = new BTNode<int>(4);

    (isMirrorTwoTree(root1,root2) == 1) ? cout<<"Yaa ! it is Mirror" : cout<<"OH no! it is not a Mirror ";

    return 0;
}