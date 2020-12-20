#include<iostream>
using namespace std;

template<typename T>
class Node{
    public:
    int data;
    Node<T> *next;
    Node(T data){
        this->data = data;
        next = NULL;
    }
};

template<typename T>
class Queue{
    Node<int> *head;
    Node<int> *tail;
    int size;
    public:
      Queue(){
          head = NULL;
          tail = NULL;
          size = 0;
      }
      int getSize(){
          return size;
      }
      bool isEmpty(){
          return size == 0;
      }
      void push(int element){
          Node<int> *n = new Node<int>(element);
          if(head == NULL){
              head = n;
              tail = n;
          }else{
              tail->next = n;
              tail = n;
          }
          size++;
      }
      int front(){
          if(isEmpty()){
            return 0;
          }
          return head->data;
      }
      void pop(){
          if(isEmpty()){
              return;
          }
          Node<int> *temp = head;
          head = head->next;
          temp->next = NULL;
          delete temp;
          size--;
      }
};

int main(){
    Queue<int> q;
    q.push(2);
    q.push(4);
    q.push(6);
    q.push(8);
    
    cout<<q.front()<<endl;
    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;

    return 0;
}