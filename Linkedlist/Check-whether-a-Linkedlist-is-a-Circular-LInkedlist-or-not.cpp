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
        cout<<temp->data<<"-> ";
        temp = temp->next;
        if(temp == head){
            cout<<"->"<<temp->data;
            break;
        }
    }
}

bool isCircularLL(Node *head){
    Node *temp = head;
    while(temp != NULL){
        if(temp->next == head){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main(){
    Node *n1 = new Node(2); 
    Node *n2 = new Node(4); 
    Node *n3 = new Node(6); 
    Node *n4 = new Node(8); 
    Node *n5 = new Node(10); 
    Node *n6 = new Node(12); 
    Node *head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n5->next = head;

    PrintLL(head);

    (isCircularLL(head) == 1) ? cout<<"\nIt is a circular Linkedlist" : cout<<"\nIt is not a circular Linked"; 

    return 0;
}