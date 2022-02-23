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
    vector<int> preorder;
    vector<int> postorder;
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
    void getPreorder(TreeNode *root){
        if(root == NULL) return;
        preorder.push_back(root->data);
        getPreorder(root->left);
        getPreorder(root->right);
    }
    void getPostorder(TreeNode *root){
        if(root == NULL) return;
        getPostorder(root->left);
        getPostorder(root->right);
        postorder.push_back(root->data);
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
        void printInorder(){
            getInorder(root);
            for(auto it:inorder) cout<<it<<" ";
        }
        void printPreorder(){
            getPreorder(root);
            for(auto it:preorder) cout<<it<<" ";
        }
        void printPostorder(){
            getPostorder(root);
            for(auto it:postorder) cout<<it<<" ";
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
    b.printInorder();
    cout<<endl;
    b.printPreorder();
    cout<<endl;
    b.printPostorder();

    return 0;
}
