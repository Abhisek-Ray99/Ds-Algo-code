// maximum sum such that no 2 elements are adjacent

#include<iostream>
using namespace std;

int findMaxSum(int arr[],int size){
    int incl = arr[0];
    int excl = 0;
    int excl_new;
    int start;
    for(start=1; start<size; start++){
        excl_new = (incl > excl) ? incl : excl;
        incl = excl + arr[start];
        excl = excl_new;
    }
    return ((incl > excl) ? incl : excl);
}

int main(){
    int arr[] = {20,30,10,40,50,60};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum = findMaxSum(arr,size);
    cout<<"Max sum : "<<sum;

    return 0;
}