#include<iostream>
#include<vector>
using namespace std;

vector<int> rotateArr(vector<int> arr,int ele){
    while(ele--){
        int temp = arr[0];
        for(int i=1; i<arr.size(); i++){
            arr[i-1] = arr[i];
        }
        arr[arr.size()-1] = temp;
    }
    return arr;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    int ele = 3;
    arr = rotateArr(arr,ele);
    for(int s=0; s<arr.size(); s++){
        cout<<arr[s]<<" ";
    }

    return 0;
}
