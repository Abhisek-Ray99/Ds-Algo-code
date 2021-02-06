// square root of an integer

#include<iostream>
using namespace std;

int findSQRT(int element){
    if(element == 0 || element == 1) return element;
    int start = 1;
    int end = element;
    int ans;
    while(start <= end){
        int mid = start+(end-start)/2;
        if(mid*mid == element) return mid;
        if(mid*mid < element){
            start = mid+1;
            ans = mid;
        }else end = mid-1;
    }
    return ans;
}

int main(){
    int element = 144;
    int sqrt_element = findSQRT(element);
    cout<<"The square root of "<<element<<" is : "<<sqrt_element;

    return 0;
}