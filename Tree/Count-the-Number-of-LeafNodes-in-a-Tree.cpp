//count the leafnodes in a tree

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class TreeNode{
    public:
        int data;
        vector<TreeNode<T>* > children;
        TreeNode(int data){
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
        TreeNode<int> *f = q.front();
        q.pop();
        cout<<"Enter the number of child of "<<f->data<<endl;
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
        TreeNode<int> *f = q.front();
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

int countLeafNodes(TreeNode<int> *root){
    if(root == NULL) return 0;
    if(root->children.size() == 0) return 1;
    int count = 0;
    for(int i=0; i<root->children.size(); i++){
        count += countLeafNodes(root->children[i]);
    }
    return count;
}

int main(){
    TreeNode<int> *root = takeInput();
    PrintTree(root);
    int leafNodes = countLeafNodes(root);
    cout<<"The Total leaf Nodes : "<<leafNodes;

    return 0;
}