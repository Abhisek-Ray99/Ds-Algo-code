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

void printithNode(Node *head, int pos){
    if(pos < 0){
        cout<<"can not find the node"<<endl;
        return;
    }
    int count = 1;
    while(count <= pos && head != NULL){
        head = head->next;
        count++;
    }
    if(head){
        cout<<head->data<<endl;
    }else{
        cout<<"can not find the node"<<endl;
    }
}

int main(){
    Node *head = takeInput();
    Print(head);
    cout<<endl;
    cout<<"enter the postion you want to print : ";
    int pos;
    cin>>pos;
    cout<<"The Node is : ";
    printithNode(head,pos);

    return 0;
}