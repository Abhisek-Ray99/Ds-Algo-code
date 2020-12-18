#include<iostream>
using namespace std;

template<typename T>
class Stack{
    T *arr;
    int capacity;
    int nextIndex;
    public:
       Stack(){
           capacity = 4;
           arr = new T[capacity];
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
               T *newArr = new T[2*capacity];
               for(int i=0; i<capacity; i++){
                   newArr[i] = arr[i];
               }
               delete []arr;
               arr = newArr;
               capacity = 2 * capacity;
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
       T top(){
           if(isEmpty()){
               cout<<"Stack Underflow"<<endl;
               return -1;
           }
           return arr[nextIndex - 1];
       }
};

int main(){
    Stack <char>s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);
    s.push(105);
    s.push(106);

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