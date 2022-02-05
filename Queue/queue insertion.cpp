#include<bits/stdc++.h>
using namespace std;

void printQueue(queue<int> q){
    while(!q.empty()){
        cout<<" | "<<q.front();
        q.pop();
    }
    cout<<" |";
}

void insertLast(queue<int> &q,int element){
    q.push(element);
}

void insertFirst(queue<int> &q,int element){
    queue<int> extraQ;
    while(!q.empty()){
        extraQ.push(q.front());
        q.pop();
    }
    q.push(element);
    while(!extraQ.empty()){
        q.push(extraQ.front());
        extraQ.pop();
    }
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    insertLast(q,15);
    insertLast(q,20);
    insertFirst(q,10);
    q = insertFirstRecursion(q,25);
    printQueue(q);

    return 0;
}
