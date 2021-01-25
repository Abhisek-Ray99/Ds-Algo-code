// The Sum of Nodes on the longest path from root to leafNode

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

void helper(BTNode<int> *root,int sum,int len,int &maxlen,int &maxSum){
    if(root == NULL){
        if(maxlen < len){
            maxlen = len;
            maxSum = sum;
        }else if (maxlen == len && maxSum < sum){
            maxSum = sum;
        }
        return;
    }
    helper(root->left,sum+root->data,len+1,maxlen,maxSum);
    helper(root->right,sum+root->data,len+1,maxlen,maxSum);
}

int sumofNodesLongestpath(BTNode<int> *root){
    if(root == NULL) return 0;
    int maxSum = INT_MIN;
    int maxlen = 0;
    helper(root,0,0,maxlen,maxSum);
    return maxSum;
}

int main(){
    BTNode<int> *root = new BTNode<int>(1);
    root->left = new BTNode<int>(2);
    root->right = new BTNode<int>(3);
    root->left->right = new BTNode<int>(5);
    root->right->left = new BTNode<int>(4);
    root->left->right->left = new BTNode<int>(6);

    int result = sumofNodesLongestpath(root);
    cout<<"The Sum of Nodes on the longest path from root to leafNode is : "<<result;
    

    return 0;
}