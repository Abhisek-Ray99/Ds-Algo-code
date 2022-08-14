#####################  1

void findmissingNumbers(int arr[],int size){
    int diff = arr[0] - 0;
    for(int start=0; start<size; start++){
        if(arr[start]-start != diff){
            while(diff < arr[start]-start){
                cout<<start+diff<<" ";
                diff++;
            }
        }
    }
}

int main(){
    int arr[] = {1,2,5,6,8,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    findmissingNumbers(arr,size);
}

#####################  2

void findmissingNumbers(int arr[],int size){
    int count = 0;
    for(int start=arr[0]; start<arr[size-1]; start++){
        if(arr[count] == start) count++;
        else cout<<start<<" ";
    }
}

int main(){
    int arr[] = {1,2,5,6,8,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    findmissingNumbers(arr,size);
}
