// populate InOrder successor of all nodes
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode *left;
        TreeNode *right;
        TreeNode *next;
        TreeNode(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
            this->next = NULL;
        }
};

class BST{
    TreeNode *root;
    TreeNode *insert(TreeNode *root,int node){
        if(root == NULL){
            TreeNode *newnode = new TreeNode(node);
            return newnode;
        }
        if(node < root->data){
            root->left = insert(root->left,node);
        }else{
            root->right = insert(root->right,node);
        }
        return root;
    }
    void printBST(TreeNode *root){
        if(root == NULL) return;
        cout<<root->data<<": ";
        if(root->left) cout<<"L->"<<root->left->data<<", ";
        if(root->right) cout<<"R->"<<root->right->data;
        cout<<endl;
        printBST(root->left);
        printBST(root->right);
    }
    void populateIn_successor(TreeNode *root,TreeNode *&prev){
        if(root == NULL) return;
        populateIn_successor(root->left,prev);
        if(prev != NULL){
            prev->next = root;
        }
        prev = root;
        populateIn_successor(root->right,prev);
    }
    public:
        BST(){
            root = NULL;
        }
        void insert(int node){
            root = insert(root,node);
        }
        void printBST(){
            printBST(root);
        }
        void populateIn_successor(){
            TreeNode *prev = NULL;
            populateIn_successor(root,prev);
            TreeNode *start = root;
            while(start->left != NULL){
                start = start->left;
            }
            while(start != NULL){
                if(start->next == NULL){
                    cout<<prev->data<<"->"<<"NULL";
                }else{
                    cout<<start->data<<"->"<<start->next->data<<" ";
                }
                start = start->next;
            }
        }
};

int main(){
    BST b;
    b.insert(12);
    b.insert(6);
    b.insert(28);
    b.insert(4);
    b.insert(10);
    b.insert(30);
    b.insert(22);
    b.insert(9);
    b.printBST();
    b.populateIn_successor();

    return 0;
}



// -----------------------------------------------------------------------------------Another method--------------------------------------------------------------------------


#include<iostream>
using namespace std;

template<typename T>
class BTNode{
    public:
        T data;
        BTNode *left;
        BTNode *right;
        BTNode *next;
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
    void populate(BTNode<int> *node, BTNode<int> **next){
        if(node != NULL){
            populate(node->right,next);
            node->next = *next;
            *next = node;
            populate(node->left,next);
        }
    }
    public:
        BST(){
            root = NULL;
        }
        void insert(int data){
            root = insert(root,data);
        }
        void populateSuccessor(){
            BTNode<int> *next = NULL;
            populate(root,&next);
            BTNode<int> *pointer = root->left->left;
            while(pointer != NULL){
                if(pointer->next){
                    cout<<"Next of "<<pointer->data<<" is "<<pointer->next->data<<endl;
                    pointer = pointer->next;
                }else{
                    cout<<"Next of "<<pointer->data<<" is "<<-1<<endl;
                    pointer = pointer->next;
                }
            }
        }
};

int main(){
    BST b;
    b.insert(10);
    b.insert(12);
    b.insert(8);
    b.insert(3);

    b.populateSuccessor();
    

    return 0;
}
