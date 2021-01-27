//print all subsequence of string

#include<iostream>
using namespace std;

void helper(string s,int s_size,int start = -1,string curr = ""){
    if(start == s_size) return;
    if(!curr.empty()) cout<<curr<<", ";
    for(int i=start+1; i<s_size; i++){
        curr += s[i];
        helper(s,s_size,i,curr);
        //backtracking
        curr = curr.erase(curr.size() - 1);
    }
    return;
}

void Printsubsequence(string s){
    helper(s,s.length());
}

int main(){
    string s = "abc";
    cout<<"The subsequence of string are : ";
    Printsubsequence(s); 

    return 0;
}