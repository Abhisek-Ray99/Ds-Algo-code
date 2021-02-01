// Count nodes in the BST lies in the given Range

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
    int CountNodesinRange(BTNode<int> *node,int range1,int range2){
        if(node == NULL) return 0;
        if(node->data == range1 && node->data == range2) return 1;
        if(node->data >= range1 && node->data <= range2){
            return 1+CountNodesinRange(node->left,range1,range2)+
                     CountNodesinRange(node->right,range1,range2);
        }else if(node->data < range1){
            return CountNodesinRange(node->right,range1,range2);
        }else{
            return CountNodesinRange(node->left,range1,range2);
        }
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
        void CountNodesinRange(int range1,int range2){
            int count = CountNodesinRange(root,range1,range2);
            cout<<count;
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

    int rangeFrom = 7;
    int rangeTo = 25;
    cout<<"The Nodes lies in the range of "<<rangeFrom<<" to "<<rangeTo<<" is : ";
    b.CountNodesinRange(rangeFrom,rangeTo);


    return 0;
}