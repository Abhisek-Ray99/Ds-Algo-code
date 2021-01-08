#include<iostream>
#include<algorithm>
using namespace std;

int findMinDiff(int packets[],int size,int student){
    if(size == 0 || student == 0){
        return 0;
    }
    sort(packets,packets+size);
    if(size < student){
        return -1;
    }
    int min_diff = INT_MAX;
    for(int i=0; i+student-1<size; i++){
        int diff = packets[i+student-1] - packets[i];
        if(diff < min_diff){
            min_diff = diff;
        }
    }
    return min_diff;

}

int main(){
    int packets[] = {3,4,1,9,56,7,9,12};
    int size = sizeof(packets)/sizeof(packets[0]);
    int student = 5;
    int min_diff = findMinDiff(packets,size,student);
    cout<<"The minimun Difference is : "<<min_diff;

    return 0;
}