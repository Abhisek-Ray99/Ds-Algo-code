#include<bits/stdc++.h>
using namespace std;

void printnto1(int n){
    if(n == 0) return;
    cout<<n<<" ";
    printnto1(n-1);
}

void print1ton(int n){
    if(n == 0){
        return;
    }
    print1ton(n-1);
    cout<<n<<" "; 
}

int main(){
    int n = 7;
    print1ton(n);
    cout<<endl;
    printnto1(n);

    return 0;
}
