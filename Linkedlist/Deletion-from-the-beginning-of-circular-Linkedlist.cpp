//deletion from the beginning of circular linkedlist

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
    cout<<"Enter the list : ";
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
            tail->next = head;
        }
        cin>>data;
    }
    return head;
}

void PrintCLL(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<"-> ";
        temp = temp->next;
        if(temp == head){
            cout<<"->"<<temp->data;
            break;
        }
    }
}

Node *deleteCLL(Node *head){
    Node *curr = head;
    while(curr->next != head){
        curr = curr->next;
    }
    Node *temp = head;
    head = head->next;
    curr->next = head;
    delete temp;
    return head;
}

int main(){
    Node *head = takeInput();
    PrintCLL(head);
    cout<<endl;
    head = deleteCLL(head);
    cout<<endl;
    PrintCLL(head);

    return 0;
}