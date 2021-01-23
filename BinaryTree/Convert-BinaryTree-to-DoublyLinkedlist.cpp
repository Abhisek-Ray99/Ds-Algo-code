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

void helper(BTNode<int> *root,BTNode<int> *&head,BTNode<int> *&prev,int &f){
    if(!root) return;
    helper(root->left,head,prev,f);
    if(f == 0){
        f = 1;
        head = root;
        prev = root;
    }else{
        prev->right = root;
        prev->right->left = prev;
        prev = prev->right;
    }
    helper(root->right,head,prev,f);
}

BTNode<int> *BTtoDLL(BTNode<int> *root){
    BTNode<int> *head = NULL;
    BTNode<int> *prev = NULL;
    int f = 0;
    helper(root,head,prev,f);
    return head;
}

void printDLL(BTNode<int> *head){
    while(head != NULL){
        cout<<head->data<<" ->";
        head = head->right;
    }
}

int main(){
    BTNode<int> *root = new BTNode<int>(10);
    root->left = new BTNode<int>(12);
    root->right = new BTNode<int>(15);
    root->left->left = new BTNode<int>(25);
    root->left->right = new BTNode<int>(30);
    root->right->left = new BTNode<int>(36);

    BTNode<int> *head = BTtoDLL(root);
    printDLL(head);

    return 0;
}