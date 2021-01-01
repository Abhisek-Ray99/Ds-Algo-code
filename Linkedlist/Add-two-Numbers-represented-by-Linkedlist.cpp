#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(){
            this->data = 0;
            next = NULL;
        }
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

Node *addTwoNumber(Node *head1,Node *head2){
    Node *dummy = new Node();
    Node *temp = dummy;
    int carry = 0;
    while(head1 != NULL || head2 != NULL || carry){
        int sum = 0;
        if(head1 != NULL){
            sum += head1->data;
            head1 = head1->next;
        }
        if(head2 != NULL){
            sum += head2->data;
            head2 = head2->next;
        }

        sum += carry;
        carry = sum/10;
        Node *node = new Node(sum % 10);
        temp->next = node;
        temp = temp->next;
    }
    return dummy->next;
}

int main(){
    Node *n1 = new Node(5);
    Node *n2 = new Node(6);
    Node *n3 = new Node(3);
    Node *head1 = n1;
    n1->next = n2;
    n2->next = n3;

    Node *n4 = new Node(8);
    Node *n5 = new Node(4);
    Node *n6 = new Node(2);
    Node *head2 = n4;
    n4->next = n5;
    n5->next = n6;

    cout<<"The 1st list : ";
    PrintLL(head1);
    cout<<"\nThe 2nd list : ";
    PrintLL(head2);

    Node *finalNode = addTwoNumber(head1,head2);
    cout<<"\nThe final list is : ";
    PrintLL(finalNode);

    return 0;
}