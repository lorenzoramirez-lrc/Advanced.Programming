#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Jugador{

    char nombre[30];
    int puntaje;

};


void guardarJugadores(Jugador* jugadores, int cantidad){


    ofstream archivo("jugadores.bin", ios::binary);
    archivo.write(reinterpret_cast<char*>(jugadores), sizeof(Jugador)*cantidad);
    archivo.close();
    cout<<"Jugadores guardados en archivo binario"<<endl<<endl;

}

void leerJugadores(){

    ifstream archivo("jugadores.bin", ios::binary);

    if(!archivo){
        cerr<<"No se encontro el archivo"<<endl;
        return;
    }


    //Obtener cantidad de jugadores
    archivo.seekg(0, ios::end);
    int cantidad=archivo.tellg()/sizeof(Jugador);
    archivo.seekg(0, ios::beg);


    //Crear arreglo dinamico

    Jugador*jugadores= new Jugador[cantidad];

    archivo.read(reinterpret_cast<char*>(jugadores), sizeof(Jugador)*cantidad);


    //Mostrar
    cout<<"Jugadores cargados en el archivo: "<<endl;
    for(int i=0;i<cantidad;i++){

        cout<<jugadores[i].nombre <<" - "<<jugadores[i].puntaje<<"pts."<<endl;

    }

    cout<<endl<<endl;


    

    delete[] jugadores;

}


void encontrar_guardarganador(){


    ifstream archivo("jugadores.bin", ios::binary);

    if(!archivo){
        cerr<<"No se encontro el archivo"<<endl;
        return;
    }


    //Obtener cantidad de jugadores
    archivo.seekg(0, ios::end);
    int cantidad=archivo.tellg()/sizeof(Jugador);
    archivo.seekg(0, ios::beg);


    //Crear arreglo dinamico

    Jugador*jugadores= new Jugador[cantidad];

    archivo.read(reinterpret_cast<char*>(jugadores), sizeof(Jugador)*cantidad);

    Jugador ganador;


    int puntaje_ganador=-1;

    for(int i=0;i<cantidad;i++){

        if(jugadores[i].puntaje>puntaje_ganador){

            strcpy(ganador.nombre, jugadores[i].nombre);
            ganador.puntaje=jugadores[i].puntaje;
            puntaje_ganador=jugadores[i].puntaje;
        }
    }

    ofstream archivoSalida("ganador.bin", ios::binary );

    if(!archivoSalida){

        cerr<<"Error al abrir el archivo para escritura"<<endl;
        return;
    }

    archivoSalida.write(reinterpret_cast<char*>(&ganador),sizeof(ganador));
    archivoSalida.close();

    cout<<"Ganador guardado en el archivo binario"<<endl<<endl;


    delete[] jugadores;


};

int main(){

    int cantidad;

    cout<<"Ingrese el numero de jugadores: ";
    cin>>cantidad;
    cout<<endl;

    Jugador* jugadores= new Jugador[cantidad];

    for(int i=0; i<cantidad; i++){
        cout<<"Nombre del jugador "<<i+1 <<": ";
        cin>>jugadores[i].nombre;
        cout<<"Puntaje: ";
        cin>>jugadores[i].puntaje;
        cout<<endl;

    }

    guardarJugadores(jugadores,cantidad);

    delete[] jugadores;

    leerJugadores();

    encontrar_guardarganador();

    ifstream archivoEntrada("ganador.bin", ios::binary);

    if(!archivoEntrada){
        cerr<<"Error al abrir el archivo para lectura"<<endl;
        return 1;
    }
    Jugador ganador;
    archivoEntrada.read(reinterpret_cast<char*>(&ganador),sizeof(ganador));
    archivoEntrada.close();

    cout<<"Datos leidos en el archivo binario: "<<endl;

    cout<< "Ganador: "<<ganador.nombre<<"- Puntaje: "<<ganador.puntaje<<endl;

    cout<<endl;


    return 0;
}