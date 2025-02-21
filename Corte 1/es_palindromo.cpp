#include <iostream>
using namespace std;
 
int main()
{
   
    char str[1000];

    cin.getline(str,1000);

    char *ptr=str;

    char limpio[1000];
    int tamaño_limpio=0;
    int tamaño=0;

    
    int i=0;

    while(*ptr!='\0'){


        if(((*ptr>='A')&&(*ptr<='Z'))||((*ptr>='0')&&(*ptr<='9'))){
            limpio[i]=*ptr;
            tamaño_limpio +=1;
            i++;
        }
        if((*ptr>='a')&&(*ptr<='z')){

            limpio[i]=*ptr-32;
            tamaño_limpio +=1;
            i++;
        }

        ptr++;
        

    }

    for(int i=0;i<tamaño_limpio;i++){
        cout<<limpio[i];
    }

    cout<<endl;
    bool es_palindromo=true;
    char *izquierda=limpio;
    char *derecha=limpio;



    while(*derecha!='\0'){
        derecha++;
    }
    derecha--;




    while(izquierda<derecha){


        if((*izquierda)!=(*derecha)){
            es_palindromo=false;
            cout<<"**"<<endl;
        }

        izquierda++;
        derecha--;


    }

    if(es_palindromo==true){
        cout<<"Es palindromo";
    }else{

        cout<<"No es palindromo";


    }




    


   













}