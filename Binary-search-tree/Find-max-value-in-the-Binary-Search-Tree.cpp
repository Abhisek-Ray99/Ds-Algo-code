// Find mix value in Binary Search Tree

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
    void printMaxvalue(BTNode<int> *root){
        if(root == NULL) return;
        while(root->right != NULL){
            root = root->right;
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
        void printMaxvalue(){
            printMaxvalue(root);
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
    cout<<"\nThe max value in the BST is : ";
    b.printMaxvalue();

    return 0;
}