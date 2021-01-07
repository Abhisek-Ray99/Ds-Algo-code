#include<iostream>
#include<unordered_set>
using namespace std;

bool subArrsum(int arr[],int size){
    unordered_set<int> _SubArrsum;
    int sum = 0;
    for(int i=0; i<size; i++){
        sum += arr[i];
        if(sum == 0 || _SubArrsum.find(sum) != _SubArrsum.end()){
            return true;
        } 
        _SubArrsum.insert(sum);
    }
    return false;
}

int main(){
    int arr[] = {4,2,-3,1,6};
    int size = sizeof(arr)/sizeof(arr[0]);

    (subArrsum(arr,size) == 1) ? cout<<"Found the sub array which sum is equal to zero" : cout<<"Oops!!! ,There no subarray exists";

    return 0;
}