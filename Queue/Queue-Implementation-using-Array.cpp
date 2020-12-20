#include<iostream>
using namespace std;

template<typename T>
class Queue{
    T *arr;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;
    public:
        Queue(){
            capacity = 5;
            arr = new T[capacity];
            nextIndex = 0;
            firstIndex = -1 ;
            size = 0;
        }
        Queue(int cap){
            capacity = cap;
            arr = new T[capacity];
            nextIndex = 0;
            firstIndex = -1;
            size = 0;
        }
        int getSize(){
            return size;
        }
        bool isEmpty(){
            return size == 0;
        }
        void push(int element){
            if(size == capacity){
                cout<<"Queue FULL"<<endl;
                return;
            }
            arr[nextIndex] = element;
            nextIndex = (nextIndex + 1) % capacity;
            if(firstIndex == -1){
                firstIndex = 0;
            }
            size++;
        }
        T front(){
            if(isEmpty()){
                cout<<"Queue EMPTY"<<endl;
                return 0;
            }
            return arr[firstIndex];
        }
        T rear(){
            if(isEmpty()){
                cout<<"Queue EMPTY"<<endl;
                return 0;
            }
            return arr[nextIndex];
        }
        void pop(){
            if(isEmpty()){
                cout<<"Queue EMPTY"<<endl;
                return;
            }
            firstIndex = (firstIndex + 1) % capacity;
            size--;
        }
};

int main(){
    Queue<int> q(5);
    q.push(2);
    q.push(4);
    q.push(6);
    q.push(8);
    q.push(10);
    cout<<q.front()<<endl;

    q.pop();
    q.pop();
    q.pop();

    cout<<q.front()<<endl;
    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;

    q.push(12);
    q.push(14);
    cout<<q.front()<<endl;
    return 0;
}