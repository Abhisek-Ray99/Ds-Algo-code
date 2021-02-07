// Find the repeating and the missing

#include<iostream>
using namespace std;

void printTwoElements(int arr[],int size){
    int start;
    cout<<"The repeating element is : ";
    for(start = 0; start<size; start++){
        if(arr[abs(arr[start]) - 1] > 0){
            arr[abs(arr[start]) - 1] = -arr[abs(arr[start]) - 1];
        }else{
            cout<<abs(arr[start]);
        }
    }
    cout<<"\nThe missing element is : ";
    for(start = 0; start< size; start++){
        if(arr[start] > 0) cout<<(start+1)<<" ";
    }
}

int main(){
    int arr[] = {7,3,3,4,5,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    printTwoElements(arr,size);

    return 0;
}