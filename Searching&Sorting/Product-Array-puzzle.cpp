// product Array puzzle

#include<iostream>
#include<vector>
using namespace std;

vector<int> productOfArr(vector<int> &arr){
    int size = arr.size();
    vector<int> L(size,1);
    vector<int> R(size,1);
    vector<int> result(size,1);
    for(int start=1; start<size; ++start){
        L[start] = L[start-1] * arr[start-1];
    }
    for(int start=size-2; start>=0; --start){
        R[start] = R[start+1] * arr[start+1];
    }
    for(int start=0; start<size; ++start){
        result[start] = L[start] * R[start];
    }
    return result;
}

int main(){ 
    vector<int> arr = {1,2,3,4,5};
    vector<int> result = productOfArr(arr);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }

    return 0;
}