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
       int size(){
           return nextIndex;
       }
       bool isEmpty(){
           return nextIndex == 0;
       }
       void push(int element){
           if(nextIndex == capacity){
               int *newArr = new int[2*capacity];
               for(int i=0; i<capacity; i++){
                   newArr[i] = arr[i];
               }
               delete []arr;
               arr = newArr;
               capacity = 2*capacity;
           }
           arr[nextIndex] = element;
           nextIndex++;
       }
       void pop(){
           if(isEmpty()){
               cout<<"Stack Underflow"<<endl;
               return;
           }
           nextIndex--;
       }
       int top(){
           if(isEmpty()){
               cout<<"Stack Underflow"<<endl;
               return -1;
           }
           return arr[nextIndex-1];
       }
};

int main(){
    Stack s;
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(8);
    s.push(10);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
    return 0;
}