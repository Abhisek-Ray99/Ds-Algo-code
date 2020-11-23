#include<iostream>
using namespace std;

int linear(int arr[],int size,int x){
    for(int i=0; i<size; i++){
        if(arr[i] == x) return i;
    }
    return -1;
}

int main(){
    int arr[] = {10,20,30,40,50,60};
    int size = sizeof(arr)/sizeof(arr[0]);
    int x = 60;
    int result = linear(arr,size,x);
    (result == -1) ? cout<<"The element is not found"
                   : cout<<"The element is found at : "<<result<<" position";

    return 0;
}