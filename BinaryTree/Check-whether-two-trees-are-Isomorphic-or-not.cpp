// check whether two trees are isomorphic or not

#include<iostream>
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

bool isIsomorphic(BTNode<int> *root1,BTNode<int> *root2){
    if((root1 != NULL && root2 == NULL) || (root1 == NULL && root2 != NULL)){
        return false;
    }else{
        if(root1 == NULL && root2 == NULL){
            return true;
        }else{
            if(root1->data == root2->data){
                return isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right, root2->right) || isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left);
            }
        }  
    }
    return false;
}

int main(){
    BTNode<int> *root1 = new BTNode<int>(1);
    root1->left = new BTNode<int>(4);
    root1->right = new BTNode<int>(5);

    BTNode<int> *root2 = new BTNode<int>(1);
    root2->left = new BTNode<int>(5);
    root2->right = new BTNode<int>(4);
    

    (isIsomorphic(root1,root2) == 1) ? cout<<"Yahoo !! it is isomorphic" : cout<<"OH no !! it is not a isomorphic";

    return 0;
}