#include <iostream>
#include <fstream>

using namespace std;

struct Jugador{

    char nombre[30];
    int puntaje;

};


int main(){

    Jugador jugador1={"Mariana",1200};






    //Escribir archivo
    ofstream archivoSalida("jugador.bin", ios::binary );

    if(!archivoSalida){

        cerr<<"Error al abrir el archivo para escritura"<<endl;
        return 1;
    }

    archivoSalida.write(reinterpret_cast<char*>(&jugador1),sizeof(jugador1));
    archivoSalida.close();

    cout<<"Estructura guardado en el archivo binario"<<endl;




    //Leer archivo
    ifstream archivoEntrada("jugador.bin", ios::binary);

    if(!archivoEntrada){
        cerr<<"Error al abrir el archivo para lectura"<<endl;
        return 1;
    }
    Jugador jugador_Leido;
    archivoEntrada.read(reinterpret_cast<char*>(&jugador_Leido),sizeof(jugador_Leido));
    archivoEntrada.close();

    cout<<"Datos leidos en el archivo binario: ";

    cout<< "Jugador Leido: "<<jugador_Leido.nombre<<"- Puntaje: "<<jugador_Leido.puntaje;

    cout<<endl;




    return 0;
}