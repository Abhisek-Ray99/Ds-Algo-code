// print all permutation of a string

#include<iostream>
#include<set>
using namespace std;

void printPermutation(char a[],int start,set<string> &s){
    if(a[start] == '\0'){
        string t(a);
        s.insert(t);
        return;
    }
    for(int j=start; a[j] != '\0'; j++){
        swap(a[start],a[j]);
        printPermutation(a,start+1,s);
        swap(a[start],a[j]);
    }
}

int main(){
    char a[100];
    cout<<"Enter the string : ";
    cin>>a;
    set<string> s;
    printPermutation(a,0,s);
    for(auto x:s) {
        cout<<x<<" ";
    }

    return 0;
}