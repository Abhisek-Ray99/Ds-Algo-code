#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void printLL(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<"-> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

Node * rotateLL(Node *head,int k){
    if(head == NULL) return head;
    Node *temp = head;
    Node *lastPTR = NULL;
    int size = 0;
    while(temp != NULL){
        lastPTR = temp;
        temp = temp->next;
        size++;
    }
    int count = size-k;
    if(count == 0) return head;
    Node *curr = head;
    while(--count && curr != NULL){
        curr = curr->next;
    }
    Node *newhead = curr->next;
    lastPTR->next = head;
    curr->next = NULL;
    return newhead;
}

int main(){
    Node *n1 = new Node(1);
    Node *head = n1;
    printLL(head);
    int k=1;
    head = rotateLL(head,k);
    printLL(head);


    return 0;
}
