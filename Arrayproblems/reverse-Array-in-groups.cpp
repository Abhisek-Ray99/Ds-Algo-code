// reverse array in groups

#include<iostream>
using namespace std;

void reverse_givensize(int arr[],int size,int given_size){
    for(int start=0; start<size; start += given_size){
        int left = start;
        int right = min(start+given_size-1, size-1);
        while(left < right){
            swap(arr[left++],arr[right--]);
        }
    }
}

int main(){ 
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int given_size = 4;
    reverse_givensize(arr,size,given_size);
    for(int start=0; start<size; start++){
        cout<<arr[start]<<" ";
    }


    return 0;
}