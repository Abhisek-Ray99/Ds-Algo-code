#include<iostream>
#include<vector>
#include<map>
#define rep(i,n) for(i=0; i<n; i++)
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> a(n);
    int start;
    rep(start,n)
        cin>>a[start];
    
    map<int,int> freq;
    rep(start,n)
        freq[a[start]]++;

    map<int, int> ::iterator it;
    for(it=freq.begin(); it!= freq.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    return 0;
}