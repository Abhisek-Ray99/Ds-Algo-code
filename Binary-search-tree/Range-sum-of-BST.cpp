// Range sum of BST

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
    int rangeSumBST(BTNode<int> *node,int L,int R){
        if(node == NULL) return 0;
        int sum = 0;
        if(node->data >= L && node->data <= R){
            sum += node->data;
        }
        if(node->data > R){
            sum += rangeSumBST(node->left,L,R);
        }else if(node->data < L){
            sum += rangeSumBST(node->right,L,R);
        }else{
            sum += rangeSumBST(node->left,L,R) + rangeSumBST(node->right,L,R);
        }
        return sum;
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
        void rangeSumBST(int L,int R){
           int sum = rangeSumBST(root,L,R);
           cout<<sum;
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
    int L=7,R=20;
    cout<<"The SUM in the range of "<<L<<" & "<<R<<" is : ";
    b.rangeSumBST(L,R);

    return 0;
}