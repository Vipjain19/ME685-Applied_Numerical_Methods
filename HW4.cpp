/*
Name: Vipul Jain       Roll No. : 180869
*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

double norm(vector<double> u1,vector<double> u2,int n){
    double ans;
    for(int i=0;i<n;i++){
        ans += (u1[i]-u2[i])*(u1[i]-u2[i]);
    }
    return sqrt(ans);
}

int main(){
    int n=4;
    double maxError = 1e-6;  // epsilon
    // nxn non-singular matrix A
    vector<vector<double>> A={ { 4, 1, 1, 1 },
                            { 1, 4, 1, 1 },
                            { 1, 1, 4, 1 },
                            { 1, 1, 1, 4 } };
    
    vector<double> b = { 7, 7, 7, 7 };  // column vector b
    vector<double> u(n,0);              // column vector u for Au = b
    
    // Gauss‐Seidel Method
    while(1){
        vector<double> u2 = u;
        for(int i=0;i<n;i++){
            double r = b[i];
            for(int j=0;j<=i-1;j++){
                r -= A[i][j]*u[j];
            }
            for(int j=i;j<n;j++){
                r -= A[i][j]*u2[j];
            }
            double correction = r/A[i][i];
            u[i] = u2[i] + correction;
        }
        if(norm(u,u2,n) < maxError) break;
    }

    // final result
    
    for(int i=0;i<n;i++){
        cout<< "u"<< i+1 <<" : "<< u[i] << endl;
    }
}