#include<iostream>
using namespace std;

int binary(int arr[],int s,int e,int x){
    while(e >= s){
        int mid = s+(e-s)/2;
        if(arr[mid] == x) return mid;
        if(arr[mid] < x){
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {10,20,30,40,50,60};
    int size = sizeof(arr)/sizeof(arr[0]);
    int x = 30;
    int result = binary(arr,0,size-1,x);
    (result != -1) ? cout<<"found : "<<result
                   : cout<<"not found";

    return 0;
}