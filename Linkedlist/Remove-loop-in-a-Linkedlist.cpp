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

void detectLoop(Node *head){
    if(head == NULL || head->next == NULL){
        return;
    }
    Node *slow = head;
    Node *fast = head; 
    slow = slow->next;
    fast = fast->next->next;

    while(fast != NULL && fast->next != NULL){
        if(slow == fast){
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    if(slow == fast){
        slow = head;
        if(slow == fast){
            while(fast->next != slow) fast = fast->next;
        }else{
            while(slow->next != fast->next){
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = NULL;
    }
}

void PrintLL(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<"-> ";
        temp = temp->next;
    }
    cout<<"NULL";
}

int main(){
    Node *n1 = new Node(2);
    Node *n2 = new Node(4);
    Node *n3 = new Node(6);
    Node *n4 = new Node(8);
    Node *n5 = new Node(10);
    Node *n6 = new Node(12);
    Node *head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n3;

    detectLoop(head);
    PrintLL(head);

    return 0;
}