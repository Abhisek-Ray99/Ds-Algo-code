#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

class BST{
    TreeNode *root;
    vector<int> inorder;
    TreeNode *insert(TreeNode *root, int node){
        if(root == NULL){
            TreeNode *newnode = new TreeNode(node);
            return newnode;
        }
        if(node < root->data){
            root->left = insert(root->left,node);
        }else{
            root->right = insert(root->right,node);
        }
        return root;
    }
    void printBST(TreeNode *root){
        if(root == NULL) return;
        cout<<root->data<<": ";
        if(root->left) cout<<"L->"<<root->left->data<<" ";
        if(root->right) cout<<"R->"<<root->right->data;
        cout<<endl;
        printBST(root->left);
        printBST(root->right);
    }
    void getInorder(TreeNode *root){
        if(root == NULL) return;
        getInorder(root->left);
        inorder.push_back(root->data);
        getInorder(root->right);
    }
    public:
        BST(){
            root = NULL;
        }
        void insert(int node){
            root = insert(root,node);
        }
        void printBST(){
            printBST(root);
        }
        void InorderPredecessor(int node){
            getInorder(root);
            for(int start=0; start<inorder.size(); start++){
                if(inorder[start] == node && inorder[0] == node){
                    cout<<"NULL";
                    return;
                }else if(inorder[start] == node){
                    cout<<inorder[start-1];
                    return;
                }
            }
        }
};

int main(){
    BST b;
    b.insert(12);
    b.insert(6);
    b.insert(20);
    b.insert(3);
    b.insert(8);
    b.insert(13);
    b.insert(24);
    b.printBST();
    b.InorderPredecessor(3);

    return 0;
}
