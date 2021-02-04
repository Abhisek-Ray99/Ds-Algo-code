// Rotate doubly linked list in group of given size

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int data){
            this->data = data;
            next = NULL;
            prev = NULL;
        }
};

Node *takeInput(){
    cout<<"Enter a list : ";
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data != -1){
        Node *curr = new Node(data);
        if(head == NULL){
            head = curr;
            tail = curr;
        }else{
            tail->next = curr;
            curr->prev = tail;
            tail = curr;
        }
        cin>>data;
    }
    return head;
}

void printDLL(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<"<-> ";
        temp = temp->next;
    }
    cout<<"NULL";
}

void push(Node **head,Node *node){
    node->prev = NULL;
    node->next = (*head);
    if((*head) != NULL ){
        (*head)->prev = node;
    }
    (*head) = node;
}

Node *reversegivenSize(Node *head,int size){
    Node *curr = head;
    Node *next = NULL;
    Node *newHead = NULL;
    int count = 0;
    while(curr != NULL && count<size){
        next = curr->next;
        push(&newHead,curr);
        curr = next;
        count++;
    }
    if(next != NULL){
        head->next = reversegivenSize(next,size);
        head->next->prev = head;
    }
    return newHead;
}

int main(){
    Node *head = takeInput();
    cout<<"The initial DLL is : "<<endl;
    printDLL(head);
    int givensize = 2;
    head = reversegivenSize(head,givensize);
    cout<<"\nThe final DLL is : "<<endl;
    printDLL(head);

    return 0;
}