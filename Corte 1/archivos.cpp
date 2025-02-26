#include <iostream>
#include <fstream>

using namespace std;

struct Student{
    string name;
    int age;
};

int main(){

    int numStudents;
    cout<<"Ingrese el numero de estudiantes: ";
    cin>>numStudents;

    Student *ptr= new Student[numStudents];

    for(int i=0; i<numStudents; i++){

        cout<<"Ingrese el nombre del estudiante "<< i+1<< ": ";
        cin>> ptr[i].name;
        cout<< "Ingrese la edad del estudiante "<< i+1<<": ";
        cin>> ptr[i].age;

    }

    //Escritura de un archivo
    ofstream outFile("ejemplo.txt", ios::app);
    if(!outFile){
        cout<<"Error al abrir el archivo para leer";
        return 1;
    }
    for(int i=0;i<numStudents;i++){

        outFile<<ptr[i].name<<" "<<ptr[i].age<<endl;

    }
    outFile.close();

    //Lectura de un archivo
    ifstream inFile("ejemplo.txt");

    if(!outFile){
        cout<<"Error al abrir el archivo para leer";
        return 1;
    }

    while(!inFile.eof()){
        Student s;
        inFile >> s.name >> s.age;
        if(inFile){
            cout<<"Nombre: "<< s.name<< "Edad: "<<s.age<<endl;
        }


    }
    inFile.close();








    return 0;
}