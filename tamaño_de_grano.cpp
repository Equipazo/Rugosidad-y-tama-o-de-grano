#include <QCoreApplication>
#include<iostream>
#include <math.h>
#include<stdio.h>

using namespace std;

int main()
{

float n, N, granos,largo, ancho;

cin>>granos;
cin>>ancho;
cin>>largo;

N= granos/((largo*ancho)/(25.4*25.4));

n=(log(N)/log(2))+ 1;

cout<<n;

}
