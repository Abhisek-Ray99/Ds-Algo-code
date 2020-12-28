#include<iostream>
using namespace std;

class twoStack{
    int *arr;
    int nextIndex1;
    int nextIndex2;
    int size;
    public:
        twoStack(int cap){
            size = cap;
            arr = new int[cap];
            nextIndex1 = -1;
            nextIndex2 = size;
        }
        void push1(int data){
            if(nextIndex2 == nextIndex1+1){
                cout<<"Stack Overflow"<<endl;
            }else{
                nextIndex1++;
                arr[nextIndex1] = data;
            }
        }
        void push2(int data){
            if(nextIndex2 == nextIndex1+1){
                cout<<"Stack Overflow"<<endl;
            }else{
                nextIndex2--;
                arr[nextIndex2] = data;
            }
        }
        int pop1(){
            if(nextIndex1 <= 0){
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            int val = arr[nextIndex1];
            nextIndex1--;
            return val;
        }
        int pop2(){
            if(nextIndex2 > size){
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            int val = arr[nextIndex2];
            nextIndex2++;
            return val;
        }
        int top1(){
            if(nextIndex1 <= 0){
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            return arr[nextIndex1];
        }
        int top2(){
            if(nextIndex2 > size){
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            return arr[nextIndex2];
        }
};

int main(){
    twoStack s(5);
    s.push1(2);
    s.push2(4);
    s.push2(6);
    s.push1(8);
    s.push2(10);
    
    cout<<s.top1()<<endl;
    cout<<s.top2()<<endl;
    cout << "Popped element from stack1 is "
         << s.pop1()<<endl; 
    s.push2(12);
    s.push2(14); 
    s.push1(16); 
    cout << "Popped element from stack2 is "
         << s.pop2(); 
    

    return 0;
}