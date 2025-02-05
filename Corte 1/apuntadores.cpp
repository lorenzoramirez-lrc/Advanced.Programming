#include <iostream>

using namespace std;

int main(){

    int x=42;
    int *ptr= &x; //Primer puntero
    int **ptr2= &ptr; //Puntero a puntero
    cout<<"Variable x: "<<x<<endl;
    cout<<"Apuntador ptr: "<<ptr<<endl; //Direccion de la Variable
    cout<<"Valor Apuntado: "<<*ptr<<endl; //Operacion Desreferencia
    cout<<"Direccion:"<<&ptr<<endl; //Operacion Direccion
    cout<<"Direccion de puntero ptr: "<<ptr2<<endl;//Direccion del puntero 1
    cout<<"Valor Apuntado 2: "<<*ptr2<<endl; //Valor del puntero 1
    cout<<"Direccion 2: "<<&ptr2<<endl; //Direccion del puntero 2




    return 0;
}