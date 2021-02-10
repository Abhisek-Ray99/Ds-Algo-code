// Rearrange array alternatively

#include<iostream>
using namespace std;

void RearrangeArray(int arr[],int size){
    int temp[size];
    int left = 0, right = size-1;
    int flag = true;
    for(int start=0; start<size; start++){
        if(flag) temp[start] = arr[right--];
        else temp[start] = arr[left++];
        flag = !flag;
    }
    for(int start=0; start<size; start++){
        arr[start] = temp[start];
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    RearrangeArray(arr,size);
    for(int start=0; start<size; start++){
        cout<<arr[start]<<" ";
    }

    return 0;
}