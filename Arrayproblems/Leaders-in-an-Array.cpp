// Leaders in an array

#include<iostream>
using namespace std;

void findLeaders(int arr[],int size){
    int Right_max = arr[size-1];
    cout<<Right_max<<" ";
    for(int start=size-2; start>=0; start--){
        if(Right_max <= arr[start]){
            Right_max = arr[start];
            cout<<Right_max<<" ";
        }
    }
}

int main(){
    int arr[] = {1,23,5,6,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"The leaders are : ";
    findLeaders(arr,size);

    return 0;
}