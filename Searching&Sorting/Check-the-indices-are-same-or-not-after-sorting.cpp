// check the indices are same or not after sorting 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<int> &nums){
    vector<int> result;
    for(int start=0; start<nums.size(); start++){
        result.push_back(nums[start]);
    }
    sort(result.begin(),result.end());
    int count = 0;
    for(int start=0; start<result.size(); start++){
        if(nums[start] == result[start]) count++;
    }
    return count;
}

int main(){
    vector<int> nums = {1,7,3,4,10};
    int count = solve(nums);
    cout<<"The no. of correct indices are : "<<count;

    return 0;
}