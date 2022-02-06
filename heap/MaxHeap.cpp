#include<bits/stdc++.h>
using namespace std;

void printHeapArr(int HeapArr[],int size){
    for(int start=1; start<=size; start++){
        cout<<HeapArr[start]<<" ";
    }
    cout<<endl;
}

void Max_heapify(int *HeapArr,int size,int start){
    int compare_P = HeapArr[start];
    int compare_C_index = start*2;
    while(compare_C_index <= size){
        if(compare_C_index < size && HeapArr[compare_C_index+1] > HeapArr[compare_C_index]){
            compare_C_index += 1;
        }
        if(compare_P > HeapArr[compare_C_index]){
            break;
        }else if(compare_P <= HeapArr[compare_C_index]){
            HeapArr[compare_C_index/2] = HeapArr[compare_C_index];
            compare_C_index *= 2;
        }
    }
    HeapArr[compare_C_index/2] = compare_P;
    return;
}

void buildMaxHeap(int *HeapArr,int size){
    for(int start=size/2; start>=1; start--){
        Max_heapify(HeapArr,size,start);
    }
}

int main(){
    int HeapArr[10],size;
    cout<<"Enter number of element in HeapArray: ";
    cin>>size;
    for(int start=1; start<=size; start++){
        cin>>HeapArr[start];
    }

    buildMaxHeap(HeapArr,size);

    cout<<"The MaxHeap is: "<<endl;
    printHeapArr(HeapArr,size);

    return 0;
}
