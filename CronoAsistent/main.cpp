#include <iostream>
#include <fstream>
#include "dataextract.h"

using namespace std;

int main(void)
{

    int i=0;
   string Array[5], Datos,  codigo, materia, dias, horas,H_teoria,H_practica, creditos, codigoh;
   string Lunes[5], Martes[5], Miercoles[5], Jueves[5], Viernes[5];
   ifstream Dsalida_r;//lectura
//   ofstream Dentrada_w;//escritura
//   Dentrada_w.open("crono.txt");
//   Dentrada_w.close();

   Dsalida_r.open("crono.txt");

   while(getline(Dsalida_r,Datos)){
       Array[i]=Datos;
       i++;
       //DinamikMemori(*Array[])
   }
   Dsalida_r.close();
   for (int i = 0; i < 1; i++) {
       for (int a = 0, car=0; Array[i][a]!='\0'; a++) {
           if(Array[i][a]=='|') car++;
           if     (car==1 && Array[i][a]!='|') codigo+= Array[i][a];
           else if(car==2 && Array[i][a]!='|') materia += Array[i][a];
           else if(car==3 && Array[i][a]!='|') dias += Array[i][a];
           else if(car==4 && Array[i][a]!='|') horas += Array[i][a];
           else if(car==5 && Array[i][a]!='|') H_teoria += Array[i][a];
           else if(car==6 && Array[i][a]!='|') H_practica += Array[i][a];
           else if(car==7 && Array[i][a]!='|') creditos += Array[i][a];
       }
       codigoh=codigo+" "+dias+" "+horas;
       cout<< codigoh <<endl;
   }


}
