#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<pair<int,int> > findSubArr(int arr[],int size){
    //create an empty map
    unordered_map<int, vector<int> > _subarr;
    //create an empty vector of pairs to store subarray starting and ending index
    vector<pair<int,int> > _storeArr;
    int sum = 0;
    for(int i=0; i<size; i++){
        sum += arr[i];
        if(sum == 0){
            _storeArr.push_back(make_pair(0,i));
        }
        if(_subarr.find(sum) != _subarr.end()){
            vector<int> v = _subarr[sum];
            for(auto it=v.begin(); it!=v.end(); it++){
                _storeArr.push_back(make_pair(*it+1,i));
            }
        }
        _subarr[sum].push_back(i);
    }
    return _storeArr;
}

void PrintSubArr(vector<pair<int,int> > _storeArr){
    for(auto it=_storeArr.begin(); it != _storeArr.end(); it++){
        cout<<"Sub-Array found from index "<<it->first<<" to "<<it->second<<endl;
    }
}

int main(){
    int arr[] = {3,-3,1,-1,5,-4,-1};
    int size = sizeof(arr)/sizeof(arr[0]);

    vector<pair<int,int> > result = findSubArr(arr,size);
    if(result.size() == 0){
        cout<<"There is no sub array which sum is Zero";
    }
    else{
        PrintSubArr(result);
    }

    return 0;
}