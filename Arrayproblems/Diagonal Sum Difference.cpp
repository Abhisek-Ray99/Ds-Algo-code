#include<bits/stdc++.h>
using namespace std;

int diagonalDifference(vector<vector<int>> arr) {
    int l_to_r = 0, r_to_l = 0;
    for(int s1=0; s1<arr.size(); s1++){
        for(int s2=0; s2<arr[s2].size(); s2++){
            if(s1 == s2) l_to_r += arr[s1][s2];
            if(s1 == arr.size()-s2-1) r_to_l += arr[s1][s2];
        }
    }
    int result = abs(l_to_r - r_to_l);
    return result;
}

int main(){
    vector<vector<int>> arr= {{1,2,3},{4,5,6},{9,8,9}};
    cout<<diagonalDifference(arr);

    return 0;
}
