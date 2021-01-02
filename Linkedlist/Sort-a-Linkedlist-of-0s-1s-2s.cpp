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

void PrintLL(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<"-> ";
        temp = temp->next;
    }
    cout<<"NULL";
}

Node *segregate(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *zeroD = new Node(0);
    Node *oneD = new Node(0);
    Node *twoD = new Node(0);
    Node *zero = zeroD, *one = oneD, *two = twoD;
    Node *curr = head;
    while(curr){
        if(curr->data == 0){
            zero->next = curr;
            zero = zero->next;
            curr = curr->next;
        }else if(curr->data == 1){
            one->next = curr;
            one = one->next;
            curr = curr->next;
        }else{
            two->next = curr;
            two = two->next;
            curr = curr->next;
        }
    }
    //join three
    zero->next = (oneD->next) ? oneD->next : two->next;
    one->next = twoD->next;
    two->next = NULL;

    //update head
    head = zeroD->next;
    //delete dummy node
    delete zeroD;
    delete oneD;
    delete twoD;

    return head;
}

int main(){
    Node *head = takeInput();
    cout<<"The initial list is : ";
    PrintLL(head);
    head = segregate(head);
    cout<<"\nThe final list is : ";
    PrintLL(head);

    return 0;
}