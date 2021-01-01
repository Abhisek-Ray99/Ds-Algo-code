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

Node *intersectionTwoLL(Node *head1,Node *head2){
    Node *finalHead;
    Node *headPTR;
    bool first = true;
    while(head1 && head2){
        if(head1->data == head2->data){
            if(first){
                Node *temp = new Node(head1->data);
                finalHead = temp;
                headPTR = finalHead;
                first = false;
            }else{
                Node *temp = new Node(head1->data);
                headPTR->next = temp;
                headPTR = temp;
            }
            head1 = head1->next;
            head2 = head2->next;
        }else if(head1->data < head2->data){
            head1 = head1->next;
        }else{
            head2 = head2->next;
        }
    }
    return finalHead;
}

int main(){
    Node *head1 = takeInput();
    Node *head2 = takeInput();

    cout<<"The first list is : ";
    Print(head1);
    cout<<"\nThe second list is : ";
    Print(head2);

    Node *head = intersectionTwoLL(head1,head2);
    cout<<"\nThe Final list is : ";
    Print(head);

    return 0;
}