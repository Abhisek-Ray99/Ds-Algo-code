#include<iostream>
#include<unordered_map>
using namespace std;

int first_repeat(int arr[],int size){
    unordered_map<int,int> m;
    for(int start=0; start<size; start++){
        m[arr[start]]++;
    }
    for(int it=0; it<size; it++){
        auto temp = m.find(arr[it]);
        if(temp->second > 1){
            return temp->first;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,5,3,4,3,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int element = first_repeat(arr,size);
    cout<<"The first repeating element is : "<<element<<endl;

    return 0;
}
