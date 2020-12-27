#include<iostream>
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

Node *takeInput(){
    int data;
    cout<<"Enter the list -> ";
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data != -1){
        Node *n = new Node(data);
        if(head == NULL){
            head = n;
            tail = n;
        }else{
            tail->next = n;
            tail = n;
        }
        cin>>data;
    }
    return head;
}

void Print(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<"-> ";
        temp = temp->next;
    }
    cout<<"NULL";
}

Node *reverseLL(Node *head){
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return head = prev;
}

int main(){
    Node *head = takeInput();
    Print(head);
    cout<<endl;
    head = reverseLL(head);
    Print(head);

    return 0;
}