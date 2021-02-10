// Kadane's Algorithm or find the contiguous sub-array with maximum sum

#include<iostream>
using namespace std;

int MaximumSum(int arr[],int size){
    int maxSum = INT_MIN;
    int initialSum = 0;
    for(int start=0; start<size; start++){
        initialSum = initialSum+arr[start];
        if(maxSum < initialSum){
            maxSum = initialSum;
        }
        if(initialSum < 0){
            initialSum = 0;
        }
    }
    return maxSum; 
}

int main(){
    int arr[] = {5,-2,6,1,-10,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum = MaximumSum(arr,size);
    cout<<"Maximum contiguous sum is : "<<sum;

    return 0;
}