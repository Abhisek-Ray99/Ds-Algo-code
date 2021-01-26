// check whether a Binary Tree contains duplicate subtree of size 2 or more

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

unordered_map<string,int> m;
string helper(BTNode<int> *root){
    if(root == NULL) return "null";
    string s = "";
    if(!root->right && !root->left){
        s = to_string(root->data);
        return s;
    }
    s = s + to_string(root->data);
    s = s + helper(root->left);
    s = s + helper(root->right);
    m[s]++;
    return s;
}

bool isDuplicateSubTree(BTNode<int> *root){
    m.clear();
    helper(root);
    for(auto x:m){
        if(x.second >= 2) return true;
    }
    return false;
}

int main(){
    BTNode<int> *root = new BTNode<int>(1);
    root->left = new BTNode<int>(2);
    root->right = new BTNode<int>(3);
    root->left->left = new BTNode<int>(4);
    root->left->right = new BTNode<int>(5);
    root->right->right = new BTNode<int>(2);
    root->right->right->left = new BTNode<int>(4);
    root->right->right->right = new BTNode<int>(5);

    (isDuplicateSubTree(root) == 1) ? cout<<"Yahoo !! duplicate Subtree found" : cout<<"Oops !! No duplicate Subtree is found";

    return 0;
}