#include<iostream>
#include<vector>
#include<set>
using namespace std;

int longestConsecutive(vector<int> &arr){
    set<int> s;
    for(int it : arr){
        s.insert(it);
    }
    int count = 0;
    for(int num : arr){
        if(!s.count(num-1)){
            int currentNum = num;
            int currentCount = 1;
            while(s.count(currentNum+1)){
                currentNum += 1;
                currentCount += 1;
            }
            count = max(count,currentCount);
        }
    }
    return count;
}

int main(){
    vector<int> arr = {1,9,3,10,4,20,5,2};

    int result = longestConsecutive(arr);
    cout<<"The No. of longest consecutive subsequence is : "<<result;

    return 0;
}