#include<bits/stdc++.h>
using namespace std;

int kthLargest(int arr[],int size, int k){
    priority_queue<int,vector<int>,greater<int>> min_Heap;
    for(int start=0; start<size; start++){
        min_Heap.push(arr[start]);
        if(min_Heap.size() > 3){
            min_Heap.pop();
        }
    }
    return min_Heap.top();
}

int main(){
    int arr[] = {7,10,4,3,20,15};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    int element = kthLargest(arr,size,k);
    cout<<element;

    return 0;
}
