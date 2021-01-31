// Convert the Binary Tree to BST

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<typename T>
class BTNode{
    public:
        T data;
        BTNode *left;
        BTNode *right;
        BTNode(T data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

void PrintTree(BTNode<int> *root){
    if(root == NULL) return;
    cout<<root->data<<" : ";
    if(root->left) cout<<"L->"<<root->left->data<<", ";
    if(root->right) cout<<"R->"<<root->right->data;
    cout<<endl;
    PrintTree(root->left);
    PrintTree(root->right);
}

void inorder(BTNode<int> *root,vector<int> &arr){
    if(root == NULL) return;
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

void convertBTtoBST(BTNode<int> *root,vector<int> arr,int &start){
    if(root == NULL) return;
    convertBTtoBST(root->left,arr,start);
    root->data = arr[start++];
    convertBTtoBST(root->right,arr,start);
}

int main(){
    BTNode<int> *root = new BTNode<int>(12);
    root->left = new BTNode<int>(4);
    root->right = new BTNode<int>(6);
    root->left->left = new BTNode<int>(16);
    root->left->right = new BTNode<int>(1);
    root->right->left = new BTNode<int>(20);
    root->right->right = new BTNode<int>(18);
    cout<<"The intial BT is : "<<endl;
    PrintTree(root);
    vector<int> arr;
    inorder(root,arr);
    sort(arr.begin(),arr.end());
    int start = 0;
    convertBTtoBST(root,arr,start);
    cout<<"\nThe final BST is : "<<endl;
    PrintTree(root);

    return 0;
}