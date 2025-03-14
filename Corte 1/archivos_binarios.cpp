#include <iostream>
#include <fstream>

using namespace std;




int main(){

    int numero=42; //Numero a guardar en el archivo



    //Escribir archivo
    ofstream archivoSalida("datos.bin", ios::binary );

    if(!archivoSalida){

        cerr<<"Error al abrir el archivo para escritura"<<endl;
        return 1;
    }

    archivoSalida.write(reinterpret_cast<char*>(&numero),sizeof(numero));

    archivoSalida.close();

    cout<<"Numero guardado en el archivo binario"<<endl;




    //Leer archivo
    ifstream archivoEntrada("datos.bin", ios::binary);

    if(!archivoEntrada){
        cerr<<"Error al abrir el archivo para lectura"<<endl;
        return 1;
    }
    int numero_leido;
    archivoEntrada.read(reinterpret_cast<char*>(&numero_leido),sizeof(numero_leido));
    archivoEntrada.close();

    cout<<"Numero leido en el archivo binario: "<<numero_leido;






    return 0;
}