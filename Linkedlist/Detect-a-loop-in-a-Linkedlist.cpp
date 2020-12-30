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

bool detectLoop(Node *head){
    if(head == NULL || head->next == NULL){
        return false;
    }
    Node *slow = head;
    Node *fast = head;

    while(fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
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
    n6->next = n2;

    (detectLoop(head) == 1) ? cout<<"Loop found"
                            : cout<<"Loop don't found";

    return 0;
}