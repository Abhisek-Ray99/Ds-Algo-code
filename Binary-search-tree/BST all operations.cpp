#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

class BST{
    TreeNode *insert(TreeNode *root,int element){
        if(root == NULL){
            TreeNode *newNode = new TreeNode(element);
            return newNode;
        }
        if(element < root->data){
            root->left = insert(root->left,element);
        }else{
            root->right = insert(root->right,element);
        }
        return root;
    }
    TreeNode *deleteNode(TreeNode *root,int element){
        if(root == NULL) return NULL;
        if(element < root->data){
            root->left = deleteNode(root->left,element);
        }else if(element > root->data){
            root->right = deleteNode(root->right,element);
        }else{
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }else if(root->left != NULL && root->right == NULL){
                TreeNode *delNode = root;
                root = root->left;
                delNode->left = NULL;
                delete delNode;
                return root;
            }else if(root->left == NULL && root->right != NULL){
                TreeNode *delNode = root;
                root = root->right;
                delNode->right = NULL;
                delete delNode;
                return root;
            }else{
                TreeNode *minNode = root->right;
                while(minNode->left != NULL){
                    minNode = minNode->left;
                }
                int swapData = minNode->data;
                root->data = swapData;
                root->right = deleteNode(root->right,swapData);
            }
        }
        return root;
    }
    bool hasNode(TreeNode *root,int element){
        if(root == NULL) return false;
        if(element == root->data){
            return true;
        }
        if(element < root->data){
            return hasNode(root->left,element);
        }else{
            return hasNode(root->right,element);
        }
    }
    void printBST(TreeNode *root){
        if(root == NULL) return;
        cout<<root->data<<": ";
        if(root->left != NULL){
            cout<<"L-> "<<root->left->data;
        }
        if(root->right != NULL){
            cout<<"R-> "<<root->right->data;
        }
        cout<<endl;
        printBST(root->left);
        printBST(root->right);
    }
    public:
        TreeNode *root;
        BST(){
            root = NULL;
        }
        void insert(int element){
            root = insert(root,element);
        }
        void deleteNode(int element){
            root = deleteNode(root,element);
        }
        bool hasNode(int element){
            return hasNode(root,element);
        }
        void printBST(){
            printBST(root);
        }
};

int main(){
    BST Tree;
    Tree.insert(10);
    Tree.insert(2);
    Tree.insert(20);
    Tree.printBST();
    cout<<Tree.hasNode(20)<<endl;
    Tree.deleteNode(2);
    Tree.printBST();

    return 0;
}
