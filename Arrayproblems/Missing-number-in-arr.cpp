int findmissing(int arr[],int size){
    size = size+1;
    int total = size*(size+1)/2;
    for(int start=0; start<size; start++){
        total -= arr[start];
    }
    return total;
}

int main(){
    int arr[] = {1,2,3,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<findmissing(arr,size);
}
