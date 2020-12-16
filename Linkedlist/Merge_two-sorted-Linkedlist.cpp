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
    Node *finalHead = NULL; // return head
    if(head_1->data < head_2->data){
        finalHead = head_1;
        head_1 = head_1->next;
    }else{
        finalHead = head_2;
        head_2 = head_2->next;
    }

    Node *finalTail = finalHead;
    while(head_1 && head_2){
        if(head_1->data < head_2->data){
            finalTail->next = head_1;
            head_1 = head_1->next;
        }else{
            finalTail->next = head_2;
            head_2 = head_2->next;
        }
        finalTail = finalTail->next;
    }
    if(head_1){
        finalTail->next = head_1;
    }else{
        finalTail->next = head_2;
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
    cout<<"First list is : ";
    Print(head_1);
    cout<<endl;

    Node *n4 = new Node(2); 
    Node *n5 = new Node(4); 
    Node *n6 = new Node(6);
    Node *head_2 = n4;
    n4->next = n5;
    n5->next = n6;
    cout<<"Second list is : ";
    Print(head_2);
    cout<<endl;

    cout<<"The final Merges list is : ";
    Node *head = MergeLL(head_1,head_2);
    Print(head);

    return 0;
}