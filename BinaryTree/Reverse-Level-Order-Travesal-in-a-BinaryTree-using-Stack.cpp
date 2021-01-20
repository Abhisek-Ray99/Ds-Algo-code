//  reverse level order traversal in a binary Tree using stack

#include<iostream>
#include<queue>
#include<stack>
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

void reverseLevelOrder(BTNode *root){
    if(root == NULL) return;
    stack<BTNode *> s;
    queue<BTNode *> q;
    q.push(root);
    while(!q.empty()){
        root = q.front();
        q.pop();
        s.push(root);
        if(root->right) q.push(root->right);
        if(root->left) q.push(root->left);
    }
    while(!s.empty()){
        root = s.top();
        cout<<root->data<<" ";
        s.pop();
    }
}

int main(){
    BTNode *rootdata = new BTNode(1);
    rootdata->left = new BTNode(2);
    rootdata->right = new BTNode(3);
    rootdata->left->left = new BTNode(4);
    rootdata->left->right = new BTNode(5);
    rootdata->right->left = new BTNode(6);
    rootdata->right->right = new BTNode(7);

    cout<<"\nThe Level Order Traversal is : ";
    levelOrder(rootdata);
    cout<<"\nThe reverse Level Order Traversal is :";
    reverseLevelOrder(rootdata);

    return 0;
}