//remove all adjacent duplicates from the string using stack

#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

string removeDuplicates(string A){
    stack<char> s;
    for(int i=0; i<A.size(); i++){
        if(s.empty() || A[i] != s.top()){
            s.push(A[i]);
        }else{
            s.pop();
        }
    }
    string ans = "";
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string A = "mississippi";
    cout<<removeDuplicates(A);

    return 0;
}