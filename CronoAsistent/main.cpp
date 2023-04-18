#include <iostream>
#include <fstream>
#include <istream>

#include "funciones.h"
#include "dataextract.h"

using namespace std;

int main(void)
{
    /////////Declaracion e inicializacion de Variables///////

    ofstream Archivo;//Variable para escribir el txt.
    char ***Materias=nullptr; // Arreglo dinamico con ptr
    int Num=0;//Numero de materias;
    char documento[11];//Numero de documento

    ///////////////Recepcion de datos por teclado////////////

    cout<<"ingrese su numero de documento: ";
    cin>>documento;

    cout<<"ingrese el numero de materias: ";
    cin>>Num;
    //////////////// Matriz dinamica de Datos///////////////

   Materias = new char**[Num];

    for(int i=0; i<Num; i++){
        Materias[i]=new char*[6];

        Materias[i][0] = new char[8];
        cout<<"Ingrese el codigo de la materia ["<<i+1<<"] : ";
        cin>>Materias[i][0];
        cout<<endl;
        Materias[i][1] = new char[25];
        cout<<"Ingrese el nombre de la materia : ";
        cin>>Materias[i][1];
        cout<<endl;
        Materias[i][2] = new char[3];
        cout<<"Ingrese Horas de clase teorica : ";
        cin>>Materias[i][2];
        cout<<endl;
        Materias[i][3] = new char[3];
        cout<<"Ingrese Horas de clase practica: ";
        cin>>Materias[i][3];
        cout<<endl;
        Materias[i][4] = new char[3];
        cout<<"Ingrese el numero de creditos de la materia: ";
        cin>>Materias[i][4];
        cout<<endl;
    }

    ////////////////////Imprimir Datos///////////////////////

    for (int a = 0; a < Num; a++) {
        for (int b = 0; b < 5; b++) {
            for (int c = 0; c < 25; c++) {
                cout<<Materias[a][b][c];
                if (Materias[a][b][c]=='\0') break;
            }
            cout<<" | ";
        }
        cout<<endl;
    }
    char *Caja=new char [50];
    int paso=-1;
    ////////////////Pasar datos a Arreglo Lineal//////////////
    for (int a = 0; a < Num; a++) {
        for (int b = 0; b < 5; b++) {
            for (int c = 0; c < 25; c++) {
                if (Materias[a][b][c]=='\0') break;

                if (Materias[a][b][c]!='\0'){
                    paso++;
                    Caja[paso]= Materias[a][b][c];
                }
            }
            paso++;
            Caja[paso]='|';
        }
        paso++;
        Caja[paso]='\n';
    }

    //////////////////Escribimos el Archivo///////////////////

    Archivo.open(documento);
    Archivo <<Caja ;
    Archivo.close();

    //////////////////Borrar memoria reservada///////////////

    for (int a = 0; a < Num; a++) {
        for (int b = 0; b < 5; b++) {
            delete[] Materias[a];
        }
    }
    delete[] Materias;
    delete[] Caja;
    Materias=nullptr;
    Caja=nullptr;

    ///////////////////Fin de la ejecucion///////////////////
}
