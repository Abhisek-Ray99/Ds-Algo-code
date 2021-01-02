#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *bottom;
        Node(int data){
            this->data = data;
            next = NULL;
            bottom = NULL;
        }
};

void PrintLL(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<"-> ";
        temp = temp->bottom;
    }
    cout<<"NULL";
}

Node* mergeTwoLL(Node *a, Node *b){
    Node *temp = new Node(0);
    Node *result = temp;

    while(a != NULL && b!= NULL){
        if(a->data < b->data){
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }else{
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    if(a){
        temp->bottom = a;
    }else{
        temp->bottom = b;
    }
    return result->bottom;
}

Node *flatten(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    //recursion for list on right
    head->next = flatten(head->next);
    //merge two list
    head = mergeTwoLL(head,head->next);
    //return the head of mergedlist
    return head;
}

int main(){
    Node *n1 = new Node(5);
    Node *n2 = new Node(7);
    Node *n3 = new Node(9);
    Node *n4 = new Node(10);
    Node *n5 = new Node(12);
    Node *n6 = new Node(14);
    Node *n7 = new Node(8);
    Node *n8 = new Node(11);
    Node *n9 = new Node(13);
    Node *head = n1;
    n1->next = n2;
    n2->next = n3;
    //first list
    n1->bottom = n4;
    n4->bottom = n5;
    n5->bottom = n6;
    //second list
    n2->bottom = n7;
    n7->bottom = n8;
    //third list
    n3->bottom = n9;

    head = flatten(head);
    cout<<"The final list is : ";
    PrintLL(head);

    return 0;
}