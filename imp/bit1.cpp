#include<iostream>
using namespace std;

int countBits(int n){
    int count = 0;
    while(n){
        n &= (n-1);
        count++;
    }
    return count;
}

int main(){
    int n = 10;
    cout<<countBits(n);

    return 0;
}
