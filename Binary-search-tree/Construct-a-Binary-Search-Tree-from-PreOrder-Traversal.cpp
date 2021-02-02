// Construct a Binary search tree from preOrder Traversal

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

BTNode<int> *insert(BTNode<int> *root,int node){
    if(!root) return new BTNode<int>(node);
    if(node < root->data){
        root->left = insert(root->left,node);
    }else{
        root->right = insert(root->right,node);
    }
    return root;
}

BTNode<int> *constructBST(vector<int> preOrder){
    BTNode<int> *root = new BTNode<int>(preOrder[0]);
    for(int start=1; start<preOrder.size(); start++){
        root = insert(root,preOrder[start]);
    }
    return root;
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

int main(){
    vector<int> preOrder = {8,5,1,7,10,12};
    BTNode<int> *root = constructBST(preOrder);
    PrintTree(root);

    return 0;
}