// split the binary string into substrings with equal number of 0s and 1s

#include<iostream>
using namespace std;

int subStrings(string s,int s_size){
    int count_0 = 0;
    int count_1 = 0;
    int final_count = 0;
    for(int i=0; i<s_size; i++){
        if(s[i] == '0') count_0++;
        else count_1++;
        if(count_0 == count_1) final_count++;
    }
    if(count_0 != count_1) return -1;
    return final_count;
}

int main(){
    string s = "1110001001";
    int s_size = s.length();

    int maxSubstrings = subStrings(s,s_size);
    cout<<"The no of binary substrings is : "<<maxSubstrings;

    return 0;
}