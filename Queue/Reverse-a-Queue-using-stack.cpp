#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQueue(queue<int> &q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

void PrintQueue(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<"  ";
        q.pop();
    }
    cout<<endl;
} 

int main(){
    queue<int> q;
    q.push(2);
    q.push(4);
    q.push(6);
    q.push(8);
    q.push(10);
    q.push(12);

    cout<<"The initial Queue is : ";
    PrintQueue(q);
    reverseQueue(q);
    cout<<"The final Queue is : ";
    PrintQueue(q);

    return 0;
}