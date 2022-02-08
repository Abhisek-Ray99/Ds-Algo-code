// ------------------------------------------------------------------All Test cases pass---------------------------------------------------------------//

#include<bits/stdc++.h>
using namespace std;

class DoublyLinkedListNode {
    public:
    int data;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;
    DoublyLinkedListNode(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
    DoublyLinkedListNode(){
        next = NULL;
        prev = NULL;
    }
};

void printDList(DoublyLinkedListNode *llist){
    DoublyLinkedListNode *temp = llist;
    cout<<"NULL <-> ";
    while(temp != NULL){
        cout<<temp->data<<" <-> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    if(llist == NULL) return llist;
    DoublyLinkedListNode *curr = llist;
    DoublyLinkedListNode *temp = new DoublyLinkedListNode(0);
    while(curr != NULL){
        temp->next = curr->next; 
        temp->prev = curr->prev; 
        curr->next = temp->prev; 
        curr->prev = temp->next; 
        curr = temp->next;
        if(curr != NULL){
            llist = curr;
        } 
    }
    return llist;
}

int main(){ 
    DoublyLinkedListNode *n1 = new DoublyLinkedListNode(1);
    DoublyLinkedListNode *n2 = new DoublyLinkedListNode(2);
    DoublyLinkedListNode *n3 = new DoublyLinkedListNode(3);
    DoublyLinkedListNode *n4 = new DoublyLinkedListNode(5);
    DoublyLinkedListNode *llist = n1;
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;
    printDList(llist);
    llist = reverse(llist);
    printDList(llist);

    return 0;
}




// ----------------------------------------------------------another method,but only onle case fail--------------------------------------------------------




#include<bits/stdc++.h>
using namespace std;

class DoublyLinkedListNode {
    public:
    int data;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;
    DoublyLinkedListNode(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

void printDList(DoublyLinkedListNode *llist){
    DoublyLinkedListNode *temp = llist;
    cout<<"NULL <-> ";
    while(temp != NULL){
        cout<<temp->data<<" <-> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    if(llist == NULL){
        return llist;
    }
    DoublyLinkedListNode *curr = llist;
    DoublyLinkedListNode *temp = NULL;
    while(curr != NULL){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    llist = temp->prev;
    return llist;
}

int main(){ 
    DoublyLinkedListNode *n1 = new DoublyLinkedListNode(1);
    DoublyLinkedListNode *n2 = new DoublyLinkedListNode(2);
    DoublyLinkedListNode *n3 = new DoublyLinkedListNode(3);
    DoublyLinkedListNode *n4 = new DoublyLinkedListNode(5);
    DoublyLinkedListNode *llist = n1;
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;
    printDList(llist);
    llist = reverse(llist);
    printDList(llist);

    return 0;
}


