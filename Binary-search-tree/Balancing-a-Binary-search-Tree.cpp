// Balancing a Binary Search Tree

#include<iostream>
#include<vector>
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
    vector<BTNode<int>* > InOrder;
    void inOrder(BTNode<int> *root){
        if(!root) return;
        inOrder(root->left);
        InOrder.push_back(root);
        inOrder(root->right);
    }
    BTNode<int> *buildTree(int start,int end){
        if(start > end) return NULL;
        int mid = start+(end-start)/2;
        BTNode<int> *root = InOrder[mid];
        root->left = buildTree(start,mid-1);
        root->right = buildTree(mid+1,end);
        return root;
    }
    BTNode<int> *balancedBST(BTNode<int> *root){
        if(!root) return root;
        inOrder(root);
        int size = InOrder.size();
        return buildTree(0,size-1);
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
        void balaceTree(){
            root = balancedBST(root);
        }
};

int main(){
    BST b;
    b.insert(12);
    b.insert(18);
    b.insert(20);
    b.insert(22);
    b.insert(2);
    cout<<"The initial BST : "<<endl;
    b.PrintTree();
    b.balaceTree();
    cout<<"\nThe Balanced BST is : "<<endl;;
    b.PrintTree();

    return 0;
}