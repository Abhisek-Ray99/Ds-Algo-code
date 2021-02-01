// Convert BST to sorted LinkedList using pair class

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

class Pair{
    public:
        BTNode<int> *head;
        BTNode<int> *tail;
};

class BST{
    BTNode<int> *root;
    BTNode<int> *insert(BTNode<int> *node,int data){
        if(node == NULL){
            BTNode<int> *n = new BTNode<int>(data);
            return n;
        }
        if(data < node->data){
            node->left = insert(node->left,data);
        }else{
            node->right = insert(node->right,data);
        }
        return node;
    }
    Pair convertToLL(BTNode<int>* root){
        if(root == NULL){
            Pair ans;
            ans.head = NULL;
            ans.head = NULL;
            return ans;
        }
        if(root->left == NULL && root->right == NULL){
            Pair p;
            p.head = root;
            p.tail = root;
            return p;
        }else if(root->left != NULL && root->right == NULL){
            Pair leftLL = convertToLL(root->left);
            leftLL.tail->right = root;
            Pair ans;
            ans.head = leftLL.head;
            ans.tail = root;
            return ans;
        }else if(root->left == NULL && root->right != NULL){
            Pair rightLL = convertToLL(root->right);
            root->right = rightLL.head;
            Pair ans;
            ans.head = root;
            ans.tail = rightLL.tail;
            return ans;
        }else{
             Pair leftLL = convertToLL(root->left);
             Pair rightLL = convertToLL(root->right);
             leftLL.tail->right = root;
             root->right = rightLL.head;
             Pair ans;
             ans.head = leftLL.head;
             ans.tail = rightLL.tail;
             return ans;
        }
    }
    public:
        BST(){
            root = NULL;
        }
        void insert(int data){
            root = insert(root,data);
        }
        BTNode<int>* convertToLL(){
           Pair p = convertToLL(root);
           BTNode<int>* temp = p.head;
           while(temp != NULL){
              temp->left = NULL;
              temp = temp->right;
           }
           return p.head;
       }
};

int main(){
    BST b;
    b.insert(4);
    b.insert(2);
    b.insert(6);
    b.insert(1);
    b.insert(3);
    b.insert(5);
    b.insert(7);

    BTNode<int>* head = b.convertToLL();
    BTNode<int>* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"-> ";
        temp = temp->right;
    }

    return 0;

    return 0;
}