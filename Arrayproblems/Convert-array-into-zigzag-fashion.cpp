// convert array into zigzag fashion

#include<iostream>
using namespace std;

void zigzagConvertion(int arr[],int size){
    bool flag = true;
    for(int start=0; start<=size-2; start++){
        if(flag){
            if(arr[start] > arr[start+1]){
                swap(arr[start],arr[start+1]);
            }
        }else{
            if(arr[start] < arr[start+1]){
                swap(arr[start],arr[start+1]);
            }
        }
        flag = !flag;
    }
}

int main(){
    int arr[] = {4,3,7,8,6,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    zigzagConvertion(arr,size);
    for(int start=0; start<size; start++){
        cout<<arr[start]<<" ";
    }

    return 0;
}