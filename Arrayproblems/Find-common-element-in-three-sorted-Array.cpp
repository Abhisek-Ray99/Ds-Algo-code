#include<iostream>
using namespace std;

void findCommon(int arr1[],int arr2[],int arr3[],int size1,int size2,int size3){
    int i=0,j=0,k=0;
    while(i<size1 && j<size2 && k<size3){
        if(arr1[i] == arr2[j] && arr2[j] == arr3[k]){
            cout<<arr1[i]<<" ";
            i++,j++,k++;
        }else if(arr1[i] < arr2[j]){
            i++;
        }else if(arr2[j] < arr3[k]){
            j++;
        }else{
            k++;
        }
    }
}

int main(){
    int arr1[] = {1,5,5};
    int arr2[] = {3,4,5,5,10};
    int arr3[] = {5,5,10,20};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    int size3 = sizeof(arr3)/sizeof(arr3[0]);
    
    cout<<"Common elements are : ";
    findCommon(arr1,arr2,arr3,size1,size2,size3);
    return 0;
}