#include<iostream>
#include<stack>
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
    cout<<"Enter the list : ";
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

bool isPalindrome(Node *head){
    Node * curr = head;
    stack<int> s;
    while(curr != NULL){
        s.push(curr->data);
        curr = curr->next;
    }
    while(head != NULL){
        int s_top = s.top();
        s.pop();
        if(head->data != s_top){
            return false;
        }
        head = head->next;
    }
    return true;
}

int main(){
    Node *head = takeInput();
    PrintLL(head);
    (isPalindrome(head) == 1) ? cout<<"\nValid Palindrome"
                              : cout<<"\nNot a Valid Palindrome";

    return 0;
}