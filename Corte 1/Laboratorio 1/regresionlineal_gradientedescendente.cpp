#include <iostream>

using namespace std;

void regresion_lineal(float *x, float *y,int n, float *m, float *b);

void gradiente_descente(float *x, float *y, int n, float *m, float *b, float alpha, int iteraciones);

int main(){

int n=5;
float x[5]={1,2,3,4,5};
float y[5]={2.2,2.8,4.5,3.7,5.5};
float m;
float b;
float alpha= 0.01;
int iteraciones=1000;



regresion_lineal(x,y,n, &m, &b);
gradiente_descente(x, y, n, &m, &b, alpha, iteraciones);


return 0;    
}

void regresion_lineal(float *x, float *y,int n, float *m, float *b ){

    float productoxy=0;
    float sumax=0;
    float sumay=0;
    float sumax2=0;
    
    for(int i=0; i<n; i++){

        productoxy+= (*(x+i))*(*(y+i));
        sumax+= *(x+i);
        sumay+= *(y+i);
        sumax2+= (*(x+i))*(*(x+i));

    }  

    *m=(n*productoxy- sumax*sumay)/(n*sumax2-(sumax*sumax));

    *b=(sumay-(*m)*sumax)/n;

    cout<<"La ecuacion utilizando regresion lineal en los puntos ingresados es: y="<<*m<<"x+"<<*b<<endl;
    
}



void gradiente_descente(float *x, float *y, int n, float *m, float *b, float alpha, int iteraciones){

    *m=0.0;
    *b=0.0;


    for(int i=0; i<iteraciones; i++){

        float gradiente_m=0.0;
        float gradiente_b=0.0;

        for(int j=0; j<n ;j++){

            float prediccion= (*m)*(*(x+j))+(*b);
            gradiente_m += -2*(*(x+j))*(*(y+j)-prediccion);
            gradiente_b += -2*(*(y+j)-prediccion);

        }

        *m -= alpha*gradiente_m/n;
        *b -= alpha* gradiente_b/n;

    }

    cout<<"La ecuacion utilizando gradiente descente en los puntos ingresados es aproximadamente: y="<<*m<<"x+"<<*b<<endl;

}