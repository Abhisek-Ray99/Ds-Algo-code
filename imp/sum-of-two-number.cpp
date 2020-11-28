#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool solve(vector<int> &nums,int k){
    sort(nums.begin(),nums.end());
    int s = 0;
    int e = nums.size()-1;
    while(s<e){
        if(nums[s] + nums[e] == k){
            return true;
        }else if(nums[s] + nums[e] < k){
            s++;
        }else{
            e--;
        }
    }
    return false;
}

int main(){
    vector<int> nums = {35,8,18,3,22};
    int size = sizeof(nums)/sizeof(nums[0]);
    int k = 110;
    (solve(nums,k) == 0) ? cout<<"false" : cout<<"true"; 
    return 0;
}