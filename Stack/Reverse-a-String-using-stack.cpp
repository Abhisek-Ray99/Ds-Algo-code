#include<iostream>
#include<stack>
using namespace std;

void revereString(string A){
    stack<char> s;
    for(int i=0; i<A.size(); i++){
        s.push(A[i]);
    }
    // --- OR --- //
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    // --- /OR --- //

    // --- OR --- //
    for(int j=0; j<A.size(); j++){
        A[j] = s.top();
        s.pop();
    }
    for(int i=0; i<A.size(); i++){
        cout<<A[i];
    }
    // --- /OR --- //
}

int main(){
    string A = "Abhisek";
    cout<<"The initial expression is : "<<A<<endl;
    cout<<"The final expression is : ";
    revereString(A);

    return 0;
}