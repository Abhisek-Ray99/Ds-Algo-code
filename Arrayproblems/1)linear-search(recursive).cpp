#include<iostream>
using namespace std;

int linear(int arr[],int left,int right,int x){
    if(right < left) return -1;
    if(arr[left] == x) return left;
    if(arr[right] == x) return right;
    return linear(arr,left++,right--,x);
}

int main(){
    int arr[] = {10,20,30,40,50,60};
    int size = sizeof(arr)/sizeof(arr[0]);
    int x = 30;
    int result = linear(arr,0,size-1,x);
    (result != -1) ? cout<<"found : "<<result
                   : cout<<"not found";


    return 0;
}