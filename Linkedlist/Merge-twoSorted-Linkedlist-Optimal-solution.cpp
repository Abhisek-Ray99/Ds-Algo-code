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
    }
    cout<<"NULL";
}

Node *MergetwoLL(Node *head1, Node *head2){
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    if(head1->data > head2->data){
        swap(head1,head2);
    }
    Node *result = head1;
    while(head1 != NULL && head2 != NULL){
        Node *temp = NULL;
        while(head1 != NULL && head1->data <= head2->data){
            temp = head1;
            head1 = head1->next;
        }
        temp->next = head2;
        swap(head1,head2);
    }
    return result;
}

int main(){
    Node *n1 = new Node(4);
    Node *n2 = new Node(6);
    Node *n3 = new Node(8);
    Node *n4 = new Node(10);
    Node *n5 = new Node(12);
    Node *head1 = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    Node *n6 = new Node(2);
    Node *n7 = new Node(3);
    Node *n8 = new Node(5);
    Node *n9 = new Node(7);
    Node *n10 = new Node(9);
    Node *head2 = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;
    n9->next = n10;

    cout<<"The first list is : ";
    PrintLL(head1);
    cout<<"\nThe second list is : ";
    PrintLL(head2);

    Node *head = MergetwoLL(head1,head2);
    cout<<"\nThe final list is : ";
    PrintLL(head);

    return 0;
}