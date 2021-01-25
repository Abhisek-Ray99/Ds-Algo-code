// Maximum Sum of nodes in Binary tree such that no two are adjacent 


#include<iostream>
#include<unordered_map>
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

int maxSumNodes(BTNode<int> *root){
    unordered_map<BTNode<int>*,int> dp;
    if(root == NULL) return 0;
    if(dp[root]) return dp[root];
    int inc = root->data;
    if(root->left){
        inc += maxSumNodes(root->left->left);
        inc += maxSumNodes(root->left->right);
    }
    if(root->right){
        inc += maxSumNodes(root->right->left);
        inc += maxSumNodes(root->right->right);
    }
    int exc = maxSumNodes(root->left) + maxSumNodes(root->right);
    dp[root] = max(inc,exc);
    return dp[root];
}

int main(){
    BTNode<int> *root = new BTNode<int>(1);
    root->left = new BTNode<int>(2);
    root->right = new BTNode<int>(3);
    root->left->left = new BTNode<int>(4);
    root->left->right = new BTNode<int>(5);
    root->right->left = new BTNode<int>(6);
    root->right->right = new BTNode<int>(7);

    cout<<"The maximum sum of nodes in binary Tree is : "<<maxSumNodes(root);

    return 0;
}