#include<iostream>
using namespace std;

int* insert_ele(int arr[],int size,int pos,int ele){
    size++;
    for(int s=size; s>=pos; s--){
        arr[s] = arr[s-1];
    }
    arr[pos-1] = ele;
    return arr;
}

int main(){
    int arr[] = {10,20,30,40,50,60};
    int size = sizeof(arr)/sizeof(arr[0]);
    int pos = 3, ele = 100;
    insert_ele(arr,size,pos,ele);
    for(int i=0; i<size+1; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}