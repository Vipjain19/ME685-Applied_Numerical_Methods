/*
Name: Vipul Jain       Roll No. : 180869
*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
    float h = 0.01;
    vector<float> x(201);
    vector<float> y(201);
    x[0]=-1; y[0]=-1;
    for(int i=1;i<201;i++){
        x[i]=x[i-1]+h;
    }
    for(int i=1;i<201;i++){
        y[i]=y[i-1]+h;
    }
    float M=0;float A=0;
    for(int i=0;i<201;i++){
        float My = 0;
        for(int j=0;j<201;j++){
            if(y[j] >= -sqrt(1-x[i]*x[i]) && y[j] <= sqrt(1-x[i]*x[i])){
                My += abs(x[i]+y[j])+1 + abs(x[i]+y[j+1])+1;
            }
        }
        My *= h/2;
        if(i==0 || i==200){
            M += My;
        }
        else M += 2*My;
    }
    M *= h/2;
    for(int i=0;i<201;i++){
        if(i==0 || i==200){
            A += sqrt(1-(x[i]*x[i]));
        }
        else{
            A += 2*(sqrt(1-(x[i]*x[i])));
        }
    }
    A *= (h/2)*2;
    double average_rho = M/A;
    float xcm = 0;
    float ycm = 0;
    for(int i=0;i<201;i++){
        float xy = 0; float yx = 0;
        for(int j=0;j<201;j++){
            if(y[j] >= -sqrt(1-x[i]*x[i]) && y[j+1] <= sqrt(1-x[i]*x[i])){
                xy += (abs(x[i]+y[j]) + abs(x[i]+y[j+1])+2)*x[i];
                yx += (abs(x[i]+y[j])+1)*y[j] + (abs(x[i]+y[j+1])+1)*y[j+1]; 
            }
        }
        xy *= h/2;
        yx *= h/2;
        if(i==0 || i==200){
            xcm += xy;
            ycm += yx;
        }
        else{
            xcm += 2*xy;
            ycm += 2*yx;
        }
    }
    xcm /= (2/h)*M;
    ycm /= (2/h)*M;
    cout<<"Mass : "<<M<<endl;
    cout<<"Area : "<<A<<endl;
    cout<<"Average Density : "<<average_rho<<endl;
    cout<<"Center of mass : "<<"( "<<xcm<<" , "<<ycm<<" )"<<endl;
}