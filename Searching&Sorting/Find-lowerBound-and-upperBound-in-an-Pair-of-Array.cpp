// Find lowerBound and upperBound in an pair of array

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void findLower_bound(vector<pair<int,int> > &arr,pair<int,int> &target){
    auto low = lower_bound(arr.begin(),arr.end(),target);
    cout<<"\nlower bound : "<<low-arr.begin();
}

void findUpper_bound(vector<pair<int,int> > &arr,pair<int,int> &target){
    auto high = upper_bound(arr.begin(),arr.end(),target);
    cout<<"\nupper bound : "<<high-arr.begin();
}

int main(){
    vector<pair<int,int> > arr = {{1,2},{3,4},{5,6},{7,8}};
    pair<int,int> target = {5,6};
    findLower_bound(arr,target);
    findUpper_bound(arr,target);

    return 0;
}