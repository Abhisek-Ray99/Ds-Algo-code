#include<iostream>
#include<queue>
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

void printDiagonal(BTNode<int> *root){
    queue<BTNode<int>* > q;
    q.push(root);
    while(!q.empty()){
        BTNode<int> *temp = q.front();
        q.pop();
        while(temp){
            cout<<temp->data<<" ";
            if(temp->left) q.push(temp->left);
            temp = temp->right;
        }
    }
}

int main(){
    BTNode<int> *root = new BTNode<int>(1);
    root->left = new BTNode<int>(2);
    root->right = new BTNode<int>(3);
    root->left->left = new BTNode<int>(4);
    root->left->right = new BTNode<int>(5);
    root->right->left = new BTNode<int>(6);
    root->right->right = new BTNode<int>(7);
    cout<<"The diagonal Traversal of binary Tree is : ";
    printDiagonal(root);

    return 0;
}