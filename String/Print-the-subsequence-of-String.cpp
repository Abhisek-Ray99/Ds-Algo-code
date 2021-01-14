#include<iostream>
using namespace std;

void PrintSubsequence(string input,string output){
    if(input.length() == 0){
        cout<<output<<endl;
        return;
    }
    PrintSubsequence(input.substr(1),output);
    PrintSubsequence(input.substr(1),output+input[0]);
}

int main(){
    string input;
    cout<<"Enter the string : ";
    cin>>input;

    string output = "";
    PrintSubsequence(input,output);

    return 0;
}