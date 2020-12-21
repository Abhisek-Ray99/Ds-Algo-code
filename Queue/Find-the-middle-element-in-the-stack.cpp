#include<iostream>
using namespace std;

class DLLNode{
    public:
       int data;
       DLLNode *next;
       DLLNode *prev;
};
class Stack{
    public:
       int count;
       DLLNode *head;
       DLLNode *mid; 
};
Stack *createStack(){
    Stack *st = new Stack();
    st->count = 0;
    return st;
};
void push(Stack *st, int new_data){
    DLLNode *new_Node = new DLLNode();
    new_Node->data = new_data; 
    new_Node->prev = NULL;
    new_Node->next = st->head;
    st->count += 1;
    if(st->count == 1){
        st->mid = new_Node;
    }else{
        st->head->prev = new_Node;
        if(!(st->count & 1)){
            st->mid = st->mid->prev;
        }
    }
    st->head = new_Node;
}
int pop(Stack *st){
    if(st->count == 0){
        cout<<"Stack is EMPTY"<<endl;
        return -1;
    }
    DLLNode *temp_head = st->head;
    int item = temp_head->data;
    st->head = temp_head->next;
    if(st->head != NULL){
        st->head->prev = NULL;
    }
    st->count -= 1;
    if((st->count) & 1){
        st->mid = st->mid->next;
    }
    free(temp_head);
    return item;
}
int stackMiddle(Stack *st){
    if(st->count == 0){
        cout<<"Stack is EMPTY"<<endl;
        return -1;
    }
    return st->mid->data;
}

int main(){
    Stack *st = new Stack();
    push(st, 2);
    push(st, 4);
    push(st, 6);
    push(st, 8);
    push(st, 10);
    push(st, 12);
    push(st, 14);

    cout<<pop(st)<<endl;
    cout<<pop(st)<<endl;
    cout<<stackMiddle(st);

    return 0;
}