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

Node *getIntersetionNode(Node *head1,Node *head2){
    if(head1 == NULL || head2 == NULL) return NULL;
    Node *head1_PTR = head1;
    Node *head2_PTR = head2;

    while(head1_PTR != head2_PTR){
        head1_PTR = (head1_PTR == NULL) ? head2 : head1_PTR->next;
        head2_PTR = (head2_PTR == NULL) ? head1 : head2_PTR->next;
    }
    return head1_PTR;
}

int main(){
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(8);
    Node *n4 = new Node(7);
    Node *n5 = new Node(6);
    Node *head1 = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    Node *n6 = new Node(2);
    Node *n7 = new Node(8);
    Node *n8 = new Node(1);
    Node *n9 = new Node(3);
    Node *head2 = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;
    n9->next = n3;

    cout<<"The first list is : ";
    PrintLL(head1);
    cout<<"\nThe second list is : ";
    PrintLL(head2);

    Node *point = getIntersetionNode(head1,head2);
    cout<<"\nThe intersection point is : "<<point->data;

    return 0;
}