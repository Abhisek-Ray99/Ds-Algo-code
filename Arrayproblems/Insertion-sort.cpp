#include<iostream>
using namespace std;

void Insertion_sort(int arr[],int size){
    for(int s=1; s<size; s++){
        int key = arr[s];
        int e = s-1;
        while(e>= 0 && arr[e] > key){
            arr[e+1] = arr[e];
            e = e-1; 
        }
        arr[e+1] = key;
    }
}

int main(){
    int arr[] = {7,8,5,2,4,6,3};
    int size = sizeof(arr)/sizeof(arr[0]);

    Insertion_sort(arr,size);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}