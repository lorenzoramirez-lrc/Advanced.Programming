#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void head(ifstream& inFile){

    cout<<"Serial  GRE_SCORE  TOEFL_SCORE University Rating   SOP     LOR       CGPA          Research     Chance of Admit"<<endl;
    

    string linea;

    getline(inFile, linea);
    for(int i=0; i<5;i++){

        getline(inFile, linea);


        string particion;

        stringstream linea_estudiante(linea);
        
            
        getline(linea_estudiante,particion,',');
        int serial=stoi(particion);
        getline(linea_estudiante,particion,',');
        int gre=stoi(particion);
        getline(linea_estudiante,particion,',');
        int toefl=stoi(particion);
        getline(linea_estudiante,particion,',');
        int university_rating=stoi(particion);
        getline(linea_estudiante,particion,',');
        float sop=stof(particion);
        getline(linea_estudiante,particion,',');
        float lor=stof(particion);
        getline(linea_estudiante,particion,',');
        float cgpa=stof(particion);
        getline(linea_estudiante,particion,',');
        int research=stoi(particion);
        getline(linea_estudiante,particion,',');
        float chance_of_admit=stof(particion);


        cout<<serial<<"         "<<gre<<"         "<<toefl<<"             "<<university_rating<<"            "<<sop<<"      "<<lor<<"         "<<cgpa<<"             "<<research<<"            "<<chance_of_admit<<endl;

    }



}

void info(ifstream& inFile){
string linea;
    string particion;
    getline(inFile, linea);

    stringstream numero(linea);
    int contador_columnas=0;       
    while(getline(numero,particion,',')){
        contador_columnas++;
    };

    

    string info[contador_columnas+1][4];


    info[0][0]="#";
    info[0][1]="Column";
    info[0][2]="Non-Null Count";;
    info[0][3]="Dtype";
    for(int i=0;i<contador_columnas;i++){
        info[i+1][0]=to_string(i);

    }

    
    inFile.seekg(0);

    getline(inFile,linea);
    stringstream columna(linea); 
    for(int i=0; i<contador_columnas; i++){  
        if (getline(columna, particion, ',')) {
            info[i+1][1] = particion;
            
        }
    }
    getline(stringstream (particion), particion, '\r');
    info[contador_columnas][1] = particion;
    
    inFile.clear();
    inFile.seekg(0);

    int contador_nonnull=0;
    for (int i = 1; i < contador_columnas+1; i++) {
        contador_nonnull = 0;
        inFile.clear();
        inFile.seekg(0); 
        getline(inFile, linea);  
        while (getline(inFile, linea)) {
            stringstream filas_null(linea);
            for(int j=0;j<i;j++){
                getline(filas_null,particion,',');
            }
            if(particion!="\0"){
                contador_nonnull++;
            }
            
        }

        info[i][2] = to_string(contador_nonnull);
    }

    inFile.clear();
    inFile.seekg(0);

    for (int i = 1; i < contador_columnas+1; i++) {
        inFile.clear();
        inFile.seekg(0); 
        getline(inFile, linea);  
        getline(inFile, linea);  
        stringstream filas_null(linea);
        for(int j=0;j<i;j++){
            getline(filas_null,particion,',');
        }
        
        
        if(!stof(particion)){
            info[i][3]="String";
        }else{
            float particion_flotante=stof(particion);
            if((particion_flotante-(int)particion_flotante)==0){
                info[i][3]="Integer";
            }else{
            info[i][3]="Float";
            }
        }

    }


    for(int i=0;i<=contador_columnas;i++){
        for(int j=0;j<4;j++){

            cout<<info[i][j]<<"                     ";


        }
        cout<<endl;
    }
}


int main(){

    ifstream inFile("/home/cristhiam/datasets/admissions/admissions.csv");

    if (!inFile.is_open()){
        cerr << "Error: No se pudo abrir el archivo" << endl;
        return 1;
    }

    cout<<endl<<"Primeras 5 filas del archivo"<<endl;
    head(inFile);

    cout<<endl;

    inFile.clear();
    inFile.seekg(0);

    cout<<"Informacion del archivo"<<endl;
    info(inFile);

    inFile.close();

    return 0;
}