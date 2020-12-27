#include<iostream>
using namespace std;

void reverseArr(int arr[], int start, int end){
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void PrintArr(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {2,4,6,8,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"The original array is : ";
    PrintArr(arr,size);
    reverseArr(arr,0,size-1);
    cout<<"The reverse array is : ";
    PrintArr(arr,size);

    return 0;
}


///////  ------OR-----   ///////

#include<iostream>
#include<algorithm>
using namespace std;


void PrintArr(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {2,4,6,8,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"The original array is : ";
    PrintArr(arr,size);
    reverse(arr, arr+size);
    cout<<"The reverse array is : ";
    PrintArr(arr,size);

    return 0;
}
