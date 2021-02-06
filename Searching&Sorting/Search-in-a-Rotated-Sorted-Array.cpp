// Search in a rotated sorted array

#include<iostream>
using namespace std;

int SearchElement(int arr[],int left,int right,int target){
    if(left > right) return -1;
    int mid = left+(right-left)/2;
    if(arr[mid] == target) return mid;
    if(arr[left] <= arr[mid]){
        if(target >= arr[left] && target <= arr[mid]){
            return SearchElement(arr,left,mid-1,target);
        }
        return SearchElement(arr,mid+1,right,target);
    }
    if(target >= arr[mid] && target < arr[right]){
        return SearchElement(arr,mid+1,right,target);
    }
    return SearchElement(arr,left,mid-1,target);
}

int main(){
    int arr[] = {4,5,6,7,8,0,1,2,3,};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 3;
    int position = SearchElement(arr,0,size-1,target);
    cout<<"The position of "<<target<<" in the arr is : "<<position;

    return 0;
}