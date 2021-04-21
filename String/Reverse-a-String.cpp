#include<iostream>
using namespace std;

void reverse_Str(string &S,int s,int e){
   while(s < e){
       swap(S[s],S[e]);
       s++;
       e--;
   }
}

void Print_Str(string S){
    for(int start=0; start<S.length(); start++){
        cout<<S[start]<<" ";
    }
}

int main(){
    string S = "Abhisek";
    cout<<"Before reversing the array : ";
    Print_Str(S);
    reverse_Str(S,0,S.length()-1);
    cout<<"\nAfter reversing the array : ";
    Print_Str(S);

    return 0;
}
