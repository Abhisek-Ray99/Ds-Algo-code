#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *random;
        Node(int data){
            this->data = data;
            next = NULL;
            random = NULL;
        }
};

Node *cloneLL(Node *head){
    Node *iter = head;
    Node *front = head;
    //make copy of each node and link them to side by side
    while(iter != NULL){
        front = iter->next;
        Node *copy = new Node(iter->data);
        iter->next = copy;
        copy->next = front;
        iter = front;
    }
    //assign random node pointers for the copy nodes
    iter = head;
    while(iter != NULL){
        if(iter->random != NULL){
            iter->next->random = iter->random->next;
        }
        iter = iter->next->next;
    }
    //restore the original list and copy list
    iter = head;
    Node *pseudoHead = new Node(0);
    Node *copy = pseudoHead;
    while(iter != NULL){
        front = iter->next->next;
        //extract the copy list
        copy->next = iter->next;
        //restore the original list
        iter->next = front;

        copy = copy->next;
        iter = front;
    }
    return pseudoHead->next;
}

void Print_LL(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<"Data : "<<temp->data<<" -> Random : "<<temp->random->data<<endl;
        temp = temp->next;
    }
}

int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head->random = head->next->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next;

    cout<<"The Original list is : "<<endl;
    Print_LL(head);
    cout<<"\nThe clone of list is : "<<endl;
    Node *copyHead = cloneLL(head);
    Print_LL(copyHead); 

    return 0;
}