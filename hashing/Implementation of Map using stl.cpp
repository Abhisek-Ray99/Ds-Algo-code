#include<iostream>
#include<unordered_map>
using namespace std;


int main(){
    unordered_map<string,int> m;
    m["AB"] = 23;
    m["CD"] = 34;
    m["EF"] = 56;
    m["GH"] = 75;

    for(auto x: m){
        cout<<x.first<<" "<<x.second<<endl;
    }
    cout<<endl;
    for(auto it=m.begin(); it != m.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<m.size()<<endl;

    string key = "CD";
    if(m.find(key) != m.end()){
        cout<<"\nKEY FOUND\n";
        auto k = m.find(key);
        cout<<k->first<<" : "<<k->second<<endl;
        m.erase(key);
    }else{
        cout<<"\nKEY NOT FOUND\n";
    }
    cout<<m.size()<<endl;

    m.insert(make_pair("SDSFDS",1200));
    for(auto it=m.begin(); it != m.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<m.size()<<endl;

    unordered_map<int,int> u;
    int arr[] = {1,2,3,1,2,3,2,1,3,1,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int start=0; start<size; start++){
        int key = arr[start];
        u[key]++;
    }
    for(auto it=u.begin(); it != u.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<u.size()<<endl;

    
    return 0;
}
