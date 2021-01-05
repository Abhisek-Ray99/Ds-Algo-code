#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int> &nums){
    int slow = nums[0];
    int fast = nums[0];
    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while(slow != fast);

    fast = nums[0];
    while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main(){
    vector<int> arr = {1,2,3,4,5,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);

    int result = findDuplicate(arr);
    cout<<"The duplicate no. is : "<<result;

    return 0;
}