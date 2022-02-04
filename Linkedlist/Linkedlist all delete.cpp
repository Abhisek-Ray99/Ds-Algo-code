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

void printList(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void deleteFirst(Node *&head){
    if(head == NULL){
        return;
    }
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}

void deleteLast(Node *&head){
    if(head == NULL){
        return;
    }
    Node *curr = head;
    Node *before = NULL;
    while(curr->next != NULL){
        before = curr;
        curr = curr->next;
    }
    before->next = NULL;
    delete curr;
}

void deletePosition(Node *&head,int position){
    if(head == NULL){
        return;
    }
    if(position == 0){
        Node *tempHead = head;
        head = head->next;
        delete tempHead;
        return;
    }
    Node *curr = head;
    Node *before = NULL;
    int count = 0;
    while(count <= position-1 && curr != NULL){
        before = curr;
        curr = curr->next;
        count++;
    }
    if(curr){
        before->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void deleteMiddle(Node *&head){
    if(head == NULL){
        return;
    }
    Node *slow = head;
    Node *fast = head;
    Node *before = NULL;
    while(fast->next != NULL){
        before = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    before->next = slow->next;
    slow->next = NULL;
    delete slow;
}

int main(){
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);
    Node *n8 = new Node(8);
    Node *head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    printList(head);
    deleteFirst(head);
    printList(head);
    deleteLast(head);
    printList(head);
    deletePosition(head,2);
    printList(head);
    deleteMiddle(head);
    printList(head);

    return 0;
}
