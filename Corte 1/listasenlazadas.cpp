#include <iostream>

using namespace std;

struct nodo{
    int numeros;
    nodo* siguiente;
};

nodo *cabeza;

void insertar_elemento(int valor){

    nodo* nuevo_elemento= new nodo();
    nuevo_elemento->numeros=valor;
    nuevo_elemento->siguiente = NULL;

    if(cabeza == NULL){
        cabeza= nuevo_elemento;
        cabeza->siguiente=NULL;
        return;
    }

    nodo* ultimo= cabeza;

    while(ultimo->siguiente!=NULL){
        ultimo= ultimo->siguiente;
    }
    ultimo->siguiente=nuevo_elemento;
};

void mostrar_elementos(nodo *n){

    int i=1;
    while(n!=NULL){

        cout<<"Elemento "<<i<<" de la lista es: "<<n->numeros<<endl;
        i++;
        n=n->siguiente;
    }



}

int main(){

    insertar_elemento(6);
    insertar_elemento(5);
    insertar_elemento(4);

    mostrar_elementos(cabeza);












}