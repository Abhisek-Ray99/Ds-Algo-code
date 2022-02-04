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
}

void deleteFirst(Node *&head){
    if(head == NULL) return;
    Node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    Node *delnode = head;
    head = head->next;
    temp->next = head;
    delete delnode;
}

void deleteLast(Node *&head){
    if(head == NULL) return;
    Node *temp = head;
    Node *before = NULL;
    while(temp->next != head){
        before = temp;
        temp = temp->next;
    }
    Node *delnode = temp;
    before->next = head;
    delnode->next = NULL;
    delete delnode;
}

void deleteNodewithValue(Node *&head,int element){
    if(head == NULL) return;
    Node *temp = head;
    Node *delnode = NULL;
    if(head->data == element){
        while(temp->next != head){
            temp = temp->next;
        }
        delnode = head;
        head = head->next;
        temp->next = head;
        delete delnode;
        return;
    }
    Node *before = NULL;
    while(temp->next != head){
        if(temp->data == element){
            before->next = temp->next;
            temp->next = NULL;
            delete temp;
            return;
        }
        before = temp;
        temp = temp->next;
    }
    delnode = temp;
    temp->next = NULL;
    before->next = head;
    delete delnode;
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
    Node *n9 = new Node(9);
    Node *head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;
    n9->next = head;
    printCircularList(head);
    deleteFirst(head);
    deleteFirst(head);
    cout<<endl;
    printCircularList(head);
    deleteLast(head);
    cout<<endl;
    printCircularList(head);
    deleteLast(head);
    cout<<endl;
    printCircularList(head);
    deleteNodewithValue(head,7);
    cout<<endl;
    printCircularList(head);

    return 0;
}
