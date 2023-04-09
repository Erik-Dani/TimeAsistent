#include "dataextract.h"


void Horario(string, string, string)
{
    char WeekDay[5] ={'L','M','W','J','V'};

}

void Mat_Registr()
{
    ofstream Formato_R;//escritura
    Formato_R.open("Registro.txt");
    int num_materias=0;
    string Formato, codigo, materia, Horario ,H_teoria,H_practica, creditos;

    cout<<"Por favor ingrese el numero de materias que va a registrar: ";
    cin>>num_materias;

    cout<<"Ingrese el Numero de Codigo de la mateira: ";
    cin>>codigo;
    cout<<"Ingrese el Nombre de la materia: ";
    cin>>materia;
    cout<<"Ingrese el Horario de la materia";
    cin>>Horario;
    cout<<"Ingrese el Numero de horas teoricas:  ";
    cin>>H_teoria;
    cout<<"Ingrese el Numero de horas practicas: ";
    cin>>H_practica;
    cout<<"Ingrese el Numero de Creditos de la Materia: ";
    cin>>creditos;

    cout<<Formato<< endl;
    Formato="|"+codigo+"|"+materia+"|"+Horario+"|"+H_teoria+"|"+H_practica+"|"+creditos;
    Formato_R <<Formato;

    Formato_R.close();
}
