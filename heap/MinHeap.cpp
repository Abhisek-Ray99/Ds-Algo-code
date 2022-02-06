#include<bits/stdc++.h>
using namespace std;

void printMinHeap(int HeapArr[],int size){
    for(int start=1; start<=size; start++){
        cout<<HeapArr[start]<<" ";
    }
}

void Min_heapify(int *HeapArr,int size,int start){
    int Node_P = HeapArr[start];
    int childindex = start*2;
    while(childindex <= size){
        if(childindex < size && HeapArr[childindex+1] < HeapArr[childindex]){
            childindex += 1;
        }
        if(Node_P < HeapArr[childindex]){
            break;
        }else if(Node_P >= HeapArr[childindex]){
            HeapArr[childindex/2] = HeapArr[childindex];
            childindex *= 2;
        }
    }
    HeapArr[childindex/2] = Node_P;
    return;
}

void buildMinHeap(int *HeapArr,int size){
    for(int start=size/2; start >= 1; start--){
        Min_heapify(HeapArr,size,start);
    }
}

int main(){
    int HeapArr[20],size;
    cout<<"Enter number of element in Array: ";
    cin>>size;
    for(int start=1; start<=size; start++){
        cin>>HeapArr[start];
    }
    buildMinHeap(HeapArr,size);

    cout<<"The MinHeap is: "<<endl;
    printMinHeap(HeapArr,size);

    return 0;
}
