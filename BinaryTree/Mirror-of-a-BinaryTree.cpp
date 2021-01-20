//Mirror of a binary Tree

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

void PrintBT(TreeNode<int> *root){
    if(root == NULL) return;
    cout<<root->data<<" : ";
    if(root->left != NULL){
        cout<<root->left->data<<" ";
    }
    if(root->right != NULL){
        cout<<root->right->data<<" ";
    }
    cout<<endl;
    PrintBT(root->left);
    PrintBT(root->right);
}

void mirror(TreeNode<int> *root){
    if(root == NULL) return;
    else{
        TreeNode<int> *temp;
        mirror(root->left);
        mirror(root->right);
        //swap the nodes
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

int main(){
    TreeNode<int> *root = takeInput();
    cout<<"The initial Tree : ";
    PrintBT(root);
    mirror(root);
    cout<<"\nThe mirror Tree is : ";
    PrintBT(root);

    return 0;
}