#include<iostream>
using namespace std;

void merge_Array(int arr[],int x[],int y[],int s,int e){
    int mid = s+(e-s)/2;
    int i = s;
    int j = mid+1;
    int k = s;
    while(i<=mid && j<=e){
        if(x[i] < y[j]){
            arr[k] = x[i];
            i++;
            k++;
        }else{
            arr[k] = y[j];
            j++;
            k++; 
        }
    }
    while(i<=mid){
        arr[k] = x[i];
        i++;
        k++;
    }
    while(j<=e){
        arr[k] = y[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[],int s,int e){
    if(s >= e){
        return;
    }
    int mid = s+(e-s)/2;
    int x[50],y[50];
    for(int i=0; i<=mid; i++){
        x[i] = arr[i];
    }
    for(int i=mid+1; i<=e; i++){
        y[i] = arr[i];
    }
    merge_sort(x,s,mid);
    merge_sort(y,mid+1,e);
    merge_Array(arr,x,y,s,e);
}

int main(){
    int arr[] = {12,3,2,1,10,5,20,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr,0,size-1);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}