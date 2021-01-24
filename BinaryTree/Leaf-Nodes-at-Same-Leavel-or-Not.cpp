//Leaf at same level or not
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

bool helper(BTNode<int> *root,int level,int *leafLevel){
    if(root == NULL) return true;
    if(root->left == NULL && root->right == NULL){
        if(*leafLevel == 0){
            *leafLevel = level;
            return true;
        }
        return (level == *leafLevel);
    }
    return helper(root->left,level+1,leafLevel) && helper(root->right,level+1,leafLevel);
}

bool isLeafSameLevel(BTNode<int> *root){
    int level = 0;
    int leafLevel = 0;
    return helper(root,level,&leafLevel);
}

int main(){
    BTNode<int> *root = new BTNode<int>(1);
    root->left = new BTNode<int>(2);
    root->right = new BTNode<int>(3);
    root->left->left = new BTNode<int>(4);
    root->left->right = new BTNode<int>(5);
    root->right->left = new BTNode<int>(6);
    root->right->right = new BTNode<int>(7);

    (isLeafSameLevel(root) == 1) ? cout<<"Leaf is at Same Level"
                                 : cout<<"Leaf is not at Same Level";

    return 0;
}