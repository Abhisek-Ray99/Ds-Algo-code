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
    int data;
    cout<<"enter the list : ";
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    Node *prev = NULL;
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

void PrintDLL(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL";
}

void reverse(Node **head){
    Node *temp = NULL;
    Node *current = *head;
    while(current != NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if(temp != NULL){
        *head = temp->prev;
    }
}

int main(){
    Node *head = takeInput();
    PrintDLL(head);
    reverse(&head);
    PrintDLL(head);

    return 0;
}