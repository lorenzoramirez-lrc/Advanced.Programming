#include <iostream>

using namespace std;


struct estudiante{

    string nombre;
    float *calificaciones;
    estudiante* siguiente;
    


};

estudiante *cabeza;

void insertar_elemento(string nombre, float *calificaciones){

    estudiante* nuevo_elemento= new estudiante();
    nuevo_elemento->nombre=nombre;
    nuevo_elemento->calificaciones=calificaciones;
    nuevo_elemento->siguiente = NULL;

    if(cabeza == NULL){
        cabeza= nuevo_elemento;
        cabeza->siguiente=NULL;
        return;
    }

    estudiante* ultimo= cabeza;

    while(ultimo->siguiente!=NULL){
        ultimo= ultimo->siguiente;
    }
    ultimo->siguiente=nuevo_elemento;
};

void burbuja(float arreglo[], int tamaño){
    for(int i=0; i<tamaño-1; i++){
        for(int j=0; j<tamaño-1-i; j++){
            if(arreglo[j]<arreglo[j+1]){
                int temp= arreglo[j];
                 arreglo[j]=arreglo[j+1];
                 arreglo[j+1]=temp;
            }
        }
    }
}

void buscador(string nombre, estudiante *n){

    bool encontrado=false;
    while(n!=NULL){

        if(n->nombre==nombre){

            cout<<"La maxima calificacion de "<<n->nombre<<" es de: "<<*n->calificaciones<<endl;
            encontrado=true;
            break;
        }

        n=n->siguiente;
    }

    if(encontrado==false){
        cout<<"Estudiante no encontrado, intente nuevamente"<<endl;

    }

}



int main(){

    int numero_estudiantes;
    cout<<"Ingrese el numero de estudiantes que quiere añadir al sistema de registro: ";
    cin>> numero_estudiantes;
    cout<<endl;

    for(int i =0;i<numero_estudiantes; i++){

        string nombre=" ";
        cout<<"Ingrese el nombre del estudiante "<<i+1<<": ";
        cin>>nombre;

        int numero_calificaciones;
        cout<<"Ingrese el numero de calificaciones que tiene el estudiante: ";
        cin>>numero_calificaciones;

        float *calificaciones= new float[numero_calificaciones];


        for(int i=0;i<numero_calificaciones;i++){
            cout<<"Ingrese la  calificacion "<<i+1<<" del estudiante: ";
            cin>>calificaciones[i];
        }

        cout<<endl;
        
        burbuja(calificaciones,numero_calificaciones);
        
        insertar_elemento(nombre, calificaciones);




    }


    string x="0";
    do{
        string nombre;
        cout<<"Ingrese el nombre del estudiante del que quiere obtener su mejor calificacion: ";
        cin>>nombre;

        buscador(nombre, cabeza);

        cout<<endl;
        cout<<"Desea realizar otra busqueda presione (0) para si cualquier otra tecla para no: ";
        cin>>x;
        cout<<endl;
        

    }while(x=="0");

    cout<<"Proceso terminado exitosamente";
    

    return 0;
}