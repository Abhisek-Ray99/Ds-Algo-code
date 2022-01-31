#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[],int size,int k){
    priority_queue<int> pQ;
    for(int start=0; start<size; start++){
        pQ.push(arr[start]);
        if(pQ.size() > k){
            pQ.pop();
        }
    }
    return pQ.top();
}

int main(){
    int arr[] = {7,10,4,3,20,15};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    int element = kthSmallest(arr,size,k);
    cout<<k<<"th Smallest element is: "<<element;

    return 0;
}