//find whether an array is a subset of another array

#include<iostream>
#include<unordered_map>
using namespace std;

void isSubset(int arr1[],int arr2[],int size1,int size2){
    unordered_map<int,int> m;
    for(int i=0; i<size1; i++){
        m[arr1[i]]++;
    }
    int c = 0;
    for(int i=0; i<size2; i++){
        if(m[arr2[i]]){
            c++;
        }
    }
    if(c != size2) cout<<"arr2 not a subset of arr1";
    else cout<<"arr2 is a subset of arr1";
}

int main(){
    int arr1[] = {1,2,3,4,5,6,8,10};
    int arr2[] = {2,6,8};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);

    isSubset(arr1,arr2,size1,size2);

    return 0;
}