// find the lca of two nodes in a BST

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
    void PrintTree(BTNode<int> *root){
        if(root == NULL) return;
        cout<<root->data<<": ";
        if(root->left) cout<<"L->"<<root->left->data<<", ";
        if(root->right) cout<<"R->"<<root->right->data;
        cout<<endl;
        PrintTree(root->left);
        PrintTree(root->right);
    }
    BTNode<int> *findLCA(BTNode<int> *node,int val1,int val2){
        if(node == NULL) return NULL;
        if(node->data == val1 || node->data == val2){
            return node;
        }
        BTNode<int> *left = findLCA(node->left,val1,val2);
        BTNode<int> *right = findLCA(node->right,val1,val2);
        if(left && right) return node;
        if(left) return left;
        else return right;
    }
    public:
        BST(){
            root = NULL;
        }
        void insert(int data){
            root = insert(root,data);
        }
        void PrintTree(){
            PrintTree(root);
        }
        void LCA(int val1,int val2){
            BTNode<int> *lca = findLCA(root,val1,val2);
            cout<<lca->data;
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

    b.PrintTree();
    cout<<"\nThe lowest common ancestor in a BST : ";
    b.LCA(3,7);
    cout<<"\nThe lowest common ancestor in a BST : ";
    b.LCA(3,10);
    cout<<"\nThe lowest common ancestor in a BST : ";
    b.LCA(7,15);



    return 0;
}