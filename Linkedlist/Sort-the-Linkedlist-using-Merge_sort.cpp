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
    cout<<"enter the list : ";
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

Node *mergeLL(Node *a,Node *b){
    if(a == NULL) return a;
    if(b == NULL) return b;
    Node *finalHead = NULL;
    if(a->data < b->data){
        finalHead = a;
        a = a->next;
    }else{
        finalHead = b;
        b = b->next;
    }
    Node *finaltail = finalHead;
    while(a && b){
        if(a->data < b->data){
            finaltail->next = a;
            a = a->next;
        }else{
            finaltail->next = b;
            b = b->next;
        }
        finaltail = finaltail->next;
    }
    if(a){
        finaltail->next = a;
    }else{
        finaltail->next = b;
    }
    return finalHead;
}

Node *Merge_sortLL(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    //break the list into two parts
    Node *slow = head;
    Node *fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *n = slow->next;
    slow->next = NULL;
    Node *a = Merge_sortLL(head);
    Node *b = Merge_sortLL(n);

    head = mergeLL(a,b);
    return head;
}

int main(){
    Node *head = takeInput();
    cout<<"The list is : ";
    Print(head);
    cout<<endl;
    cout<<"The final list is : ";
    head = Merge_sortLL(head);
    Print(head);

    return 0;
}