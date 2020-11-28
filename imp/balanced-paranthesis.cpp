#include <stack>
#include <string>
#include <iostream>

using namespace std;
int isBalanced(string s) {
    stack<char> st;  
    
    for (auto c: s) {
        switch (c) {
            case '(':
                st.push(c);
                break;
            case ')':
                if (st.empty() || (st.top() != '(')) {
                    return false;
                }
                st.pop();
                break;
        }
    }
    return st.empty() ? true : false;
}


int main(){
    string s = "(())";
    int result = isBalanced(s);
    (result == 1) ? cout<<"yes"
                  : cout<<"no";
    return 0;
}


//or//


//balanced / valid parentheses
#include<iostream>
#include<stack>
using namespace std;

bool isValid(string A){
    stack<char> s;
    for(int i=0; i<A.size(); i++){
        if(A[i]=='(' || A[i]=='{' || A[i]=='['){
            s.push(A[i]);
        }else{
            if(s.empty()) return false;
            else if(A[i]==')'){
                if(s.top() == '(') s.pop();
                else return false;
            }
            else if(A[i]=='}'){
                if(s.top() == '{') s.pop();
                else return false;
            }
            else if(A[i]==']'){
                if(s.top() == '[') s.pop();
                else return false;
            }
        }
    }
    if(s.empty()) return true;
    return false;
}

int main(){
    string s = "((()))";
    (isValid(s) == 1) ? cout<<"it's a balanced parentheses"
                      : cout<<"it's not a balanced parantheses";

    return 0;
}