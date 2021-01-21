//top view of binary tree using map

#include<iostream>
#include<queue>
#include<map>
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

void topviewBT(BTNode<int> *root){
    map<int,int> m;
    queue<pair<BTNode<int>*,int> > q;
    if(!root) return;
    q.push({root,0});
    while(!q.empty()){
        BTNode<int> *f = q.front().first;
        int height = q.front().second;
        q.pop();
        if(!m[height]) m[height] = f->data;
        if(f->left) q.push({f->left, height-1});
        if(f->right) q.push({f->right, height+1});
    }
    for(auto x:m) cout<<x.second<<" ";
}

int main(){
    BTNode<int> *root = new BTNode<int>(1);
    root->left = new BTNode<int>(2);
    root->right = new BTNode<int>(3);
    root->left->left = new BTNode<int>(4);
    root->left->right = new BTNode<int>(5);
    root->right->left = new BTNode<int>(6);
    root->right->right = new BTNode<int>(7);

    cout<<"The top view of the Binary Tree is : ";
    topviewBT(root);

    return 0;
}