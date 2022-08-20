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

void PrintLL(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<"-> ";
        temp = temp->next;
    }
    cout<<"NULL";
}

Node *reverseLL(Node *head, int n){
    Node *prev = NULL;
    Node *curr = head;
    Node *temp = NULL;
    Node *tail = NULL;
    Node *newHead = NULL;
    Node *join = NULL;
    int group = 0;
    while(curr){
        join = curr;
        group = n;
        prev = NULL;

        while(curr && group--){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        if(!newHead){
            newHead = prev;
        }
        if(tail){
            tail->next = prev;
        }
        tail = join;
    }
    return newHead;
}

--------------------------------------or --------------------------------------
  node *reverse (node *head, int k)
    { 
        // Complete this method
        node *curr = head;
        node *prev = NULL;
        node *nxt = NULL;
        
        node *newhead = NULL;
        node *join = NULL;
        node *tail = NULL;
        
        while(curr != NULL){
            join = curr;
            int count = 1;
            prev = NULL;
            while(curr != NULL && count <= k){
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
                count++;
            }
            if(newhead == NULL) newhead = prev;
            if(tail != NULL) tail->next = prev;
            tail = join;
        }
        return newhead;
    }

-------------------------------------------------------------------

int main(){
    Node *head = takeInput();
    cout<<"The initial list is : ";
    PrintLL(head);
    cout<<endl;
    cout<<"enter number of group to reverse -> ";
    int n;
    cin>>n;
    head = reverseLL(head,n);
    cout<<"The final list is : ";
    PrintLL(head);

    return 0;
}
