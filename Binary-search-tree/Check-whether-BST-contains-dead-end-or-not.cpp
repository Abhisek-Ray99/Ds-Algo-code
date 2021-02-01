// check wether BST contains dead end or not

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
    bool isDeadEnd(BTNode<int> *node, int min, int max) { 
        if (!node) return false; 
        if (min == max) return true; 
        return isDeadEnd(node->left, min, node->data - 1) || 
            isDeadEnd(node->right, node->data + 1, max); 
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
        bool isDeadEnd(){
            int min = 1, max = INT_MAX;
            return isDeadEnd(root,min,max);
        }
};

int main(){
    BST b;
    b.insert(10);
    b.insert(5);
    b.insert(15);
    b.insert(20);
    b.insert(3);
    b.insert(7);
    b.PrintTree();

    (b.isDeadEnd() == 1) ? cout<<"yes !! BST contains Dead end"
                         : cout<<"No !! BST does contains Dead end";     


    return 0;
}