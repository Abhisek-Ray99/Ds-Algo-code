// Sort Array of 0s 1s 2s

#include<iostream>
using namespace std;

void Sort012_s(int arr[],int size){
    int low = 0;
    int high = size - 1;
    int mid = 0;
    while(mid <= high){
        switch (arr[mid]){
        case 0: 
            swap(arr[low++],arr[mid++]);
            break;
        case 1: 
            mid++;
            break;
        case 2: 
            swap(arr[mid],arr[high--]);
            break;
        
        default:
            break;
        }
    }
}

int main(){
    int arr[] = {1,2,0,1,1,0,2,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    Sort012_s(arr,size);
    for(int start=0; start<size; start++){
        cout<<arr[start]<<" ";
    }

    return 0;
}