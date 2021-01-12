#include<iostream>
using namespace std;

//moore's voting algorithm
int majorityElement(int arr[],int size){
    int major = 0;
    int count = 1;
    for(int i=1; i<size; i++){
        if(arr[major] == arr[i]){
            count++;
        }else{
            count--;
        }
        if(count == 0){
            major = i;
            count = 1;
        }
    }
    int count_ele = 0;
    for(int i=0; i<size; i++){
        if(arr[i] == arr[major]){
            count_ele++;
        }
    }
    if(count_ele > size/2) return arr[major];
    else return 0;
}

int main(){
    int arr[] = {2,7,3,7,2,7,7};
    int size = sizeof(arr)/sizeof(arr[0]);

    int candidate = majorityElement(arr,size);
    if(candidate){
        cout<<"The major element is : "<<candidate;
    }else{
        cout<<"No Majority element exists";
    }

    return 0;
}