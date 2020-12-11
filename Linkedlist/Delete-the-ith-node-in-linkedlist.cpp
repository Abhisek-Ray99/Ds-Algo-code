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

Node *deleteithNode(Node *head, int pos){
    if(pos<0) return head;
    if(pos == 0 && head){
        Node *newHead = head->next;
        head->next = NULL;
        delete head;
        return  newHead;
    }
    Node *curr = head;
    int count = 1;
    while(count <= pos-1 && curr != NULL){
        curr = curr->next;
        count++;
    }
    if(curr && curr->next){
        Node *newdel = curr->next;
        curr->next = newdel->next;
        newdel->next = NULL;
        delete newdel;
        return head;
    }
    return head;
}

int main(){
    Node *head = takeInput();
    Print(head);
    cout<<endl;
    cout<<"Enter the position of node to delete : ";
    int pos;
    cin>>pos;
    head = deleteithNode(head,pos);
    cout<<"The finalize list is : ";
    Print(head);
    

    return 0;
}