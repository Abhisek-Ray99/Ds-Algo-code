//zigzag conversion
#include<iostream>
using namespace std;

string zigzag(string s, int nRows){
    if(nRows <= 1) return s;
    int n = s.size();
    string *A = new string[nRows];
    int row = 0;
    int step = 1;
    for(int i=0; i<n; i++){
        A[row].push_back(s[i]);
        
        if(row == 0) step = 1; //row++
        else if(row == nRows-1) step = -1; 
        row = row + step;
    }
    s = "";
    for(int i=0; i<nRows; i++){
        s = s + A[i];
    }
    return s;
}

int main(){
    string s = "PAYPAl";
    cout<<zigzag(s, 3);

    return 0;
}