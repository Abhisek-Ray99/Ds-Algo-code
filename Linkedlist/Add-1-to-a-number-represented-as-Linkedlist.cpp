#include <iostream>
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
    while (temp != NULL){
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << "NULL";
}

Node *addOneLL(Node *head){
    Node *curr = head;
    Node *last = head;

    int flag = 0, count = 0;
    while (curr){
        if (curr->data != 9){
            last = curr;
            count++;
        }else{
            flag = 1;
        }
        curr = curr->next;
    }
    if (flag == 0){
        last->data++;
        return head;
    }
    if (count != 0){
        last->data++;
        last = last->next;
        while (last){
            last->data = 0;
            last = last->next;
        }
        return head;
    }
    while (last){
        last->data = 0;
        last = last->next;
    }

    Node *temp = new Node(1);
    temp->next = head;
    head = temp;

    return head;
}

int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(9);
    Node *n3 = new Node(9);
    Node *n4 = new Node(9);
    Node *head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    cout << "The initial list is : ";
    PrintLL(head);
    head = addOneLL(head);
    cout << "\nThe final list is : ";
    PrintLL(head);

    return 0;
}