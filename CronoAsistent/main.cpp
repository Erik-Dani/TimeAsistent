#include <iostream>
#include <fstream>
#include <istream>
#include <time.h>
#include <stdlib.h>
#include "funcionesc.h"

using namespace std;

int main()
{
    /////////Declaracion e inicializacion de Variables///////

    ofstream Archivo2;
    char ***Materias=nullptr; // Arreglo dinamico con ptr
    int Num=0;//Numero de materias;
    char documento[10];
    char ***horario = nullptr;

    ///////////////Recepcion de datos por teclado////////////

    cout<<"ingrese su numero de documento: ";
    cin>>documento;

    cout<<"ingrese el numero de materias que va a registrar: ";
    cin>>Num;
    Num++;
    //////////////// Matriz dinamica de Datos///////////////

    Materias = new char**[Num];
    Materias[0]=new char*[6];
    ////////////////////Registrar Materias /////////////////

    RegistroMaterias(Materias,Num,documento);

    ////////////////Imprimir y Guardar Datos///////////////
    MateriasFormat(Materias);

    ImprimirMaterias(Materias,Num);

    //////////////////////Segunda parte///////////////////

            //CrearHorario(horario,documento);
}
