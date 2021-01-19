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

BTNode<int> *takeInput(){
    int rootdata;
    cout<<"Enter the Tree : ";
    cin>>rootdata;
    BTNode<int> *root = new BTNode<int>(rootdata);
    queue<BTNode<int>* > q;
    q.push(root);
    while(!q.empty()){
        BTNode<int> *f = q.front();
        q.pop();
        cout<<"Enter the left child of "<<f->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata != -1){
            BTNode<int> *child = new BTNode<int>(leftdata);
            q.push(child);
            f->left = child;
        }
        cout<<"Enter the right child of "<<f->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata != -1){
            BTNode<int> *child = new BTNode<int>(rightdata);
            q.push(child);
            f->right = child;
        }
    }
    return root;
}

void PrintBT(BTNode<int> *root){
    if(root == NULL) return;
    cout<<root->data<<" : ";
    if(root->left != NULL){
        cout<<root->left->data<<" ";
    }
    if(root->right != NULL){
        cout<<root->right->data<<" ";
    }
    cout<<endl;
    PrintBT(root->left);
    PrintBT(root->right);
}

int findHeight(BTNode<int> *root){
    if(root == NULL) return 0;
    int left = findHeight(root->left);
    int right = findHeight(root->right);
    return max(left,right) + 1;
}

int main(){
    BTNode<int> *root = takeInput();
    PrintBT(root);
    int height = findHeight(root);
    cout<<"The height of the binary tree is : "<<height;

    return 0;
}