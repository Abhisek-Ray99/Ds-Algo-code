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
class Stack{
    Node<T> *head;
    int size;
    public:
        Stack(){
            head = NULL;
            size = 0;
        }
        int getSize(){
            return size;
        }
        bool isEmpty(){
            return size == 0;
        }
        void push(T element){
            Node<T> *n = new Node<T>(element);
            n->next = head;
            head = n;
            size++;
        }
        void pop(){
            if(isEmpty()){
                cout<<"Stack Underflow"<<endl;
                return;
            }
            Node<T> *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            size--;
        }
        T top(){
            if(isEmpty()){
                cout<<"Stack Underflow"<<endl;
                return 0;
            }
            return head->data;
        }

};

int main(){
    Stack<char> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();

    cout<<s.getSize()<<endl;
    cout<<s.isEmpty()<<endl;

    return 0;
}