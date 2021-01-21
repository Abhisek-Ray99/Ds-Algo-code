#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
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

void zigzagBT(BTNode<int> *root){
    vector<int> ans;
    queue<BTNode<int>* > q;
    if(!root) return;
    q.push(root);
    int f = 1;
    while(!q.empty()){
        vector<int> temp;
        int size = q.size();
        while(size--){
            BTNode<int> *f = q.front();
            temp.push_back(f->data);
            q.pop();
            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
        }
        if(f % 2 == 0) reverse(temp.begin(),temp.end());
        for(int i=0; i<temp.size(); i++){
            ans.push_back(temp[i]);
        }
        f = !f;
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    BTNode<int> *root = new BTNode<int>(7);
    root->left = new BTNode<int>(9);
    root->right = new BTNode<int>(7);
    root->left->left = new BTNode<int>(8);
    root->left->right = new BTNode<int>(5);
    root->right->left = new BTNode<int>(6);
    root->left->left->left = new BTNode<int>(12);
    root->left->left->right = new BTNode<int>(10);

    cout<<"The zigzag traversal of the Binary Tree is : ";
    zigzagBT(root);

    return 0;
}