#include<iostream>
#include<unordered_map>
using namespace std;

int getPairs(int arr[],int n,int sum){
    unordered_map<int,int> m;
    int count = 0;
    for(int i=0; i<n; i++){
        int x = sum - arr[i];
        if(arr[x] == 0){
            m[arr[i]]++;
        }else{
            count += m[x];
            m[arr[i]]++;
        }
    }
    return count;
}

int main(){
    int arr[] = {1,5,7,-1,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum = 6;
    int result = getPairs(arr,size,sum);
    cout<<"Numbers of pairs are : "<<result;

    return 0;
}