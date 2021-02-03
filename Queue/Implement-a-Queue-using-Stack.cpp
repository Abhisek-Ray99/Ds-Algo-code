// Implement a Queue using Stack

#include<iostream>
#include<stack>
using namespace std;

class Queue{
    stack<int> S1;
    stack<int> S2;
    int curr_size;
    public:
        Queue(){
            curr_size = 0;
        }
        void push(int element){
            curr_size++;
            while(!S1.empty()){
                S2.push(S1.top());
                S1.pop();
            }
            S1.push(element);
            while(!S2.empty()){
                S1.push(S2.top());
                S2.pop();
            }
        }
        void pop(){
            if(S1.empty()) cout<<"\nQ is Empty";
            int del_ele = S1.top();
            S1.pop();
            curr_size--;
            cout<<"\nDelete element : "<<del_ele;
        }
        void front(){
            if(S1.empty()) return;
            cout<<"Front : "<<S1.top();
        }
        void size(){
            cout<<"\nSize : "<<curr_size;
        }
};

int main(){
    Queue q;
    q.push(2);
    q.push(4);
    q.push(6);
    q.front();
    q.size();
    q.pop();
    q.pop();
    q.size();
    q.pop();
    q.pop();

    return 0;
}