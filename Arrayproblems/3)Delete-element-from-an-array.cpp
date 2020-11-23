#include<iostream>
using namespace std;

int delete_ele(int arr[],int size,int ele){
    int s;
    for(s=0; s<size; s++){
        if(arr[s] == ele){
            break;
        }
    }
    if(s<size){
        size = size-1;
        for(int s2=s; s2<size; s2++){
            arr[s2] = arr[s2+1];
        }

    }
    return size;
}

int main(){
    int arr[] = {2,4,6,8,10,12,14};
    int size = sizeof(arr)/sizeof(arr[0]);
    int ele = 6;
    size = delete_ele(arr,size,ele);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}