/*
Name: Vipul Jain       Roll No. : 180869
*/
#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;

// function f(x) , Here , f(x) = x-tan(x)
double func(double x){
    return x-tan(x); 
}

// function f'(x) , Here , f'(x) = 1-sec2(x) 
double func2(double x){
    double y = 1-(1/(cos(x)*cos(x)));
    return y;
}

int main(){
    double x=4.3;
    double y1 = func(x);
    double maxError = 1e-6;

    // iterations for Newton Raphson method
    while(abs(y1)>= maxError){
        double y2 = func2(x);
        double deltax = -y1/y2;
        x += deltax;
        y1 = func(x);
    }
    cout<< x;
    return 0;
}