/*
Name: Vipul Jain       Roll No. : 180869
*/
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <vector>
using namespace std;

#define PI  asin(1)*2

double L(double a,int i,vector<double> x){
    double ans = 1;
    for(int j=0;j<8;j++){
        if (j != i) ans *= (a-x[j])/(x[i]-x[j]);
    }
    return ans;
}


int main(){
    vector<double> x(8);
    vector<double> P(8);
    vector<double> y(8);
    x[0]=0;
    for(int i=1;i<8;i++){
        x[i] = x[i-1] + 2*PI/7;
    }
    for(int i=0;i<8;i++){
        y[i] = sin(x[i])*sin(x[i]);
    }
    for(int i=0;i<8;i++){
        P[i]=0;
        for(int j=0;j<8;j++){
            P[i] += L(x[i],j,x)*y[j];
        }
    }
    vector<double> x2(100);
    vector<double> P2(100);
    vector<double> y2(100);
    x2[0]=0;
    for(int i=1;i<100;i++){
        x2[i] = x2[i-1] + 2*PI/99;
    }
    for(int i=0;i<100;i++){
        P2[i]=0;
        for(int j=0;j<8;j++){
            P2[i] += L(x2[i],j,x)*y[j];
        }
    }

    for(int i=0;i<100;i++){
        y2[i] = sin(x2[i])*sin(x2[i]);
    }

    double mean=0;
    double max = abs(y2[0]-P2[0]);
    for(int i=0;i<100;i++){
        mean += abs(y2[i]-P2[i]);
        if(abs(y2[i]-P2[i]) > max) max = abs(y2[i]-P2[i]);
    }
    mean /= 100;
    cout<<max<<endl;
    cout<< mean << endl;
    // for printing datapoints
    /*for(int i=0;i<100;i++){
        cout<< x2[i] <<" " << y2[i] << " "<< P2[i] << endl;
    }*/
}