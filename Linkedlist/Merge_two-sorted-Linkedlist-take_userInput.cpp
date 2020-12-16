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

Node *MergeLL(Node *head_1, Node *head_2){
    if(head_1 == NULL) return head_1;
    if(head_2 == NULL) return head_2;
    Node *finalHead = NULL; // return head
    if(head_1->data < head_2->data){
        finalHead = head_1;
        head_1 = head_1->next;
    }else{
        finalHead = head_2;
        head_2 = head_2->next;
    }

    Node *finalTail = finalHead;
    while(head_1 && head_2){
        if(head_1->data < head_2->data){
            finalTail->next = head_1;
            head_1 = head_1->next;
        }else{
            finalTail->next = head_2;
            head_2 = head_2->next;
        }
        finalTail = finalTail->next;
    }
    if(head_1){
        finalTail->next = head_1;
    }else{
        finalTail->next = head_2;
    }
    return finalHead;
}

int main(){
    Node *head_1 = takeInput();
    Node *head_2 = takeInput();

    cout<<"First list is : ";
    Print(head_1);
    cout<<endl; 
    cout<<"Second list is : ";
    Print(head_2);
    cout<<endl;

    cout<<"The final Merges list is : ";
    Node *head = MergeLL(head_1,head_2);
    Print(head);

    return 0;
}