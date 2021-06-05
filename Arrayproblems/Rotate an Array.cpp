//Brute force approch


//rotate an array from left to right(anti clock wise)
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



//rotate an array from right to left(clock wise)
#include<iostream>
#include<vector>
using namespace std;

vector<int> rotatenums(vector<int> nums,int k){
    while(k--){
        int temp = nums[nums.size()-1];
        for(int i=nums.size()-2; i >= 0; i--){
            nums[i+1] = nums[i];
        }
        nums[0] = temp;
    }
    return nums;
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    nums = rotatenums(nums,k);
    for(int s=0; s<nums.size(); s++){
        cout<<nums[s]<<" ";
    }

    return 0;
}






// Optimised solution o(n) and o(1)  //left to right(clock wise)
#include<iostream>
using namespace std;

void reverse(int arr[],int s,int e){
    while(s < e){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
}

void rotate_arr(int arr[],int d,int n){
    if(d > n) d = d % n;
    reverse(arr, 0, n-(n-d)-1);
    reverse(arr, n-(n-d), n-1);
    reverse(arr, 0, n-1);
}

int main(){
    int arr[] = {2,4,6,8,10,12,14,16,18,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 3;
    rotate_arr(arr,d,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
