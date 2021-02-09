// Fizzbuzz using vector
#include<iostream>
#include<vector>
using namespace std;

vector<string> solve(int n) {
    vector<string> result;
    for(int i=1; i<=n; i++){
        if(i % 3 == 0 && i % 5 == 0) result.push_back("Fizzbuzz");
        else if(i % 3 == 0) result.push_back("Fizz");
        else if(i % 5 == 0) result.push_back("Buzz");
        else result.push_back(to_string(i));
    }
    return result;
}

int main(){
    int n = 15;
    vector<string> res = solve(n);
    for(auto x:res){
        cout<<x<<", ";
    }
}