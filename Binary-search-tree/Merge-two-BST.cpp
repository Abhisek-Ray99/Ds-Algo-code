// merge two BST

#include<iostream>
#include<vector>
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
    
void printTree(BTNode<int> *root){
    if(root == NULL) return;
    cout<<root->data<<": ";
    if(root->left) cout<<"L->"<<root->left->data<<", ";
    if(root->right) cout<<"R->"<<root->right->data;
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}
void inOrder(BTNode<int> *root,vector<int> &arr){
    if(root){
        inOrder(root->left,arr);
        arr.push_back(root->data);
        inOrder(root->right,arr);
    }
}
void merge(vector<int> &arr1,vector<int> &arr2,vector<int> &result){
    int start1=0,start2=0;
    while(start1 < arr1.size() && start2 < arr2.size()){
        if(arr1[start1] > arr2[start2]){
            result.push_back(arr2[start2]);
            start2 = start2+1;
        }else{
            result.push_back(arr1[start1]);
            start1 = start1+1;
        }
    }
    while(start1 < arr1.size()){
        result.push_back(arr1[start1]);
        start1 = start1+1;
    }
    while(start2 < arr2.size()){
        result.push_back(arr2[start2]);
        start2 = start2+1;
    }
}
vector<int> mergeOfTwoBST(BTNode<int> *root1,BTNode<int> *root2){
    vector<int> arr1;
    vector<int> arr2;
    inOrder(root1,arr1);
    inOrder(root2,arr2);
    vector<int> result;
    merge(arr1,arr2,result);
    return result;
}
BTNode<int> *sortedArrToBST(vector<int> &arr,int start,int end){
    if(start > end) return NULL;
    int mid = start+(end-start)/2;
    BTNode<int> *root = new BTNode<int>(arr[mid]);
    root->left = sortedArrToBST(arr,start,mid-1);
    root->right = sortedArrToBST(arr,mid+1,end);
    return root;
}



int main(){
    BTNode<int> *root1 = new BTNode<int>(3);
    root1->left = new BTNode<int>(2);
    root1->right = new BTNode<int>(5);
    cout<<"The 1st BST is : "<<endl;
    printTree(root1);

    BTNode<int> *root2 = new BTNode<int>(4);
    root2->left = new BTNode<int>(1);
    root2->right = new BTNode<int>(6);
    cout<<"The 2nd BST is : "<<endl;
    printTree(root2);

    vector<int> result = mergeOfTwoBST(root1,root2);
    BTNode<int> *root = sortedArrToBST(result,0,result.size()-1);
    cout<<"The final BST is : "<<endl;
    printTree(root);

    return 0;
}