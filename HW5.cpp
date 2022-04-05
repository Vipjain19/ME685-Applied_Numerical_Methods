/*
Name: Vipul Jain       Roll No. : 180869
*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define Maxerror 1e-5

float norm(vector<float> u,int n){
    float ans;
    for(int i=0;i<n;i++){
        ans += u[i]*u[i];
    }
    return sqrt(ans);
}

float dot_product(vector<float> u,vector<float> v,int n){
    float ans;
    for(int i=0;i<n;i++){
        ans += u[i]*v[i];
    }
    return (ans);
}

vector<float>  gaussian(vector<vector<float>> A, vector<float> u,int m,int n,int p){
    vector<float> v2(m,0);
    for(int k=0;k<n-1;k++){
        float mx = A[k][k];
        int mxi = k;
        for(int i=k+1;i<n;i++){
            if(A[k][i]>mx){
                mxi = i;
                mx = A[k][i];
            }
        }
        if(mxi != k){
            for(int i=0;i<3;i++){
                float temp = A[i][mxi];
                A[i][mxi] = A[i][k];
                A[i][k] = temp;
            }
        }
        for(int i=k+1;i<n;i++){
            float factor = A[i][k]/A[k][k];
            for(int j= k+1;j<n;j++){
                A[i][j] -= factor*A[k][j];
            }
            u[i] -= factor*u[k];
        }
    }

    v2[n-1] = u[n-1]/A[n-1][n-1];

    for(int i = n-2;i>=0;i--){
        float sum = u[i];
        for(int j= i+1;j<n;j++){
            sum -= A[i][j]*v2[j];
        }
        v2[i] = sum/A[i][i];
    }
    return v2;
}
vector<float> Multiply (vector<vector<float>> A, vector<float> B, int m,int n,int p){
    vector<float> C(m,0);
    for(int i=0; i<m ; i++){
        for(int j=0;j<p;j++){
            for(int k=0;k<n;k++){
                C[i] += A[i][k] * B[k];
            }
        }
    } 
    return C;
}

int main(){
    int n=3;
    float lambda_max = 100;
    float lambda_min = 100;
    vector<vector<float> > L ={ { 0, 2.3, 0.4 },
                                { 0.6, 0, 0 },
                                { 0, 0.3, 0 } };
    vector<float> v1 = {1,0,0};
    vector<float> v2 = {1,0,0};
    float error = 10;

    // Power iteration
    while (error > Maxerror){
        vector<float> u = Multiply(L,v1,3,3,1);
        float norm_Lu = norm(u,3);
        for(int i=0;i<3;i++){
            u[i] /= norm_Lu;
        }
        float lambda = dot_product(Multiply(L,u,3,3,1),u,3)/dot_product(u,u,3);
        error = abs(lambda - lambda_max);
        v1 = u;
        lambda_max = lambda;
    }     

    error = 10;

    vector<vector<float> > A = L;
    
    //inverse power iteration
    while (error > Maxerror){
        vector<float> u = gaussian(A,v2,3,3,1);
        float norm_Lu = norm(u,3);
        for(int i=0;i<3;i++){
            u[i] /= norm_Lu;
        }
        vector<float> u2 = gaussian(A,u,3,3,1);
        float lambda = dot_product(u2,u,3)/dot_product(u,u,3);
        error = abs(lambda - lambda_min);
        lambda_min = lambda;
        v2= u;
    }     
    cout<<"lambda_max : " << lambda_max << endl;
    cout<< "lambda_min : " << 1/lambda_min;
    return 0;
}