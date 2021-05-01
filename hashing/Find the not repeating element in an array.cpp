#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
    cout<<"Enter the number of elements : ";
    int no_ele;
    cin>>no_ele;
    vector<int> v(no_ele);
    for(int start=0 ;start<no_ele; start++){
        cin>>v[start];
    }

    unordered_map<int,int> m;
    for(int s=0; s<no_ele; s++){
        m[v[s]]++;
    }
    cout<<"\nThe Key and value pair is : "<<endl;
    for(auto s=m.begin(); s!=m.end(); s++){
        cout<<s->first<<" "<<s->second<<endl;
    }
    for(auto s=m.begin(); s!=m.end(); s++){
        if(s->second == 1){
            cout<<s->first<<" ";
        }else{
            cout<<"0";
        }
    }


    return 0;
}
