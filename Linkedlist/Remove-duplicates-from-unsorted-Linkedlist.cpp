#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            next = NULL;
        }
};

void PrintLL(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<"-> ";
        temp = temp->next;
    }
    cout<<"NULL";
}

Node *removeDuplicates(Node* head)  {  
    vector<int> v;
    bool arr[10001] = {false};

    Node *curr = head;
    while(curr){
        if(arr[curr->data] == false){
            {
                v.push_back(curr->data);
                arr[curr->data] = true;
            }
        }
        curr = curr->next;
    }
    if(v.size() == 0){
        return NULL;
    }
    Node *temp = new Node(v[0]);
    Node *newHead = temp;
    Node *newTail = temp;

    for(int i=1; i<v.size(); i++){
        Node *temp = new Node(v[i]);
        newTail->next = temp;
        newTail = temp;
    } 
    return newHead;
}  

int main(){
    Node *n1 = new Node(4);  
    Node *n2 = new Node(2);  
    Node *n3 = new Node(2); 
    Node *n4 = new Node(3);  
    Node *n5 = new Node(5);  
    Node *n6 = new Node(3);  
    Node *n7 = new Node(5);  
    Node *n8 = new Node(6);  
    Node *head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;

    cout<<"The initial list is : ";
    PrintLL(head);
    cout<<"\nThe final list is : ";
    head = removeDuplicates(head);  
    PrintLL(head);
}