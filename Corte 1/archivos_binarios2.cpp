#include <iostream>
#include <fstream>

using namespace std;




int main(){

    int numeros[]={10,20,30,50};

    int cantidad=sizeof(numeros)/sizeof(numeros[0]);


    //Escribir archivo
    ofstream archivoSalida("array.bin", ios::binary );

    if(!archivoSalida){

        cerr<<"Error al abrir el archivo para escritura"<<endl;
        return 1;
    }

    archivoSalida.write(reinterpret_cast<char*>(&numeros),sizeof(numeros));\
    archivoSalida.close();

    cout<<"Numeros guardado en el archivo binario"<<endl;




    //Leer archivo
    ifstream archivoEntrada("array.bin", ios::binary);

    if(!archivoEntrada){
        cerr<<"Error al abrir el archivo para lectura"<<endl;
        return 1;
    }
    int numeros_leidos[cantidad];
    archivoEntrada.read(reinterpret_cast<char*>(&numeros_leidos),sizeof(numeros_leidos));
    archivoEntrada.close();

    cout<<"Datos leidos en el archivo binario: ";

    for(int i=0;i<cantidad;i++){

        cout<<numeros_leidos[i]<<" ";


    }

    cout<<endl;




    return 0;
}