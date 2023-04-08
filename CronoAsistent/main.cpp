#include <iostream>
#include <fstream>
#include "dataextract.h"

using namespace std;

int main(void)
{
    int num_materias=0;
    string codigo, materia, dias, horas,H_teoria,H_practica, creditos;
    cout<<"Por favor ingrese el numero de materias que va a registrar: "<<endl;
    cin>>num_materias;
    cout<<"Ingrese el Numero de Codigo de la mateira: "<<endl;
    cin>>codigo;
    cout<<"Ingrese el Horario de la materia"<<endl;
    cin>>materia;
    cout<<"Ingrese el Nombre de la materia: "<<endl;
    cin>>horas;
    cout<<"Ingrese el Numero de Creditos de la Materia: "<<endl;
    cin>>H_teoria;
    cout<<"Ingrese el Numero de horas teoricas:  "<<endl;
    cin>>H_practica;
    cout<<"Ingrese el Numero de horas practicas: "<<endl;
    cin>>creditos;

//    int i=0;
//   string Array[5], Datos,  codigo, materia, dias, horas,H_teoria,H_practica, creditos, codigoh;
//   string Lunes[5], Martes[5], Miercoles[5], Jueves[5], Viernes[5];
//   ifstream Dsalida_r;//lectura
////   ofstream Dentrada_w;//escritura
////   Dentrada_w.open("crono.txt");
////   Dentrada_w.close();

//   Dsalida_r.open("crono.txt");

//   while(getline(Dsalida_r,Datos)){
//       Array[i]=Datos;
//       i++;
//       //DinamikMemori(*Array[])
//   }
//   Dsalida_r.close();
//   for (int i = 0; i < 1; i++) {
//       for (int a = 0, car=0; Array[i][a]!='\0'; a++) {
//           if(Array[i][a]=='|') car++;
//           if     (car==1 && Array[i][a]!='|') codigo+= Array[i][a];
//           else if(car==2 && Array[i][a]!='|') materia += Array[i][a];
//           else if(car==3 && Array[i][a]!='|') dias += Array[i][a];
//           else if(car==4 && Array[i][a]!='|') horas += Array[i][a];
//           else if(car==5 && Array[i][a]!='|') H_teoria += Array[i][a];
//           else if(car==6 && Array[i][a]!='|') H_practica += Array[i][a];
//           else if(car==7 && Array[i][a]!='|') creditos += Array[i][a];
//       }
//       codigoh=codigo+" "+dias+" "+horas;
//       cout<< codigoh <<endl;
//   }


}
