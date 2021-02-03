// Find the next Smaller Elements

#include<iostream>
#include<stack>
using namespace std;

void nextSmaller(int arr[],int size){
    stack<int> q;
    q.push(arr[0]);
    for(int start=1; start<size; start++){
        if(q.empty()){
            q.push(arr[start]);
        }
        while(!q.empty() && arr[start] < q.top()){
            cout<<q.top()<<" next smaller element is -> "<<arr[start]<<endl;
            q.pop();
        }
        q.push(arr[start]);
    }
    while(!q.empty()){
        cout<<q.top()<<" next smaller element is -> "<<-1<<endl;
        q.pop();
    }
}

int main(){
    int arr[] = {12,2,10,1,8,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    nextSmaller(arr,size);

    return 0;
}