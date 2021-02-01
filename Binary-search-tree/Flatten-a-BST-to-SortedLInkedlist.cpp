// Convert BST to sorted LinkedList using inOrder Traversal
// Flatten a BST to sorted Linkedlist

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
    void inorder(BTNode<int> *curr, BTNode<int> *&prev){ 
        if (curr == NULL) return; 
        inorder(curr->left, prev); 
        prev->left = NULL; 
        prev->right = curr; 
        prev = curr; 
        inorder(curr->right, prev); 
    } 
    BTNode<int> *convertBSTtoLL(BTNode<int> *root){ 
        BTNode<int> *dummy = new BTNode<int>(-1);  
        BTNode<int>* prev = dummy;  
        inorder(root, prev); 
        prev->left = NULL; 
        prev->right = NULL; 
        BTNode<int> *ret = dummy->right; 
        delete dummy; 
        return ret; 
    } 
    void PrintLL(BTNode<int> *root){
        BTNode<int> *temp = root;
        while(temp != NULL){
            cout<<temp->data<<"-> ";
            temp = temp->right;
        }
    }
    public:
        BST(){
            root = NULL;
        }
        void insert(int data){
            root = insert(root,data);
        }
        void converBSTtoLL(){
            root = convertBSTtoLL(root);
        }
        void PrintLL(){
            PrintLL(root);
        }
};

int main(){
    BST b;
    b.insert(4);
    b.insert(2);
    b.insert(6);
    b.insert(1);
    b.insert(3);
    b.insert(5);
    b.insert(7);

    b.converBSTtoLL();
    b.PrintLL();

    return 0;
}