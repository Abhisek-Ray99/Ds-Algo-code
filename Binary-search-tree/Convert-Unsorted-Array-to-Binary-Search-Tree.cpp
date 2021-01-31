// Unsorted array to BST

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

BTNode<int> *convertToBST(vector<int> arr,int start,int end){
    if(start > end) return NULL;
    sort(arr.begin(),arr.end());
    int mid = start+(end-start)/2;
    BTNode<int> *root = new BTNode<int>(arr[mid]);
    root->left = convertToBST(arr,start,mid-1);
    root->right = convertToBST(arr,mid+1,end);
    return root;
}

void PrintTree(BTNode<int> *root){
    if(root == NULL) return;
    cout<<root->data<<": ";
    if(root->left) cout<<"L->"<<root->left->data<<", ";
    if(root->right) cout<<"R->"<<root->right->data;
    cout<<endl;
    PrintTree(root->left);
    PrintTree(root->right);
}

int main(){
    vector<int> arr = {12,4,1,6,18,16,20};
    int size = arr.size();
    BTNode<int> *root = convertToBST(arr,0,size-1);
    PrintTree(root);

    return 0;
}