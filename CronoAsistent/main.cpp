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



    ///////////////Recepcion de datos por teclado////////////
}


