// Implement a Doubly linkedlist

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int data){
            this->data = data;
            next = NULL;
            prev = NULL;
        }
};

Node *takeInput(){
    cout<<"Enter a list : ";
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data != -1){
        Node *curr = new Node(data);
        if(head == NULL){
            head = curr;
            tail = curr;
        }else{
            tail->next = curr;
            curr->prev = tail;
            tail = curr;
        }
        cin>>data;
    }
    return head;
}

void printDLL(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<"<-> ";
        temp = temp->next;
    }
    cout<<"NULL";
}


int main(){
    Node *head = takeInput();
    printDLL(head);

    return 0;
}