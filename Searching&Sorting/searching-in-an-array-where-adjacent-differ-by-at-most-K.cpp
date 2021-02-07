// searching in an array where adjacent differ by at most k

#include<iostream>
using namespace std;

int search(int arr[],int size,int element,int difference){
    int start = 0;
    while(start < size){
        if(arr[start] == element) return start;
        start = start + max(1,abs(arr[start]-element)/difference);
    }
    cout<<"Number is not present!";
    return -1;
}

int main(){
    int arr[] = {2,5,8,8,11,14};
    int size = sizeof(arr)/sizeof(arr[0]);
    int element = 11;
    int difference = 3;
    int index = search(arr,size,element,difference);
    cout<<"Element "<<element<<" is present at index : "<<index;

    return 0;
}