// PostOrder traversal

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
        int leftchildData;
        cin>>leftchildData;
        if(leftchildData != -1){
            BTNode<int> *rightchild = new BTNode<int>(leftchildData);
            q.push(rightchild);
            f->left = rightchild;
        }
        cout<<"Enter the right child of "<<f->data<<endl;
        int rightchildData;
        cin>>rightchildData;
        if(rightchildData != -1){
            BTNode<int> *rightchild = new BTNode<int>(rightchildData);
            q.push(rightchild);
            f->right = rightchild;
        }
    }
    return root;
}

void PrintBT(BTNode<int> *root){
    if(root == NULL) return;
    cout<<root->data<<" : ";
    if(root->left){
        cout<<root->left->data<<", ";
    }
    if(root->right){
        cout<<root->right->data<<", ";
    }
    cout<<endl;
    PrintBT(root->left);
    PrintBT(root->right);
}

void postOrder(BTNode<int> *root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main(){
    BTNode<int> *root = takeInput();
    PrintBT(root);
    cout<<"\nThe PostOrder Traversal of Binary Tree is : ";
    postOrder(root);

    return 0;
}
