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

void Print(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<"-> ";
        temp = temp->next;
    }
    cout<<"NULL";
}

Node *segregateEvenOdd(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *even = new Node(0);
    Node *odd = new Node(0);
    Node * evenPTR = even, *oddPTR = odd;
    Node *curr = head;
    while(curr){
        if(curr->data % 2 == 0){
            evenPTR->next = curr;
            evenPTR = evenPTR->next;
            curr = curr->next; 
        }else{
            oddPTR->next = curr;
            oddPTR = oddPTR->next;
            curr = curr->next;
        }
    }
    evenPTR->next = odd->next;
    oddPTR->next = NULL; 
    delete even;
    delete odd;

    return head;
}

int main(){
    Node *head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(6);
    head->next->next->next->next->next = new Node(7);

    cout<<"The initial list is : ";
    Print(head);
    head = segregateEvenOdd(head);
    cout<<"\nThe final list is : ";
    Print(head);

    return 0;
}