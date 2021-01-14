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
    if(head != NULL){
        do{
            cout<<temp->data<<" ->";
            temp = temp->next;
        }while(temp != head);
    }
}

void splitCLL(Node *head,Node **head1,Node **head2){
    Node *fast = head;
    Node *slow = head;
    if(head == NULL){
        return;
    }
    while(fast->next != head && fast->next->next != head){
        fast = fast->next->next;
        slow = slow->next;
    }
    //if even element in the CLL
    if(fast->next->next == head){
        fast = fast->next;
    }
    //set the first half head
    *head1 = head;
    //set the second half head
    if(head->next != head){
        *head2 = slow->next;
    }
    //make the second CCL
    fast->next = slow->next;
    //make the first CCL
    slow->next = head;

}

int main(){
    Node *head = takeInput();
    Node *head1 = NULL;
    Node *head2 = NULL;
    cout<<"The initial list is : ";
    PrintCLL(head);

    splitCLL(head,&head1,&head2);

    cout<<"\nThe first half is : ";
    PrintCLL(head1);
    cout<<"\nThe second half is : ";
    PrintCLL(head2);

    return 0;
}