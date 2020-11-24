//selection sort
#include<iostream>
using namespace std;

void selection_sort(int arr[], int size){
    for(int s=0; s<size; s++){
        int min = s;
        for(int e=s+1; e<size; e++){
            if(arr[e] < arr[min]){
                min = e;
            }
        }
        swap(arr[s],arr[min]);
    }
}

int main(){
    int arr[] = {10,2,4,1,3,8,5,20};
    int size = sizeof(arr)/sizeof(arr[0]);

    selection_sort(arr,size);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}