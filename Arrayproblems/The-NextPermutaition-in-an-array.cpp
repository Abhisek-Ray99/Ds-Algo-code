#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void nextPermutation(vector<int> &arr){
    int n = arr.size(), k, l;
    for(k=n-2; k>=0; k--){
        if(arr[k] < arr[k+1]){
            break;
        }
    }
    if(k < 0){
        reverse(arr.begin(),arr.end());
    }else{
        for(l=n-1; l>k; l--){
            if(arr[l] > arr[k]){
                break;
            }
        }
        swap(arr[k],arr[l]);
        reverse(arr.begin()+k+1, arr.end());
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    cout<<"The inital arr is : ";
    for(int i=0; i<size-1; i++){
        cout<<arr[i]<<" ";
    }
    nextPermutation(arr);
    cout<<"\nThe next permutation is : ";
    for(int i=0; i<size-1; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}