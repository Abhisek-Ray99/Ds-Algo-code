// Maximum and Minimum of an Array using minimum number of comparisons

#include<iostream>
using namespace std;

class Pair{
    public:
        int min;
        int max;
};

Pair getMinMax(int arr[],int size){
    Pair minmax;
    int start;
    if(size == 1){
        minmax.max = arr[0];
        minmax.min = arr[0];
        return minmax;
    }
    if(arr[0] > arr[1]){
        minmax.max = arr[0];
        minmax.min = arr[1];
    }else{
        minmax.max = arr[1];
        minmax.min = arr[0];
    }
    for(int start=2; start<size; start++){
        if(arr[start] > minmax.max) minmax.max = arr[start];
        else if(arr[start] < minmax.min) minmax.min = arr[start];
    }
    return minmax;
}

int main(){
    int arr[] = {123,1,1234,12,12345};
    int size = sizeof(arr)/sizeof(arr[0]);
    Pair minmax = getMinMax(arr,size);
    cout<<"Maximum element is : "<<minmax.max<<endl<<"Minimum element is : "<<minmax.min;
    

    return 0;
}