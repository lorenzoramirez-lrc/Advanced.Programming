#include <iostream>

using namespace std;



void regresion_lineal(float x[], float y[],int n);

int main(){

int n=5;

float x[5]={1,2,3,4,5};

float y[5]={2.2,2.8,4.5,3.7,5.5};



regresion_lineal(x,y,n);


return 0;    
}


void regresion_lineal(float x[], float y[],int n){

    float producto=0;
    float sumax=0;
    float sumay=0;
    float sumax2=0;
    float m=0;
    float b=0;


    for(int i=0; i<n; i++){

        producto+=x[i]*y[i];
        sumax+=x[i];
        sumay+=y[i];
        sumax2+=(x[i]*x[i]);

    }  

    m=(n*producto- sumax*sumay)/(n*sumax2-(sumax*sumax));

    b=(sumay-m*sumax)/n;

    cout<<"La ecuacion de regresion lineal de los puntos ingresados es: y="<<m<<"x+"<<b<<endl;
    
}
