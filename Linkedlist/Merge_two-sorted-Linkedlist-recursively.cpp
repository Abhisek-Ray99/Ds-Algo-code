//here two sorted linkedlist number should be same

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

Node *MergeLL(Node *head_1, Node *head_2){
    if(head_1 == NULL) return head_1;
    if(head_2 == NULL) return head_2;

    Node *finalHead = NULL; //return head
    if(head_1->data < head_2->data){
        finalHead = head_1;
        finalHead->next = MergeLL(head_1->next,head_2);
    }else{
        finalHead = head_2;
        finalHead->next = MergeLL(head_1,head_2->next);
    }
    return finalHead;
}

int main(){
    Node *n1 = new Node(1);
    Node *n2 = new Node(3);
    Node *n3 = new Node(5);
    Node *head_1 = n1;
    n1->next = n2;
    n2->next = n3;

    Node *n5 = new Node(2);
    Node *n6 = new Node(4);
    Node *n7 = new Node(6);
    Node *head_2 = n5;
    n5->next = n6;
    n6->next = n7;

    cout<<"The first list : ";
    Print(head_1);
    cout<<endl;
    cout<<"The second list : ";
    Print(head_2);
    cout<<endl;

    cout<<"The final Merged list is : ";
    Node *head = MergeLL(head_1,head_2);
    Print(head);

    return 0;
}