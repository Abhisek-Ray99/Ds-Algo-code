#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;
    q.push(2);
    q.push(4);
    q.push(6);
    q.push(8);
    q.push(10);
    q.push(12);

    cout<<q.front()<<endl;
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;
    q.pop();
    q.pop();
    q.pop();
    q.push(14);
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;

    return 0;
}