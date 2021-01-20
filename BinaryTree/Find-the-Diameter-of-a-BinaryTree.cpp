//find the diameter of binary tree

#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class TreeNode{
    public:
        int data;
        TreeNode *left;
        TreeNode *right;
        TreeNode(T data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

TreeNode<int> *takeInput(){
    int rootdata;
    cout<<"Enter the Tree : ";
    cin>>rootdata;
    TreeNode<int> *root = new TreeNode<int>(rootdata);
    queue<TreeNode<int>* > q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int> *f = q.front();
        q.pop();
        cout<<"Enter the left child of "<<f->data<<endl;
        int leftchild;
        cin>>leftchild;
        if(leftchild != -1){
            TreeNode<int> *child = new TreeNode<int>(leftchild);
            q.push(child);
            f->left = child;
        }
        cout<<"Enter the right child of "<<f->data<<endl;
        int rightchild;
        cin>>rightchild;
        if(rightchild != -1){
            TreeNode<int> *child = new TreeNode<int>(rightchild);
            q.push(child);
            f->right = child;
        }
    }
    return root;
}

void PrintTree(TreeNode<int> *root){
    if(root == NULL) return;
    cout<<root->data<<" : ";
    if(root->left != NULL){
        cout<<root->left->data<<" ";
    }
    if(root->right != NULL){
        cout<<root->right->data<<" ";
    }
    cout<<endl;
    PrintTree(root->left);
    PrintTree(root->right);
}
int height(TreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}
int diameterOfBinaryTree(TreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int option1 = height(root->left) + height(root->right);
    int option2 = diameterOfBinaryTree(root->left);
    int option3 = diameterOfBinaryTree(root->right);

    return max(option1, max(option2, option3));
}

int main(){
    TreeNode<int> *root = takeInput();
    PrintTree(root);
    int diameter = diameterOfBinaryTree(root);
    cout<<"\nThe diameter of binary Tree is : "<<diameter;

    return 0;
}