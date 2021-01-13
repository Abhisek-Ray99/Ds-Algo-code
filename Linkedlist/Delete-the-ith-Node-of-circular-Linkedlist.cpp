//delete the ith node of circular linkedlist

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

Node *deleteIthNode(Node *head,int pos){
    if(pos < 0) return head;
    if(pos == 0 && head){
        Node *newNode = head->next;
        head->next = NULL;
        delete head;
        return newNode;
    }
    Node *curr = head;
    int count = 1;
    while(count <= pos-1 && curr != NULL){
        curr = curr->next;
        count++;
    }
    if(curr && curr->next){
        Node *newDel = curr->next;
        curr->next = newDel->next;
        newDel->next = NULL;
        delete newDel;
        return head;
    }
    return head;
}

int main(){
    Node *head = takeInput();
    cout<<"The initial list is : ";
    PrintCLL(head);
    cout<<"\nEnter the position you want to delete : ";
    int pos;
    cin>>pos;
    head = deleteIthNode(head,pos);
    cout<<"\nThe final list is : ";
    PrintCLL(head);

    return 0;
}