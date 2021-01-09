//triplate
#include<iostream>
#include<algorithm>
using namespace std;

int findTriplate(int arr[],int size,int sum){
    sort(arr,arr+size);
    int ans = 0;
    for(int i=0; i<size-2;i++){
        int l=i+1;
        int r=size-1;
        while(l<r){
            if(arr[i]+arr[l]+arr[r] == sum){
                ans = 1;
                break;
            }else if(arr[i]+arr[l]+arr[r] < sum){
                l++;
            }else{
                r--;
            }
        }
        if(ans == 1){
            break;
        }
    }
    return ans;
}

int main(){
    int arr[] = {12,3,4,1,6,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum = 94;

    (findTriplate(arr,size,sum) == 1) ? cout<<"found"
                                      : cout<<"not found";

    return 0;
}