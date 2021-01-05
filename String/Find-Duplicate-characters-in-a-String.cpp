#include<iostream>
#include<map>
using namespace std;

void find_duplicate(string s){
    map<char,int> m;
    for(int i=0; i<s.length(); i++){
        m[s[i]]++;
    }
    for(auto it:m){
        if(it.second > 1){
            cout<<it.first<<" "<<"count : "<<it.second<<endl;
        }
    }

}

int main(){
    string s = "unnecessary";
    find_duplicate(s);

    return 0;
}