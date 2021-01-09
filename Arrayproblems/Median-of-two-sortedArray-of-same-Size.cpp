#include<iostream>
using namespace std;

int getMedian(int arr1[],int arr2[],int size){
    int start_arr1=0,start_arr2=0;
    int count;
    int m1=-1,m2=-1;
    for(count=0; count<=size;count++){
        if(start_arr1 == size){
            m1 = m2;
            m2 = arr2[0];
            break;
        }else if(start_arr2 == size){
            m1 = m2;
            m2 = arr1[0];
            break;
        }
        if(arr1[start_arr1] <= arr2[start_arr2]){
            m1 = m2;
            m2 = arr1[start_arr1];
            start_arr1++;
        }else{
            m1 = m2;
            m2 = arr2[start_arr2];
            start_arr2++;
        }
    }
    return (m1+m2)/2;
}

int main(){
    int arr1[] = {1,12,15,26,38};
    int arr2[] = {2,13,17,30,45};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);

    if(size1 = size2){
        cout<<"Median is : "<<getMedian(arr1,arr2,size1);
    }else{
        cout<<"The size of two array is unequal";
    }

    return 0;
}