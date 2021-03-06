// Level Order Traversal in a binary Tree using vector

#include<iostream>
#include<vector>
#include<queue>
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

BTNode<int> *takeInput(){
    int rootdata;
    cout<<"Enter the Tree : ";
    cin>>rootdata;
    BTNode<int> *root = new BTNode<int>(rootdata);
    queue<BTNode<int>* > q;
    q.push(root);
    while(!q.empty()){
        BTNode<int> *f = q.front();
        q.pop();
        cout<<"Enter the left child of "<<f->data<<endl;
        int leftchild;
        cin>>leftchild;
        if(leftchild != -1){
            BTNode<int> *child = new BTNode<int>(leftchild);
            q.push(child);
            f->left = child;
        }
        cout<<"Enter the right child of "<<f->data<<endl;
        int rightchild;
        cin>>rightchild;
        if(rightchild != -1){
            BTNode<int> *child = new BTNode<int>(rightchild);
            q.push(child);
            f->right = child;
        }
    }
    return root;
}

void PrintBT(BTNode<int> *root){
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

vector<int> PrintLevelOrder(BTNode<int> *root){
    vector<int> ans;
    if(!root) return ans;
    queue<BTNode<int>* > q;
    q.push(root);
    while(!q.empty()){
        BTNode<int> *f = q.front();
        q.pop();
        ans.push_back(f->data);
        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);
    }
    return ans;
}

int main(){
    BTNode<int> *root = takeInput();
    PrintBT(root);

    cout<<"\nThe level Order Traversal of Binary Tree is : ";
    vector<int> result = PrintLevelOrder(root);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }

    return 0;
}