// Implement a Stack using Queue

#include<iostream>
#include<queue>
using namespace std;

class Stack{
    queue<int> Q1;
    queue<int> Q2;
    int curr_size;
    public:
        Stack(){
            curr_size = 0;
        }
        void push(int element){
            curr_size++;
            Q2.push(element);
            while(!Q1.empty()){
                Q2.push(Q1.front());
                Q1.pop();
            }
            queue<int> Q = Q1;
            Q1 = Q2;
            Q2 = Q;
        }
        void pop(){
            if(Q1.empty()) return;
            int del =  Q1.front();
            Q1.pop();
            cout<<"\ndeleted element : "<<del;
            curr_size--;
        }
        void top(){
            if(Q1.empty()) return;
            cout<<"\nTop : "<<Q1.front();
        }
        void size(){
            cout<<"\nSize : "<<curr_size;
        }
};

int main(){
    Stack s;
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(8);
    s.push(10);
    s.size();
    s.top();
    s.pop();
    s.pop();
    s.size();
    s.top();

    return 0;
}