// Minimum Platform

#include<iostream>
#include<algorithm>
using namespace std;

int findMaxPlatform(int arrive[],int depart[],int size){
    sort(arrive,arrive+size);
    sort(depart,depart+size);
    int maxPlatform = 1;
    int platform = 1;
    int start = 1, end = 0;
    while(start < size && end < size){
        if(arrive[start] <= depart[end]){
            platform++;
            start++;
        }else if(arrive[start] > depart[end]){
            platform--;
            end++;
        }
        if(platform > maxPlatform){
            maxPlatform = platform;
        }
    }
    return maxPlatform;
}

int main(){
    int arrive[] = {900,940,950,1100,1120,1500,1800};
    int depart[] = {910,1200,1120,1130,1130,1900,2000};
    int size = sizeof(arrive)/sizeof(arrive[0]);
    int platform = findMaxPlatform(arrive,depart,size);
    cout<<"Maximum platform needed is : "<<platform;

    return 0;
}