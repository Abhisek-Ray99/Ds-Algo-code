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

void leftview(BTNode<int> *root){
    queue<BTNode<int>* > q;
    if(!root) return;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        cout<<q.front()->data<<" ";
        while(size--){
            root = q.front();
            q.pop();
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
        }
    }
}

int main(){
    BTNode<int> *root = new BTNode<int>(1);
    root->left = new BTNode<int>(2);
    root->right = new BTNode<int>(3);
    root->right->left = new BTNode<int>(4);
    root->right->right = new BTNode<int>(5);
    cout<<endl;
    leftview(root);

    return 0;
}