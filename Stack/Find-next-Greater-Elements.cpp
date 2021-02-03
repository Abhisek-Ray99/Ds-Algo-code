// Find the next Greater Elements

#include<iostream>
#include<stack>
using namespace std;

void nextGreater(int arr[],int size){
    stack<int> q;
    q.push(arr[0]);
    for(int start=1; start<size; start++){
        if(q.empty()){
            q.push(arr[start]);
        }
        while(!q.empty() && arr[start] > q.top()){
            cout<<q.top()<<" next greater element is -> "<<arr[start]<<endl;
            q.pop();
        }
        q.push(arr[start]);
    }
    while(!q.empty()){
        cout<<q.top()<<" next greater element is -> "<<-1<<endl;
        q.pop();
    }
}

int main(){
    int arr[] = {10,20,12,30,40,4,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    nextGreater(arr,size);

    return 0;
}