#include<iostream>
using namespace std;

class Stack{
    int *arr;
    int nextIndex;
    int capacity;
    public:
       Stack(){
           capacity = 4;
           arr = new int[capacity];
           nextIndex = 0;
       }
       Stack(int cap){
           capacity = cap;
           arr = new int[cap];
           nextIndex = 0;
       }
       int size(){
           return nextIndex;
       }
       bool isEmpty(){
           return nextIndex == 0;
       }
       void push(int element){
           if(nextIndex == capacity){
               cout<<"Stack is Overflow"<<endl;
               return;
           }
           arr[nextIndex] = element;
           nextIndex++;
       }
       void pop(){
           if(isEmpty()){
               cout<<"Stack is Underflow"<<endl;
               return;
           }
           nextIndex--;
       }
       int top(){
           if(isEmpty()){
               cout<<"Stack is Underflow"<<endl;
               return -1;
           }
           return arr[nextIndex-1];
       }
};

int main(){
    //first stack
    Stack s(4);
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(8);
    s.push(10);
    cout<<endl;
    cout<<s.size();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;

    return 0;
}