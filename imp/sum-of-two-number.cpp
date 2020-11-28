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




//OR//Print two number of sum(using only array)



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rec(int i, int j, int ele, int size, int arr[])
{
    int sum;
    for (i = 0; i < j;)
    {
        sum = arr[i] + arr[j];
        if (sum > ele)
        {
            j--;
        }
        else if (sum < ele)
        {
            i++;
        }
        else if (sum == ele)
        {
            cout<<"Value equal to sum of = "<<arr[i]<<" and "<<arr[j];
            return 1; //True
        }
    }
    return 0; //False
}
int main()
{
    int arr[] = {35,8,18,3,22};
    int size = sizeof(arr)/sizeof(arr[0]);
    int i, j, x;
    int ele = 25;
    //Sorting of arr
    sort(arr,size+arr);
    j = size - 1;
    rec(i, j, ele, size, arr);
    return 0;
}

