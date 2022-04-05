/*
Name: Vipul Jain       Roll No. : 180869
*/
#include <iostream>
#include<vector>
using namespace std;

int main(){
    int n=4;
    // nxn non-singular matrix A
    vector<vector<float>> A={ { 4, 1, 1, 1 },
                            { 1, 4, 1, 1 },
                            { 1, 1, 4, 1 },
                            { 1, 1, 1, 4 } };
    
    vector<float> b = { 7, 7, 7, 7 };  // column vector b
    vector<float> x(n,0);              // column vector x for Ax = b
    
    // forward elimination

    for(int k=0;k<n-1;k++){
        for(int i=k+1;i<n;i++){
            float factor = A[i][k]/A[k][k];
            for(int j= k+1;j<n;j++){
                A[i][j] -= factor*A[k][j];
            }
            b[i] -= factor*b[k];
        }
    }

    // back sustitution

    x[n-1] = b[n-1]/A[n-1][n-1];

    for(int i = n-2;i>=0;i--){
        float sum = b[i];
        for(int j= i+1;j<n;j++){
            sum -= A[i][j]*x[j];
        }
        x[i] = sum/A[i][i];
    }

    // final result
    
    for(int i=0;i<n;i++){
        cout<< "x"<< i+1 <<" : "<< x[i] << endl;
    }
}