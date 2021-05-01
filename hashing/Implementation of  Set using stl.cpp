#include<iostream>
#include<unordered_set>
using namespace std;


int main(){
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(4);
    for(auto it = s.begin(); it != s.end(); it++){
        cout<<*it<<" ";
    }
    cout<<"\n"<<s.size()<<endl;
    int key = 4;
    if(s.find(key) == s.end()){
        cout<<"\nkey not found";
    }else{
        auto temp = s.find(key);
        s.erase(key);
    }
    cout<<s.size();
     
    if(s.count(key)){
        cout<<"\nPresent";
    }else{
        cout<<"\nNot present";
    }

    return 0;
}
