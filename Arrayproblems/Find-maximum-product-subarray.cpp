#include<iostream>
using namespace std;

int maxProduct(int *arr,int size){
    long long max_product = arr[0];
    long long min_product = arr[0];
    long long product = arr[0];
    for(int i=1; i<size; i++){
        if(arr[i] < 0){
            swap(min_product,max_product);
        }
        max_product = max((long long)arr[i],max_product*arr[i]);
        min_product = min((long long)arr[i],min_product*arr[i]);
        if(max_product > product){
            product = max_product;
        }
    }
    return product;
}

int main(){
    int arr[] = {6,-3,-10,0,2};
    int size = sizeof(arr)/sizeof(arr[0]);

    long long result = maxProduct(arr,size);
    cout<<"The maximum product of sub array is : "<<result;

    return 0;
}