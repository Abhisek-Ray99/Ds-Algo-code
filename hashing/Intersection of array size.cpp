#include<iostream>
#include<unordered_map>
using namespace std;

int union_of_arr(int arr1[],int arr2[],int size1,int size2){
    unordered_map<int,int> m;
    for(int start1=0; start1<size1; start1++){
        m[arr1[start1]]++;
    }
    for(int start2=0; start2<size2; start2++){
        m[arr2[start2]]++;
    }
    int count;
    for(auto it=m.begin(); it!=m.end(); it++){
        if(it->second > 1){
            count++;
        }
    }
    return count;
}

int main(){
    int arr1[] = {89,24,75,11,23};
    int arr2[] = {89,2,4};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    int count = union_of_arr(arr1,arr2,size1,size2);
    cout<<"The intersection of array size is : "<<count<<endl;

    return 0;
}
