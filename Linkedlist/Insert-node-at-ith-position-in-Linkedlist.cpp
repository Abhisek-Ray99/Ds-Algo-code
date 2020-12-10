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

Node *takeInput(){
    int data;
    cout<<"Enter the list -> ";
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data != -1){
        Node *n = new Node(data);
        if(head == NULL){
            head = n;
            tail = n;
        }else{
            tail->next = n;
            tail = n;
        }
        cin>>data;
    }
    return head;
}

void Print(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<"-> ";
        temp = temp->next;
    }
    cout<<"NULL";
}

Node *insertAtithPos(Node *head, int pos, int node){
    if(pos<0) return head;
    if(pos == 0){
        Node *n = new Node(node);
        n->next = head;
        head = n;
        return head;
    }
    Node *temp = head;
    int count = 1;
    while(count <= pos-1 && head != NULL){
        head = head->next;
        count++;
    }
    if(head){
        Node *n = new Node(node);
        n->next = head->next;
        head->next = n;
        return temp;
    }
    return temp;
}

int main(){
    Node *head = takeInput();
    Print(head);
    cout<<endl;
    cout<<"Enter the position you want to insert : ";
    int pos;
    cin>>pos;
    cout<<"Enter the node you want to insert : ";
    int node;
    cin>>node;
    cout<<"The Final Linked List is : ";
    head = insertAtithPos(head,pos,node);
    Print(head);

    return 0;
}