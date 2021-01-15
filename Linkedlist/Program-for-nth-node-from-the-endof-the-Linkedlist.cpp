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

void PrintLL(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ->";
        temp = temp->next;
    }
    cout<<"NULL";
}

Node *PrintithNodefromLast(Node *head,int pos){
    int count_nodes = 0;
    Node *temp = head;
    while(temp != NULL){
        temp = temp->next;
        count_nodes++;
    }
    if(count_nodes < pos){
        return 0;
    }
    temp = head;
    for(int i=1; i<count_nodes-pos+1; i++){
        temp = temp->next;
    }
    return temp;
}

int main(){
    Node *head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(6);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(10);

    cout<<"\nThe initial list is : ";
    PrintLL(head);
    Node *result = PrintithNodefromLast(head,1);
    if(result){
        cout<<"\nThe node is : "<<result->data;
    }else{
        cout<<"\nNOt found";
    }

    return 0;
}