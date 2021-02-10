// count the triplet

#include<iostream>
#include<algorithm>
using namespace std;

void countTriplet(int arr[],int size){
    int count = 0;
    sort(arr,arr+size);
    for(int start1=size-1; start1>1; start1--){
        int start2 = start1-1, start3 = 0;
        while(start3 < start2){
            if(arr[start3] + arr[start2] == arr[start1]){
                count++;
                start2--;
            }else if(arr[start3] + arr[start2] < arr[start1]){
                start3++;
            }else{
                start2--;
            }
        }
    }
    if(count == 0){
	    count = -1;
	}
    cout<<count;
}

int main(){
    int arr[] = {1,5,3,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"The number of triplet in the array is : ";
    countTriplet(arr,size);

    return 0;
}