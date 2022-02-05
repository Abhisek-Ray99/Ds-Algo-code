#include<bits/stdc++.h>
using namespace std;

void printHashMap(int arr[],int size){
    unordered_map<int,int> M;
    for(int start=0; start<size; start++){
        M[arr[start]]++;
    }
    for(auto it:M){
        cout<<it.first<<" "<<it.second<<endl;
    }
}

int getMaxFreq(int arr[],int size){
    unordered_map<int,int> M;
    for(int start=0; start<size; start++){
        M[arr[start]]++;
    }
    int max = INT_MIN;
    int maxElement;
    for(auto it:M){
        if(it.second > max){
            max = it.second;
            maxElement = it.first;
        }
    }
    return maxElement;
}

int main(){
    int arr[] = {1,2,5,1,6,6,4,6,7,7,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    printHashMap(arr,size);
    int element = getMaxFreq(arr,size);
    cout<<element;

    return 0;
}
