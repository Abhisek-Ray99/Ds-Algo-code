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

int main(){
    Node *n1 = new Node(2);
    Node *n2 = new Node(4);
    Node *n3 = new Node(8);
    Node *n4 = new Node(10);
    Node *n5 = new Node(12);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    Node *head = n1;
    Print(head);

    return 0;
}