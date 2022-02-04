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

void printCircularList(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ->";
        temp = temp->next;
        if(temp == head){
            cout<<temp->data;
            break;
        }
    }
    cout<<endl;
}

void insertFirst(Node *&head,int element){
    Node *newNode = new Node(element);
    if(head == NULL){
        head = newNode;
    }
    Node *curr = head;
    while(curr->next != head){
        curr = curr->next;
    }
    newNode->next = head;
    head = newNode;
    curr->next = head;
}

void insertLast(Node *&head,int element){
    Node *newNode = new Node(element);
    if(head == NULL){
        head = newNode;
    }
    Node *curr = head;
    while(curr->next != head){
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->next = head;
}

void insertAtpos(Node *&head,int position,int element){
    if(head == NULL){
        Node *newNode = new Node(element);
        head = newNode;
        return;
    }
    if(position == 0){
        Node *newNode = new Node(element);
        Node *curr = head;
        while(curr->next != head){
            curr = curr->next;
        }
        newNode->next = head;
        head = newNode;
        curr->next = head;
        return;
    }
    Node *curr = head;
    int count = 1;
    while(count <= position-1 && curr != NULL){
        curr = curr->next;
        count++;
    }
    Node *newNode = new Node(element);
    newNode->next = curr->next;
    curr->next = newNode;
}

int main(){
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = head;
    printCircularList(head);
    insertFirst(head,5);
    insertFirst(head,6);
    insertFirst(head,7);
    printCircularList(head);
    insertLast(head,8);
    insertLast(head,9);
    printCircularList(head);
    insertAtpos(head,5,15);
    insertAtpos(head,11,10);
    printCircularList(head);

    return 0;
}
