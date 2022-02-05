#include<bits/stdc++.h>
using namespace std;

void printStack(stack<int> s){
    while(!s.empty()){
        cout<<"-----"<<endl<<"| ";
        cout<<s.top()<<" |"<<endl;
        s.pop();
    }
    cout<<"-----";
}

void insertTop(stack<int> &s,int element){
    s.push(element);
}

void insertBottom(stack<int> &s,int element){
    stack<int> newStack;
    while(!s.empty()){
        newStack.push(s.top());
        s.pop();
    }
    s.push(element);
    while(!newStack.empty()){
        s.push(newStack.top());
        newStack.pop(); 
    }
}

stack<int> insertBottomRecursion(stack<int> s,int element){
    if(s.empty()){
        s.push(element);
    }else{
        int tempVaribale = s.top();
        s.pop();
        s = insertBottomRecursion(s,element);
        s.push(tempVaribale);
    }
    return s;
}

int main(){
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    insertTop(s,10);
    insertBottom(s,20);
    s = insertBottomRecursion(s,30);
    printStack(s);
}
