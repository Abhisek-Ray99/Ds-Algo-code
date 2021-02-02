// Replace elements with greatest element on right side 
//tag : Array

#include<iostream>
#include<vector>
using namespace std;

vector<int> replacements(vector<int> &arr){
    int max = -1;
    int size = arr.size();
    vector<int> ans(size);
    ans[size-1] = -1;
    int counter = size-2;
    for(int start=size-1; start>=0; start--){
        if(arr[start] > max) max = arr[start];
        if(counter >= 0) ans[counter] = max;
        counter--;
    }
    return ans;
}

void Printarr(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<",";
    }
}

int main(){
    vector<int> arr = {20,3,12,2,10,1,4};
    arr = replacements(arr);
    Printarr(arr);

    return 0;
}