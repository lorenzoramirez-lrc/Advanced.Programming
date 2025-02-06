#include <iostream>

using namespace std;

int main(){
    cout<<"Punteros"<<endl;
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

    cout<<endl;


    cout<<"Punteros en Arreglos"<<endl;

    int numeros[]={1,1,2,3,5,8};
    int *puntero_arreglo=numeros;

    for(int i=0;i<6;i++){
        cout<<"Valor posicion ["<<i<<"] del arreglo: "<<*puntero_arreglo<<endl;
        puntero_arreglo++;
    }
    cout<<endl;
    cout<<"Memoria Dinamica"<<endl;


    int tam;

    cin>>tam;

    int *p_arreglo= new int[tam];

    for(int i=0;i<tam;i++){
        cin>>p_arreglo[i];
    }

    cout<<"Valores del arreglo: ";
    for(int i=0;i<tam;i++){
        cout<<p_arreglo[i]<<",";
    }

    delete[] p_arreglo;







    

    


    






return 0;
}