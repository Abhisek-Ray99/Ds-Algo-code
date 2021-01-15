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
    cout<<"Enter the data : ";
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
        cout<<temp->data<<" ->";
        temp = temp->next;
    }
    cout<<"NULL";
}

long long MultiplyLL(Node *head1,Node *head2){
    long long num1=0, num2=0;
    while(head1 || head2){
        if(head1){
            num1 = num1*10 + head1->data;
            head1 = head1->next;
        }
        if(head2){
            num2 = num2*10 + head2->data;
            head2 = head2->next;
        }
    }
    return num1*num2;
}

int main(){
    Node *head1 = takeInput(); 
    Node *head2 = takeInput();
    cout<<"\nThe first list is : "; 
    Print(head1);
    cout<<"\nThe first list is : ";
    Print(head2);

    long result = MultiplyLL(head1,head2);
    cout<<"\nThe final list is : "<<result;

    return 0;
}