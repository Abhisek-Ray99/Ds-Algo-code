#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int i,int j){
    return __builtin_popcount(i) < __builtin_popcount(j);
}

void sort_Arr(vector<int> &n){
    sort(n.begin(), n.end(),cmp);
    for(auto x: n){
        cout<<x<<" ";
    }
}

int main(){
    vector<int> n = {1,2,3,4,5,6,7,8,9,10,11};
    sort_Arr(n);

    return 0;
}
