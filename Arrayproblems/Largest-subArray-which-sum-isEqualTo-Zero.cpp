#include<iostream>
#include<unordered_map>
using namespace std;

int maxLen(int Arr[],int size){
    unordered_map<int,int> store;
    int max_Subarr = 0;
    int sum = 0;
    for(int i=0; i<size; i++){
        sum += Arr[i];
        if(sum == 0){
            max_Subarr = i+1;
        }else{
            if(store.find(sum ) != store.end()){
                max_Subarr = max(max_Subarr, i-store[sum]);
            }else{
                store[sum] = i;
            }
        }
    }
    return max_Subarr;
}

int main(){
    int arr[] = {4,2,-3,1,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int count = maxLen(arr,size);
    cout<<"Largest sub-Array is : "<<count;

    return 0;
}
