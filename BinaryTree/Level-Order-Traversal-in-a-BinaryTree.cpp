//level order traversal in a binary Tree

#include<iostream>
#include<queue>
using namespace std;

class BTNode{
    public:
        int data;
        BTNode *left;
        BTNode *right;
        BTNode(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

BTNode *takeInputLevelwise(){
    int rootdata;
    cout<<"Enter the Tree : ";
    cin>>rootdata;
    BTNode *root = new BTNode(rootdata);
    queue<BTNode *> q;
    q.push(root);
    while(!q.empty()){
        BTNode *f = q.front();
        q.pop();
        cout<<"Enter the left child of "<<f->data<<endl;
        int leftchild;
        cin>>leftchild;
        if(leftchild != -1){
            BTNode *child = new BTNode(leftchild);
            q.push(child);
            f->left = child;
        }
        cout<<"Enter the right child of "<<f->data<<endl;
        int rightchild;
        cin>>rightchild;
        if(rightchild != -1){
            BTNode *child = new BTNode(rightchild);
            q.push(child);
            f->right = child;
        }
    }
    return root;
}

void levelOrder(BTNode *root){
    if(root == NULL) return;
    queue<BTNode *> q;
    q.push(root);
    while(!q.empty()){
        root = q.front();
        cout<<root->data<<" ";
        q.pop();
        if(root->left) q.push(root->left);
        if(root->right) q.push(root->right);
    }
}

int main(){
    BTNode *root = takeInputLevelwise();
    cout<<"\nThe level Order Traversal of Binary Tree is : ";
    levelOrder(root);

    return 0;
}