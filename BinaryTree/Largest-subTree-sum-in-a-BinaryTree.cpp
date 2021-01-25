// Largest subTree Sum in a BinaryTree


#include<iostream>
#include<queue>
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

int helper(BTNode<int> *root){
    if(root == NULL) return 0;
    return helper(root->left) + helper(root->right) + root->data;
}

int largestSubTreeSum(BTNode<int> *root){
    if(root == NULL) return 0;
    queue<BTNode<int>* > q;
    q.push(root);
    int res = INT_MIN,sum;
    while(!q.empty()){
        BTNode<int> *f = q.front();
        q.pop();
        sum = helper(f);
        res = max(res,sum);
        if(f->left != NULL) q.push(f->left);
        if(f->right != NULL) q.push(f->right);
    }
    return res;
}

int main(){
    BTNode<int> *root = new BTNode<int>(-1);
    root->left = new BTNode<int>(-2);
    root->right = new BTNode<int>(-3);
    root->left->right = new BTNode<int>(5);
    root->right->left = new BTNode<int>(10);
    root->left->right->left = new BTNode<int>(6);

    int result = largestSubTreeSum(root);
    cout<<"The largest sumTree Sum is : "<<result;
    

    return 0;
}