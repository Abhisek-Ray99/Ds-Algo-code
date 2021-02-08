// Find the lowerBound and upperBound in an Array

#include<iostream>
using namespace std;

int lower_bound(int arr[],int size,int element){
    int mid;
    int low = 0;
    int high = size;
    while(low < high){
        mid = low+(high-low)/2;
        if(element <= arr[mid]) high = mid;
        else low = mid+1;
    }
    return low;
}

int upper_bound(int arr[],int size,int element){
    int mid;
    int low = 0;
    int high = size;
    while(low < high){
        mid = low+(high-low)/2;
        if(element >= arr[mid]) low = mid+1;
        else high = mid;
    }
    return low;
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int element = 4;
    int index = lower_bound(arr,size,element);
    (index == size) ? cout<<"\nLower_bound not exits"
                    : cout<<"\nLower_bound of "<<element<<" is at index : "<<index;
    index = upper_bound(arr,size,element);
    (index == size) ? cout<<"\nUpper_bound not exits"
                    : cout<<"\nUpper_bound of "<<element<<" is at index : "<<index; 

    return 0;
}