//Print all the nodes at level k or Print all the nodes at depth-d 

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class TreeNode{
    public:
        int data;
        vector<TreeNode<T>* > children; 
        TreeNode(T data){
            this->data = data;
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
        TreeNode<int>* f = q.front();
        q.pop();
        cout<<"Enter the number of children of "<<f->data<<endl;
        int n;
        cin>>n;
        for(int i=1; i<=n; i++){
            cout<<"Enter "<<i<<" number child of "<<f->data<<endl;
            int childData;
            cin>>childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            q.push(child);
            f->children.push_back(child);
        }
    }
    return root;
}

void PrintTree(TreeNode<int> *root){
    queue<TreeNode<int>* > q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* f = q.front();
        q.pop();
        cout<<f->data<<" : ";
        for(int i=0; i<f->children.size(); i++){
            cout<<f->children[i]->data<<", ";
        } 
        cout<<endl;
        for(int i=0; i<f->children.size(); i++){
            q.push(f->children[i]);
        }
    }
}

void PrintAtLevelK(TreeNode<int> *root,int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout<<root->data<<endl;
        return;
    }
    for(int i=0; i<=root->children.size(); i++){
        PrintAtLevelK(root->children[i],k-1);
    }
}


int main(){
    TreeNode<int> *root = takeInput();
    PrintTree(root);
    cout<<"\nEnter the level for print all the nodes : ";
    int k;
    cin>>k;
    PrintAtLevelK(root,k);

    return 0;
}