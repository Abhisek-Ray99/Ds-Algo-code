#include<iostream>
using namespace std;
#define MAX 1000

bool hashTable[MAX+1][2];

bool search(int ele){
    if(ele>0){
        if(hashTable[ele][0] == 1){
            return true;
        }else{
            return false;
        }
    }else{
        if(hashTable[abs(ele)][1] == 1){
            return true;
        }else{
            return false;
        }
    }   
}

void insert(int arr[],int size){
    for(int start=0; start<size; start++){
        if(arr[start] > 0){
            hashTable[arr[start]][0] = 1;
        }else{
            hashTable[abs(arr[start])][1] = 1;
        }
    }
}

int main(){
    int arr[] = {-1,2,12,6,4,22,9,-2};
    int size = sizeof(arr)/sizeof(arr[0]);
    insert(arr,size);
    cout<<"Enter a element to find : ";
    int element;
    cin>>element;
    (search(element)) ? cout<<"Element is found" : cout<<"Element not found";


}
