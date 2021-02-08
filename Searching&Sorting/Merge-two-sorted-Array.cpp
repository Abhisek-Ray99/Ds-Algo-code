// Merge two sorted Array

#include<iostream>
using namespace std;

void mergeTwoArray(int arr1[],int arr2[],int size1,int size2,int result[]){
    int start1 = 0;
    int start2 = 0;
    int start3 = 0;
    while(start1<size1 && start2<size2){
        if(arr1[start1]<arr2[start2]) result[start3++] = arr1[start1++];
        else result[start3++] = arr2[start2++];
    }
    while(start1 < size1) result[start3++] = arr1[start1++];
    while(start2 < size2) result[start3++] = arr2[start2++];
}

int main(){
    int arr1[] = {1,4,6,8};
    int arr2[] = {2,3,5,7};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    int result[size1+size2];
    mergeTwoArray(arr1,arr2,size1,size2,result);    
    cout<<"The merge Array is : ";
    for(int i=0; i<size1+size2; i++){
        cout<<result[i]<<" ";
    }

    return 0;
}