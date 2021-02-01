// Check whether a preorder Traversal of BST is valid or not

#include<iostream>
#include<stack>
using namespace std;

bool isValidBST(int arr[],int size){
    stack<int> s;
    int root = INT_MIN;
    for(int i=0; i<size; i++){
        if(arr[i] < root) return false;
        while(!s.empty() && s.top()<arr[i]){
            root = s.top();
            s.pop();
        }
        s.push(arr[i]);
    }
    return true;
}

int main(){
    int arr[] = {20,16,12,10,17,34,40};
    int size = sizeof(arr)/sizeof(arr[0]);

    (isValidBST(arr,size)) ? cout<<"It is Valid PreOrder"
                           : cout<<"It is not a Valid PreOrder";

    return 0;
}