// check whether a string is a valid shuffle of two strings or not


#include<iostream>
using namespace std;

void isShuffle(string res,string s1,string s2){
    int length_res = res.length();
    int length_s1 = s1.length();
    int length_s2 = s2.length();
    if(length_s1 + length_s2 != length_res) cout<<"no it is not a shuffle";
    else{
        int f = 0;
        int i=0,j=0,k=0;
        while(k < length_res){
            if(i<length_s1 && s1[i] == res[k]) i++;
            else if(j<length_s2 && s2[j] == res[k]) j++;
            else{
                f=1;
                break;
            }
            k++;
        }
        if(i<length_s1 || j<length_s2) cout<<"no it is not a shuffle";
        else cout<<"yes it is a shuffle";
    }
}

int main(){
    string res = "twostring";
    string s1 = "tsrng";
    string s2 = "woti";
    isShuffle(res,s1,s2);

    return 0;
}