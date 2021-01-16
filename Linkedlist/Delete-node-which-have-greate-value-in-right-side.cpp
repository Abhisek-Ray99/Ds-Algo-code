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

void PrintLL(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ->";
        temp = temp->next;
    }
    cout<<"NULL";
}

void reverseLL(Node **head){
    Node *curr = *head;
    Node *prev = NULL;
    Node *next;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

Node *deleteNode(Node *head){
    reverseLL(&head);
    Node *maxNode = head;
    Node *curr = head;
    Node *temp;
    while(curr != NULL && curr->next != NULL){
        if(maxNode->data > curr->next->data){
            temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }else{
            curr = curr->next;
            maxNode = curr;
        }
    }
    reverseLL(&head);
    return head;
}

int main(){
    Node *head = new Node(2);
    head->next = new Node(1);
    head->next->next = new Node(8);
    head->next->next->next = new Node(16);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(2);

    cout<<"\nThe initial list is : ";
    PrintLL(head);
    head = deleteNode(head);
    cout<<"\nThe final list is : ";
    PrintLL(head);

    return 0;
}