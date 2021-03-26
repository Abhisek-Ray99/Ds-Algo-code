#include<iostream>
using namespace std;

int lcs(int i,int j,string s1,string s2){
    //base case
    if(i>=s1.size() || j>=s2.size()){
        return 0;
    }
    if(s1[i] == s2[j]){
        return 1+lcs(i+1,j+1,s1,s2);
    }else{
        int left = lcs(i+1,j,s1,s2);
        int right = lcs(i,j+1,s1,s2);
        return max(left,right);
    }
}

int main(){
    string s1,s2;
    cout<<"Enter 1st string : ";
    cin>>s1;
    cout<<"Enter 2nd string : ";
    cin>>s2;
    cout<<"The size of the LCS is : "<<lcs(0,0,s1,s2);

    return 0;
}