//construct a Binary tree from PostOrder & InOrder traversal

#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class BTNode{
    public:
       T data;
       BTNode* left;
       BTNode* right;
       BTNode(T data){
           this->data = data;
           left = NULL;
           right = NULL;
       }
};

void preOrder(BTNode<int>* root){
    if(root == NULL) return;
    cout<<root->data<<" ";  //data
    preOrder(root->left);   //left
    preOrder(root->right);  //right
}

BTNode<int>* buildTreeHelper(vector<int> inOrder, vector<int> postOrder, int inS, int inE, int postS, int postE){
    if(inS > inE){
        return NULL;
    }
    int rootData = postOrder[postE];
    int rootIndex = -1;
    for(int i=inS; i<=inE; i++){
        if(inOrder[i] == rootData){
            rootIndex = i;
            break;
        }
    }

    int leftInS = inS;
    int leftInE = rootIndex - 1;
    int leftPostS = postS;
    int leftPostE = leftPostS + leftInE - leftInS;

    int rightInS = rootIndex + 1;
    int rightInE = inE;
    int rightPostS = leftPostE + 1;
    int rightPostE = postE - 1;

    BTNode<int>* root = new BTNode<int>(rootData);
    root->left = buildTreeHelper(inOrder, postOrder, leftInS, leftInE, leftPostS, leftPostE);
    root->right = buildTreeHelper(inOrder, postOrder, rightInS, rightInE, rightPostS, rightPostE);
    return root;
}

BTNode<int>* buildTree(vector<int> &inOrder, vector<int> &postOrder){
    int n = inOrder.size();
    return buildTreeHelper(inOrder, postOrder, 0, n-1, 0, n-1);
}

int main(){

    vector<int> inOrder = {9,3,15,20,7};
    vector<int> postOrder = {9,15,7,20,3};

    BTNode<int>* root = buildTree(inOrder, postOrder);
    preOrder(root);


    return 0;
}