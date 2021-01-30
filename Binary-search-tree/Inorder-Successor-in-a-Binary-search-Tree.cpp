// InOrder successor in Binary Search Tree


#include<iostream>
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

class BST{
    BTNode<int> *root;
    BTNode<int> *insert(BTNode<int> *node,int data){
        if(node == NULL){
            BTNode<int> *n = new BTNode<int>(data);
            return n;
        }
        if(data < node->data){
            node->left = insert(node->left,data);
        }else{
            node->right = insert(node->right,data);
        }
        return node;
    }
    void printTree(BTNode<int> *root){
        if(root == NULL) return;
        cout<<root->data<<": ";
        if(root->left) cout<<"L->"<<root->left->data<<", ";
        if(root->right) cout<<"R->"<<root->right->data;
        cout<<endl;
        printTree(root->left);
        printTree(root->right);
    }
    BTNode<int> *findMin(BTNode<int> *root){
        while(root->left) root = root->left;
        return root;
    }
    void inorderSuccessor(BTNode<int> *node,int data,BTNode<int> **prev){
        if(node == NULL || !data) return;
        while(node){
            if(node->data > data){
                *prev = node;
                node = node->left;
            }else{
                node = node->right;
            }
        }
    }
    public:
        BST(){
            root = NULL;
        }
        void insert(int data){
            root = insert(root,data);
        }
        void printTree(){
            printTree(root);
        }
        void InOrderSuccessor(int data,BTNode<int> *&prev){
            inorderSuccessor(root,data,&prev);
        }
};

int main(){
    BST b;
    b.insert(10);
    b.insert(5);
    b.insert(20);
    b.insert(3);
    b.insert(7);
    b.insert(15);
    b.printTree();

    BTNode<int> *prev = NULL;
    b.InOrderSuccessor(10,prev);
    if(prev) cout<<"The Inorder Successor is : "<<prev->data;
    else cout<<"Not exits";

    return 0;
}