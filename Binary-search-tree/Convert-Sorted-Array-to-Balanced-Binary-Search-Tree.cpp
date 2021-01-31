//Convert from Sorted array to Balanced BST


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

void PrintTree(BTNode<int> *root){
    if(root == NULL) return;
    cout<<root->data<<": ";
    if(root->left) cout<<"L->"<<root->left->data<<", ";
    if(root->right) cout<<"R->"<<root->right->data;
    cout<<endl;
    PrintTree(root->left);
    PrintTree(root->right);
}

BTNode<int> *convertToBST(int arr[],int start,int end){
    if(start > end) return NULL;
    int mid = start + (end-start)/2;
    BTNode<int> *root = new BTNode<int>(arr[mid]);
    root->left = convertToBST(arr,start,mid-1);
    root->right = convertToBST(arr,mid+1,end);
    return root;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    int size = sizeof(arr)/sizeof(arr[0]);

    BTNode<int> *root = convertToBST(arr,0,size-1);
    PrintTree(root);

}