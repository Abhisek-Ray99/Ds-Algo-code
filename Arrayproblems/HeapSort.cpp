#include<iostream>
using namespace std;

void heapify(int arr[],int size,int index){
    int left = 2*index+1;
    int right = 2*index+2;
    int large = index;
    if(left < size && arr[left] > arr[index]){
        large = left;
    }
    if(right < size && arr[right] > arr[large]){
        large = right;
    }
    if(large != index){
        swap(arr[index],arr[large]);
        heapify(arr,size,large);
    }
}

void buildHeap(int arr[], int size){
    for(int start=(size/2)-1; start>=0; start--){
        heapify(arr,size,start);
    }
}

void HeapSort(int arr[], int size){
    buildHeap(arr, size);
    for (int start = size - 1; start >= 0; start--){
        swap(arr[0],arr[start]);
        heapify(arr,start,0);
    }
}

int main(){
    int arr[] = {12, 4, 2, 1, 43, 52, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    HeapSort(arr, size);
    for (int start = 0; start < size; start++){
        cout << arr[start] << " ";
    }

    return 0;
}