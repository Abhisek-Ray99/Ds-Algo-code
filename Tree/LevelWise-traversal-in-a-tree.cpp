//Levelwise traversal of Tree

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>* > children;
    TreeNode(T data){
        this->data = data;
    }
};

TreeNode<int> *takeInputLevelwise(){
    int rootdata;
    cout<<"Enter the root data : ";
    cin>>rootdata;
    TreeNode<int> *root = new TreeNode<int>(rootdata);
    queue<TreeNode<int>* > q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int> *f = q.front();
        q.pop();
        cout<<"Enter the number of children of "<<f->data<<endl;
        int n;
        cin>>n;
        for(int i=1; i<=n; i++){
            int childData;
            cout<<"Enter "<<i<<" number child of "<<f->data<<endl;
            cin>>childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            q.push(child);
            f->children.push_back(child);
        }
    }
    return root;
}

void PrintTreeLevelwise(TreeNode<int> *root){
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

int main(){
    TreeNode<int> *root = takeInputLevelwise();
    PrintTreeLevelwise(root);

    return 0;
}