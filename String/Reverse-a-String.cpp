#include<iostream>
using namespace std;

void reverseString(string s){
    for(int i=s.length()-1; i>=0; i--){
        cout<<s[i];
    }
}

int main(){
    string s = "Abhisek Ray";
    reverseString(s);

    return 0;
}