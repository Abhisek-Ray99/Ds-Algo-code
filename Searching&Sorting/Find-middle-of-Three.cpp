// Find middle of three 

#include<iostream>
using namespace std;

int findMiddleElement(int num1,int num2,int num3){
    if(num1 > num2){
        if(num2 > num3) return num2;
        else if(num1 > num3) return num3;
        else return num1;
    }else{
        if(num1 > num3) return num1;
        else if(num2 > num3) return num3;
        else return num2;
    }
}

int main(){
    int num1 = 30, num2 = 12, num3 = 20;
    int middleElement = findMiddleElement(num1,num2,num3);
    cout<<"The middle element is : "<<middleElement;

    return 0;
}