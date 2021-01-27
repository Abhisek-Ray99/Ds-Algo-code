// 

// print longest palindrome in the string

#include<iostream>
using namespace std;

void PrintString(string s,int start,int end){
    for(int i=start; i<=end; i++){
        cout<<s[i];
    }
}

void longestPalindrome(string s){
    int low,high;
    int start=0, end=1;
    for(int i=1; i<s.length(); i++){
        //even part
        low = i-1;
        high = i;
        while(low>=0 && high<s.length() && s[low] == s[high]){
            if(high-low+1 > end){
                start = low;
                end = high-low+1;
            }
            low--;
            high++;
        }

        //odd part
        low = i-1;
        high = i+1;
        while(low>=0 && high<s.length() && s[low] == s[high]){
            if(high-low+1 > end){
                start = low;
                end = high-low+1;
            }
            low--;
            high++;
        }
    }
    PrintString(s,start,start+end-1);
}

int main(){
    string s = "Hellomadam";
    longestPalindrome(s);

    return 0;
}