#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *previous;
        Node *next;
        Node(int data){
            this->data = data;
            previous = NULL;
            next = NULL;
        }
};

void printDList(Node *head){
    Node *temp = head;
    cout<<"NULL <- ";
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
    head->previous = newNode;
    head = newNode;
}

void insertLast(Node *&head,int element){
    Node *newNode = new Node(element);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node *curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->previous = curr;
}

void insertAtPos(Node *&head,int position,int element){
    if(head == NULL) return;
    Node *newNode = new Node(element);
    if(position == 0){
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }
    Node *curr = head;
    int count = 1;
    while(count <= position-1 && curr != NULL){
        curr = curr->next;
        count++;
    }
    if(curr != NULL){
        newNode->next = curr->next;
        curr->next->previous = newNode;
        curr->next = newNode;
        newNode->previous = curr;
    }
}

void insertAfterNode(Node *&node, int element){
    if(node == NULL) return;
    Node *newNode = new Node(element);
    if(node->next != NULL){
        newNode->next = node->next;
        node->next->previous = newNode;
        node->next = newNode;
        newNode->previous = node;
    }else{
        node->next = newNode;
        newNode->previous = node;
    }
}

int main(){
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *head = n1;
    n1->next = n2;
    n2->previous = n1;
    n2->next = n3;
    n3->previous = n2;
    n3->next = n4;
    printDList(head);
    insertFirst(head,10);
    printDList(head);
    insertLast(head,11);
    printDList(head);
    insertAtPos(head,5,12);
    printDList(head);
    insertAfterNode(n4,20);
    printDList(head);

    return 0;
}
