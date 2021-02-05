// find the first and last position of an element in the sorted array


#include<iostream>
using namespace std;

void findElement(int arr[],int size,int element){
    int first = -1;
    int last = -1;
    for(int start=0; start<size; start++){
        if(element != arr[start]) continue;
        if(first == -1) first = start;
        last = start;
    }
    if(first != -1){
            cout<<"First occurrence : "<<first<<endl<<"Last occurrence : "<<last;
    }else cout<<"Not found";
}

int main(){
    int arr[] = {1,2,2,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int element = 2;
    findElement(arr,size,element);

    return 0;
}