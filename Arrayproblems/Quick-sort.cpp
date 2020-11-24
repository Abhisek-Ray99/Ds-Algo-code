#include<iostream>
using namespace std;

int partition(int arr[],int s,int e){
    int pivot = arr[e];
    int i = (s-1);
    for(int j=s; j<=e-1; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[e]);
    return (i+1);
}

void quick_sort(int arr[],int s,int e){
    if(s<e){
        int pivot = partition(arr,s,e);
        quick_sort(arr,s,pivot-1);
        quick_sort(arr,pivot+1,e);
    }
}

int main(){
    int arr[] = {7,5,2,10,8,12,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    quick_sort(arr,0,size-1);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}