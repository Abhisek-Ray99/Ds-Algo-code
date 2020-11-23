#include<iostream>
using namespace std;

void bubble_sort(int arr[],int size){
    for(int s=0; s<size; s++){
        for(int s2=0; s2<size-s-1; s2++){
            if(arr[s2] > arr[s2+1]){
                int temp = arr[s2];
                arr[s2] = arr[s2+1];
                arr[s2+1] = temp;
            }
        }    
    }
}

int main(){
    int arr[] = {3,8,1,2,10,4,9};
    int size = sizeof(arr)/sizeof(arr[0]);

    bubble_sort(arr,size);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}