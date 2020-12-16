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

Node *removeKthNode(Node *head, int k){
    Node *one = head;
    Node *two = head;
    while(k--){
        two = two->next;
    }
    if(two == NULL){
        return one->next;
    }
    while(two->next != NULL){
        one = one->next;
        two = two->next;
    }
    //remove
    one->next = one->next->next;
    return head;
}

int main(){
    Node *head = takeInput();
    Print(head);
    cout<<endl;
    cout<<"enter the node you want to remove : ";
    int k;
    cin>>k;
    head = removeKthNode(head,k);
    cout<<"The final list is : ";
    Print(head);

    return 0;
}