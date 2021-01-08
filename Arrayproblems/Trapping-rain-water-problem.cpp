#include<iostream>
#include<vector>
using namespace std;

int trop(vector<int> &height){
    int size = height.size();
    int left = 0,right = size-1;
    int result = 0;
    int max_left = 0, max_right = 0;
    while(left <= right){
        if(height[left] <= height[right]){
            if(height[left] >= max_left){
                max_left = height[left];
            }else{
                result += max_left - height[left]; 
            }
            left++;
        }else{
            if(height[right] >= max_right){
                max_right = height[right];
            }else{
                result += max_right - height[right];
            }
            right--;
        }
    }
    return result;
}

int main(){
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result = trop(height);
    cout<<"Maximum water that can be accumulated is : "<<result;

    return 0;
}