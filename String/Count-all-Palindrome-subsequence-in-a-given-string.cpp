// count all palindromic subsequence in a given string


#include<iostream>
using namespace std;

int findsubstring(string A,int start,int end){
    if(start > end) return 0;
    if(start == end) return 1;
    if(A[start] == A[end]){
        return 1+findsubstring(A,start+1,end)+findsubstring(A,start,end-1);
    }else{
        return findsubstring(A,start+1,end)+findsubstring(A,start,end-1)-findsubstring(A,start+1,end-1);
    }
    return 0;
}

int main(){
    string A = "aba";
    int length = A.length();
    int count_palindrome = findsubstring(A,0,length-1);

    cout<<"The number of palindrome subsequence are : "<<count_palindrome;

    return 0;
}