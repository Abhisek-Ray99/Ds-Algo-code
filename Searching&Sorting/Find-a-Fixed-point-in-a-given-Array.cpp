// Find a fixed point (value equal to index) in a given array 

#include<iostream>
using namespace std;

int fixedPoint(int arr[],int start,int end){
    if(end < start) return 0;
    int mid = start+(end-start)/2;
    if(mid == arr[mid]) return mid;
    if(mid < arr[mid]) return fixedPoint(arr,start,mid-1);
    else return fixedPoint(arr,mid+1,end);
    return -1;
}

int main(){
    int arr[] = {1,2,4,3,5,6,8};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Fixed point is : "<<fixedPoint(arr,0,size-1);

    return 0;
}