#include<iostream>
using namespace std;

int find_max(int arr[],int size){
    int max = arr[0];
    for(int start=1; start<size; start++){
        if(arr[start] > max) max = arr[start];
    }
    return max;
}

int find_min(int arr[],int size){
    int min = arr[0];
    for(int start=1; start<size; start++){
        if(arr[start] < min) min = arr[start];
    }
    return min;
}

int main(){
    int arr[] = {100,12,37,400,5,-6};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<find_max(arr,size);
    cout<<endl<<find_min(arr,size);
}
