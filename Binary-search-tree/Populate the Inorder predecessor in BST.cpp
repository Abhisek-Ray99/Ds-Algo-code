#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode *left;
        TreeNode *right;
        TreeNode *next;
        TreeNode(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
            this->next = NULL;
        }
};

class BST{
    TreeNode *root;
    TreeNode *insert(TreeNode *root,int node){
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
        if(root->left) cout<<"L->"<<root->left->data<<", ";
        if(root->right) cout<<"R->"<<root->right->data;
        cout<<endl;
        printBST(root->left);
        printBST(root->right);
    }
    void populateIn_predecessor(TreeNode *root,TreeNode *&prev){
        if(root == NULL) return;
        populateIn_predecessor(root->right,prev);
        if(prev != NULL){
            prev->next = root;
        }
        prev = root;
        populateIn_predecessor(root->left,prev);
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
        void populateIn_predecessor(){
            TreeNode *prev = NULL;
            populateIn_predecessor(root,prev);
            TreeNode *start = root;
            while(start->right != NULL){
                start = start->right;
            }
            while(start != NULL){
                if(start->next == NULL){
                    cout<<prev->data<<"->"<<"NULL";
                }else{
                    cout<<start->data<<"->"<<start->next->data<<" ";
                }
                start = start->next;
            }
        }
};

int main(){
    BST b;
    b.insert(12);
    b.insert(6);
    b.insert(28);
    b.insert(4);
    b.insert(10);
    b.insert(30);
    b.insert(22);
    b.insert(9);
    b.printBST();
    b.populateIn_predecessor();

    return 0;
}
