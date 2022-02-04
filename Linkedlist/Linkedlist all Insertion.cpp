#include<bits/stdc++.h>
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

void PrintList(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void insertFirst(Node *&head,int element){
    Node *newNode = new Node(element);
    if(head == NULL){
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode; 
}

void insertLast(Node *&head,int element){
    Node *newNode = new Node(element);
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

Node *insertPosition(Node *&head,int position,int element){
    if(position < 0) return head;
    Node *newNode = new Node(element);
    if(position == 0){  
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node *curr = head;
    int count = 1;
    while(count <= position-1 && curr != NULL){
        curr = curr->next;
        count++;
    }
    if(curr){
        newNode->next = curr->next;
        curr->next = newNode;
        return head;
    }
    return head;
}

void insertMiddle(Node *&head,int element){
    Node *slow = head;
    Node *fast = head;
    while(fast->next != NULL && fast != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *newNode = new Node(element);
    newNode->next = slow->next;
    slow->next = newNode;
}

int main(){
    Node *n1 = new Node(1);
    Node *n2 = new Node(4);
    Node *n3 = new Node(8);
    Node *n4 = new Node(12);
    Node *head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    PrintList(head);
    insertFirst(head,10);
    insertFirst(head,20);
    PrintList(head);
    insertLast(head,22);
    insertLast(head,26);
    PrintList(head);
    head = insertPosition(head,4,100);
    PrintList(head);
    insertMiddle(head,50);
    PrintList(head);

    return 0;
}
