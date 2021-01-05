#include<iostream>
using namespace std;

bool isRotation(string s_1,string s_2){
    if(s_1.length() != s_2.length()){
        return false;
    }
    string temp = s_1+s_2;
    return (temp.find(s_2) != string::npos);
}

int main(){
    string s_1 = "ABACD";
    string s_2 = "CDABA";
    (isRotation(s_1,s_2) == 1) ? cout<<"is a rotation of string 2" : cout<<"not a rotation of string 2";

    return 0;
}