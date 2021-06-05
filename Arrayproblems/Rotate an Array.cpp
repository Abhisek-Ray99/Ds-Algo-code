//Brute force approch


//rotate an array from left to right(anit clock wise)
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
