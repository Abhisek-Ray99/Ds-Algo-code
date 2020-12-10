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

Node *partition(Node *head, int x){
    /* s_h = smallhead, s_t = smalltail
       e_h = equalhead, e_t = equaltail
       g_h = greaterhead, g_h = greatertail 
    */
    Node *s_h = NULL, *s_t = NULL;
    Node *e_h = NULL, *e_t = NULL;
    Node *g_h = NULL, *g_t = NULL;
    // here we iterate the list && after that we store the node in the small, equal and greater variable by partition 
    while(head != NULL){
        if(head->data == x){
            if(e_h == NULL){
                e_h = e_t = head;
            }else{
                e_t->next = head;
                e_t = e_t->next;
            }
        }else if(head->data < x){
            if(s_h == NULL){
                s_h = s_t = head;
            }else{
                s_t->next = head;
                s_t = head;
            }
        }else{
            if(g_h == NULL){
                g_h = g_t = head;
            }else{
                g_t->next = head;
                g_t = head;
            }
        }
        head = head->next;
    }
    //fix the grater list to null , if this list has some node
    if(g_t != NULL){
        g_t->next = NULL;
    }
    //if small is null we link the equal to greater
    if(s_h == NULL){
        //if equal is null return the greater
        if(e_h == NULL){
            return g_h;
        }
        e_t->next = g_h;
        return e_h;
    }
    //if equal is null we link the small to greater
    if(e_h == NULL){
        s_t->next = g_h;
        return s_h;
    }
    //if both smaller and equal list are not empty
    s_t->next = e_h;
    e_t->next = g_h;
    return s_h;
}

int main(){
    Node *head = takeInput();
    Print(head);
    cout<<endl;
    int x = 3;
    head = partition(head,x);
    cout<<"The finalize List is ->";
    Print(head);

    return 0;
}