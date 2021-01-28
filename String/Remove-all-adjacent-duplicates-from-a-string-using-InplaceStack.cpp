// remove all adjacent duplicates from a string using inplace stack


#include<iostream>
using namespace std;

string PrintString(string s){
    int start = -1;
    for(int i=0; i<s.size(); i++){
        if(start == -1 || s[i] != s[start]){
            start++;
            s[start] = s[i];
        }else{
            start--;
        }
    }
    string ans = "";
    for(int i=0; i<=start; i++){
        ans.push_back(s[i]);
    }
    return ans;
}

int main(){
    string s = "mississippi";
    string result = PrintString(s);
    cout<<"The final string is : "<<result;
}