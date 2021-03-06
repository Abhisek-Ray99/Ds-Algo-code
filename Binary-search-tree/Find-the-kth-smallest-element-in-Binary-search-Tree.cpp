// find kth smallest element in BST

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
    void kthSmallest(BTNode<int> *node,int k,int &count){
        if(node == NULL || count >= k) return;
        kthSmallest(node->left,k,count);
        count++;
        if(count == k){
            cout<<"The "<<k<<"th smallest element in the BST is : "<<node->data<<endl;
            return;
        }
        kthSmallest(node->right,k,count);
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
        void kthSmallest(int k){
            int count = 0;
            kthSmallest(root,k,count);
        }
};

int main(){
    BST b;
    b.insert(10);
    b.insert(5);
    b.insert(16);
    b.insert(12);
    b.insert(22);
    b.insert(18);
    b.insert(8);

    b.PrintTree();
    b.kthSmallest(4);

    return 0;
}