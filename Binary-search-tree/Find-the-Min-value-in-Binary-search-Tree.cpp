// Find min value in Binary search Tree

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

class BST{
    BTNode<int> *root;
    BTNode<int> *insert(BTNode<int> *node, int data){
        if(node == NULL){
            BTNode<int> *n = new BTNode<int>(data);
            return n;
        }
        if(data < node->data){
            node->left = insert(node->left, data);
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
    void minNode(BTNode<int> *root){
        if(root == NULL) return;
        while(root->left != NULL){
            root = root->left;
        }
        cout<<root->data;
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
        void minNode(){
            minNode(root);
        }
};


int main(){
    BST b;
    b.insert(12);
    b.insert(25);
    b.insert(10);
    b.insert(2);
    b.insert(15);
    b.insert(20);
    b.printTree();
    
    cout<<"\nThe min node in value in the BST is : ";
    b.minNode();
    
    return 0;
}