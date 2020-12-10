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

bool isPresent(Node *head, int node){
    Node *temp = head;
    if(temp == NULL) return false;
    if(temp->data == node) return true;
    return isPresent(head->next,node);
}

int main(){
    Node *head = takeInput();
    Print(head);
    cout<<endl;
    int node;
    cout<<"Enter the Node to search -> ";
    cin>>node;
    (isPresent(head,node) == 1) ? cout<<"Node is Present"
                                : cout<<"Node is not Present";

    return 0;
}