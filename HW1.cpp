/*
Name: Vipul Jain       Roll No. : 180869
*/
#include <iostream>
#include<vector>
using namespace std;

vector<vector<int>> Multiply (vector<vector<int>> A, vector<vector<int>> B, int m,int n,int p){
    vector<vector<int>> C(m,vector<int> (p,0));
    for(int i=0; i<m ; i++){
        for(int j=0;j<p;j++){
            for(int k=0;k<n;k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    } 
    return C;
}

void Print(vector<vector<int>> C,int m,int p){
    for(int i=0; i<m ; i++){
        for(int j=0;j<p;j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    } 
    return;
}

int main(){
    int m=3;
    int n=3;
    int p=3;
    vector<vector<int>> A={ { 2, -2, -4 },
                            { -1, 3, 4 },
                            { 1, -2, -3 } };
    vector<vector<int>> A_2 = Multiply(A,A,m,n,p);
    Print(A_2,m,p);
    vector<vector<int>> A_3 = Multiply(A_2,A,m,n,p);
    Print(A_3,m,p);
    vector<vector<int>> A_4 = Multiply(A_3,A,m,n,p);
    Print(A_4,m,p);
    return 0;
}