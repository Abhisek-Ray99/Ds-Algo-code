#include<iostream>
using namespace std;

int countBits(int n){
    int count = 0;
    while(n){
        count += n&1;
        n >>= 1;
    }
    return count;
}

int main(){
    int n = 10;
    cout<<countBits(n);

    return 0;
}
