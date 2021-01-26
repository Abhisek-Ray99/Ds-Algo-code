// print all duplicate subtree in binary tree

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
            left= NULL;
            right = NULL;
        }
};

string helper(BTNode<int> *root, unordered_map<string,int> &m){
    if(root == NULL) return "";
    string s = "(";
    s += helper(root->left,m);
    s += to_string(root->data);
    s += helper(root->right,m);
    s += ")";
    if(m[s] == 1){
        cout<<root->data<<" ";
    }
    m[s]++;
    return s;
}

void PrintallSubTree(BTNode<int> *root){
    unordered_map<string,int> m;
    helper(root,m);
}

int main(){
    BTNode<int> *root = new BTNode<int>(1);
    root->left = new BTNode<int>(2);
    root->right = new BTNode<int>(3);
    root->left->left = new BTNode<int>(4);
    root->right->left = new BTNode<int>(2);
    root->right->right = new BTNode<int>(4);
    root->right->left->left = new BTNode<int>(4);
    cout<<"The duplicate subTree is : ";
    PrintallSubTree(root);
    
    return 0;
}