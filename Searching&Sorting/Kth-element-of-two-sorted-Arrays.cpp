// Kth element of two sorted arrays

#include<iostream>
using namespace std;

int KthElement(int arr1[],int arr2[],int size1,int size2,int k){
    int result[size1+size2];
    int start1 = 0, start2 = 0, start3 = 0;
    while(start1 < size1 && start2 < size2){
        if(arr1[start1] < arr2[start2]){
            result[start3++] = arr1[start1++];
        }else{
            result[start3++] = arr2[start2++];
        }
    }
    while(start1 < size1) result[start3++] = arr1[start1++];
    while(start2 < size2) result[start3++] = arr2[start2++];
    return result[k-1];
}

int main(){
    int arr1[] = {12,34,45,72,90};
    int arr2[] = {20,42,86,81};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    int k = 2;
    int element = KthElement(arr1,arr2,size1,size2,k);
    cout<<"The "<<k<<"th element is : "<<element;

    return 0;
}