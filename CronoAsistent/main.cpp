#include <iostream>
#include <fstream>
#include <istream>

#include "funcionesc.h"
#include "funcionopc.h"

using namespace std;

int main(void)
{
    /////////Declaracion e inicializacion de Variables///////

    char ***Materias=nullptr; // Arreglo dinamico con ptr
    char ***horario=nullptr; // Arreglo dinamico con ptr
    int Numero,opccion=0;
    Materias = new char**[Numero];
    horario = new char**[14];

    cout<<"ingrese el numero de materias: ";
    cin>> Numero;

    RegistroMaterias(Materias,Numero);
    cout<<endl;
    cout<<endl;
    GenerarHorario(horario);
    cout<<"Para la asignacion de horas de estudio independiente: \n1-->Generar horario Random.\n2-->Ingresar por teclado.\n";
    cout<<"Opcion: ";
    cin>>opccion;
    switch (opccion) {
    case 1:
        random(horario,Materias,Numero);
        Imprimir(horario,14);
        break;
    case 2: GenerarHorario(horario);
        break;
    }

    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 6; j++) {
            delete[] horario[i][j];
        }
        delete[] horario[i];
    }
    delete[] horario;

    for (int a = 0; a < Numero; a++) {
        for (int b = 0; b < 5; b++) {
            delete[] Materias[a];
        }
    }
    delete[] Materias;
    delete[] horario;
    Materias=nullptr;
    horario=nullptr;




    ///////////////Recepcion de datos por teclado////////////
}


