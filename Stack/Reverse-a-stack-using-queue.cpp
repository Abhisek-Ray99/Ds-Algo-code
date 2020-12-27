#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseStack(stack<int> &s){
    queue<int> q;
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
}

void Print(stack<int> s){
     while(!s.empty()){
        cout<<"\t"<<s.top();
        s.pop();
    }
    cout<<endl;
}

int main(){
    stack<int> s;
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(8);
    s.push(10);
    s.push(12);

    cout<<"The initial Stack is : ";
    Print(s);
    reverseStack(s);
    cout<<"The final Stack is : ";
    Print(s);

    return 0;
}

