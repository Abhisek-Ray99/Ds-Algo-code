// Replace every element with the least greater element on its right

#include<iostream>
using namespace std;

template<typename T>
class BTNode{
    public:
    T data;
    BTNode *left;
    BTNode *right;
    BTNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void insert(BTNode<int> *&root,int data,BTNode<int> *&successor){
    if(root == NULL) root = new BTNode<int>(data);
    if(data < root->data){
        successor = root;
        insert(root->left,data,successor);
    }
    if(data > root->data){
        insert(root->right,data,successor);
    }
}
void replaceElement(int arr[],int size){
    BTNode<int> *root = NULL;
    for(int start=size-1; start>=0; start--){
        BTNode<int> *successor = NULL;
        insert(root,arr[start],successor);
        if(successor) arr[start] = successor->data;
        else arr[start] = -1;
    }
}

int main(){
    int arr[] = {12,8,16,3,10,14,20};
    int size = sizeof(arr)/sizeof(arr[0]);
    replaceElement(arr,size);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<",";
    }

    return 0;
}