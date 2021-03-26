#include<iostream>
using namespace std;

void LCS(string str1,string str2){
    int m, n;
    string store;
    m = str1.length();
    n = str2.length();
    int matrix[m + 1][n + 1];
    int i;
    for (i = 0; i <= m; i++)
    {
        matrix[i][0] = 0;
    }
    for (i = 0; i <= n; i++)
    {
        matrix[0][i] = 0;
    }
    for (i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                matrix[i][j] = 1 + matrix[i - 1][j - 1];
            }
            else
            {
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    }
    for (i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << " " << endl;
    }
    for (i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (matrix[i][j] - matrix[i - 1][j - 1] == 1 && matrix[i][j] != matrix[i - 1][j] && matrix[i][j] != matrix[i][j - 1])
            {
                store = store + str1[i - 1];
            }
        }
    }
    cout << store;
}

int main(){
    string str1,str2;
    cout<<"Enter 1st string : ";
    cin>>str1;
    cout<<"Enter 2nd string : ";
    cin>>str2;
    LCS(str1,str2);

    return 0;
}