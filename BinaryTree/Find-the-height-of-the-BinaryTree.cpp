// -------------------------------------------------------First Method------------------------------------------------------🎃

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




// --------------------------------------------------------Another method---------------------------------------------------------



#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

void printTree(Node *root){
    if(root == NULL) return;
    cout<<root->data<<": ";
    if(root->left){
        cout<<"L-> "<<root->left->data<<" ";
    }
    if(root->right){
        cout<<"R-> "<<root->right->data<<" ";
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

int heightofBinaryTree(Node *root){
    if(root == NULL){
        return 0;
    }
    int maxHeight = 1;
    if(root->left != NULL){
        int height = 1 + heightofBinaryTree(root->left); 
        if(height >= maxHeight) maxHeight = height;
    }
    if(root->right != NULL){
        int height = 1 + heightofBinaryTree(root->right);
        if(height >= maxHeight) maxHeight = height;
    }
    return maxHeight;
}

int main(){
    Node *n1 = new Node(3);
    Node *n2 = new Node(2);
    Node *n3 = new Node(5);
    Node *n4 = new Node(1);
    Node *n5 = new Node(4);
    Node *n6 = new Node(6);
    Node *root = n1;
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n3->left = n5;
    n3->right = n6;
    printTree(root);
    int height = heightofBinaryTree(root);
    cout<<"height: "<<height;


    return 0;
}
