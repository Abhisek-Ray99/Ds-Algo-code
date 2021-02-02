// populate InOrder successor of all nodes

#include<iostream>
using namespace std;

template<typename T>
class BTNode{
    public:
        T data;
        BTNode *left;
        BTNode *right;
        BTNode *next;
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
    void populate(BTNode<int> *node, BTNode<int> **next){
        if(node != NULL){
            populate(node->right,next);
            node->next = *next;
            *next = node;
            populate(node->left,next);
        }
    }
    public:
        BST(){
            root = NULL;
        }
        void insert(int data){
            root = insert(root,data);
        }
        void populateSuccessor(){
            BTNode<int> *next = NULL;
            populate(root,&next);
            BTNode<int> *pointer = root->left->left;
            while(pointer != NULL){
                if(pointer->next){
                    cout<<"Next of "<<pointer->data<<" is "<<pointer->next->data<<endl;
                    pointer = pointer->next;
                }else{
                    cout<<"Next of "<<pointer->data<<" is "<<-1<<endl;
                    pointer = pointer->next;
                }
            }
        }
};

int main(){
    BST b;
    b.insert(10);
    b.insert(12);
    b.insert(8);
    b.insert(3);

    b.populateSuccessor();
    

    return 0;
}