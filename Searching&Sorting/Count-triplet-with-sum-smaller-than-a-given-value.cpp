// Count triplet with sum smaller than a given value

#include<iostream>
#include<algorithm>
using namespace std;

int countTriplet(int arr[],int size,int sum){
    int count = 0;
    for(int start1=0; start1<size; start1++){
        for(int start2=start1+1; start2<size; start2++){
            for(int start3=start2+1; start3<size; start3++){
                if(arr[start1]+arr[start2]+arr[start3] < sum) count++;
            }
        }
    }
    return count;
}

int main(){
    int arr[] = {-2,0,1,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum = 2;
    int tripletCount = countTriplet(arr,size,sum);
    cout<<tripletCount;

    return 0;
}