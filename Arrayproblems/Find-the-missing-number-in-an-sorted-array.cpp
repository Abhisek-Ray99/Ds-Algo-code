//find the missing number in an sorted array

#include<iostream>
using namespace std;
int findMissingNumber(int arr[],int size){
    int total = size * (size + 1)/2;
    int sum = 0;
    for(int start=0; start<size-1; start++){
        sum += arr[start];
    }
    return total-sum;
}

int main(){
    int arr[] = {1,2,3,4,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int missing_element = findMissingNumber(arr,size);
    cout<<"The missing element is : "<<missing_element;

    return 0;
}