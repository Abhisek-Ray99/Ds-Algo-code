// find the equilibrium point in an array

#include<iostream>
using namespace std;

int equilibriumPoint(int arr[],int size){
    int sum = 0;
    int leftSum = 0;
    for(int start=0; start<size; start++){
        sum += arr[start];
    }
    for(int start=0; start<size; start++){
        sum -= arr[start];
        if(leftSum == sum) return start;
        leftSum += arr[start];
    }
    return -1;
}

int main(){
    int arr[] = {-2,4,6,-2,2,-5,2,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int index = equilibriumPoint(arr,size);
    cout<<"The first equilibrium index is : "<<index;

    return 0;
}