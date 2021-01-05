#include<iostream>
using namespace std;

bool isPalindrome(string s){
    int l=0; 
    int h= s.length()-1;
    while(h>l){
        if(s[l++] != s[h--]){
            return false;
        }
    }
    return true;
}

int main(){
    string s = "madam";
    (isPalindrome(s) == 1) ? cout<<"Palindrome"
                           : cout<<"Not a Palindrome";

    return 0;
}