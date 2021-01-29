// delete node in the Binary search Tree

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
        ~BTNode(){
            delete left;
            delete right;
        }
};

class BST{
    BTNode<int> *root;
    void printTree(BTNode<int> *root){
        if(root == NULL) return;
        cout<<root->data<<": ";
        if(root->left != NULL){
            cout<<"L->"<<root->left->data<<", ";
        }
        if(root->right != NULL){
            cout<<"R->"<<root->right->data;
        }
        cout<<endl;
        printTree(root->left);
        printTree(root->right);
    }
    BTNode<int> *insert(BTNode<int>*node,int data){
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
    BTNode<int> *deleteNode(BTNode<int> *node,int data){
        if(root == NULL) return 0;
        if(data < node->data){
            node->left = deleteNode(node->left,data);
        }else if(data > node->data){
            node->right = deleteNode(node->right,data);
        }else{
            if(node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            }else if(node->right == NULL){
                BTNode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }else if(node->left == NULL){
                BTNode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }else{
                BTNode<int> *minNode = node->right;
                while(minNode->left != NULL){
                    minNode = minNode->left;
                }
                int rightmin = minNode->data;
                node->data = rightmin;
                node->right = deleteNode(node->right,rightmin);
            }
        }
        return node;
    }
    public:
        BST(){
            root = NULL;
        }
        ~BST(){
            delete root;
        }
        void insert(int data){
            root = insert(root,data);
        }
        void printTree(){
            printTree(root);
        }
        void deleteNode(int data){
            deleteNode(root,data);
        }
};

int main(){
    BST b;
    b.insert(10);
    b.insert(5);
    b.insert(20);
    b.insert(15);
    b.insert(7);
    b.insert(3);
    b.printTree();

    cout<<"\nEnter the Node you want to delete : ";
    int node;
    cin>>node;
    b.deleteNode(node);
    b.printTree();

    return 0;
}