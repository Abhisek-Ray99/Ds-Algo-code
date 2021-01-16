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
    int data;
    cout<<"Enter the list : ";
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    Node *prev = NULL;
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

void PrintDLL(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ->";
        temp = temp->next;
    }
    cout<<"NULL";
}

Node *rotateDLL(Node **head,int n){
    if(n == 0){
        return *head;
    }
    Node *curr = *head;
    int count = 1;
    while(count < n && curr != NULL){
        curr = curr->next;
        count++;
    }
    if(curr == NULL) return 0;
    Node *nthNode = curr;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = *head;
    (*head)->prev = curr;
    *head = nthNode->next;
    (*head)->prev = NULL;
    nthNode->next = NULL;
    return *head;
}

int main(){
    Node *head = takeInput();
    cout<<"\nThe initial list is : ";
    PrintDLL(head);
    int n = 3;
    head = rotateDLL(&head,n);
    cout<<"\nThe final list is : ";
    PrintDLL(head);

    return 0;
}