// minimum no. of swaps required to sort the array

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int MinSwap(int arr[],int size){
    vector<pair<int,int> > result(size);
    for(int start=0; start<size; start++){
        result[start] = {arr[start],start};
    }
    sort(result.begin(),result.end());
    int count = 0;
    for(int start=0; start<size; start++){
        if(result[start].second == start) continue;
        else{
            count++;
            swap(result[start],result[result[start].second]);
            start--;
        }        
    }
    return count;
}

int main(){
    int arr[] = {3,5,1,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int numberofSwap = MinSwap(arr,size);
    cout<<"The minimum number of swap required to sort the array : "<<numberofSwap;

    return 0;
}