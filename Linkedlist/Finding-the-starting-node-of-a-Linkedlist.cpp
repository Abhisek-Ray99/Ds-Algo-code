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

Node *detectLoop(Node *head){
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            break;
        }
    }
    if(fast == NULL || fast->next == NULL){
        return NULL;
    }else{
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        } 
        return slow;
    }
}

int main(){
    Node *n1 = new Node(2);
    Node *n2 = new Node(4);
    Node *n3 = new Node(6);
    Node *n4 = new Node(8);
    Node *n5 = new Node(10);
    Node *head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n3;
    
    Node *element = detectLoop(head);
    cout<<element->data;

    return 0;
}