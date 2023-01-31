#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
double f(double a,double b,double x){
    return (a+b*x);
}
int main()
{
    double n;
    cout<<"Enter the number of data present in dataset = ";
    cin>>n;
    double* X = (double*)calloc(sizeof(double),n);
    double* Y = (double*)calloc(sizeof(double),n);
    cout<<"\tEnter the data along X-axis:\n";
    for(int i=0;i<n;i++)
    cin>>X[i];
    cout<<"\tEnter the data along Y-axis:\n";
    for(int i=0;i<n;i++)
    cin>>Y[i];

    double sumX = 0;
    double sumY = 0;
    double sumXY = 0;
    double sumXX = 0;

    for(int i=0;i<n;i++){
        sumX += X[i];
        sumY += Y[i];
        sumXX += X[i]*X[i];
        sumXY += X[i]*Y[i];
    }
    cout<<"sumX = "<<sumX<<endl;
    cout<<"sumY = "<<sumY<<endl;
    cout<<"sumXY = "<<sumXY<<endl;
    cout<<"sumXX = "<<sumXX<<endl;
    

    double b = (n*sumXY-(sumX)*(sumY))/(n*sumXX-(sumX*sumX));
    double a = (sumY-b*sumX)/n;

    cout<<"The Slope = "<<b<<endl;
    cout<<"The Intercept Point = "<<a<<endl;

    double* newY = (double*)calloc(sizeof(double),n);

    for(int i=0;i<n;i++)
      newY[i] = f(a,b,X[i]);
    cout<<"New Y-Data: \n";
    for(int i=0;i<n;i++)
    cout<<newY[i]<<"\t";
    cout<<endl;
    return 0;
}
/*
6 2 10 4 8
9 11 5 8 7
New Y-Data: 
8  10.6  5.4  9.3   6.7
*/
