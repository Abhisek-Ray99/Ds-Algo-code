// find a pair with a given difference

#include<iostream>
using namespace std;

bool findPair(int arr[],int size,int difference){
    int first = 0;
    int second = 1;
    while(first < size && second < size){
        if(first != second && arr[second] - arr[first] == size){
            cout<<"Pair found : ("<<arr[first]<<","<<arr[second]<<")";
            return true;
        }
        else if(arr[second] - arr[first] < size) second++;
        else first++;
    }
    cout<<"Pair not found";
    return false;
}

int main(){
    int arr[] = {1,2,3,4,8,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int difference = 4;
    findPair(arr,size,difference);

    return 0;
}