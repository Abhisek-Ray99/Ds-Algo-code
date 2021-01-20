///find the diameter of binary Tree using pair

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
        int leftdata;
        cin>>leftdata;
        if(leftdata != -1){
            TreeNode<int> *child = new TreeNode<int>(leftdata);
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

pair<int,int> heightDiameter(TreeNode<int> *root){
    if(root == NULL){
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int,int> leftAns = heightDiameter(root->left);
    pair<int,int> rightAns = heightDiameter(root->right);

    int lh = leftAns.first;
    int ld = leftAns.second;
    int rh = rightAns.first;
    int rd = rightAns.second;

    int height = 1 + max(lh,rh);
    int diameter = max(lh+rh,max(ld,rd));
    pair<int,int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

int diameterOfBT(TreeNode<int>* root){
    pair<int,int> p = heightDiameter(root); 
    return p.second;
}

int main(){
    TreeNode<int> *root = takeInput();
    PrintTree(root);
    int diameter = diameterOfBT(root);
    cout<<"The diameter of binary Tree is : "<<diameter;

    return 0;
}