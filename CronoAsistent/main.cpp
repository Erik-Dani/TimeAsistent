#include <iostream>
#include <fstream>
//#include <string>

using namespace std;

int main(void)
{
   int i=0;
   string Array[5], Datos, hora;

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
//   char let='L';
//   for (int i = 0; i < 5; i++) {
//       for (int a = 0, car=0; Array[i][a]!='\0'; a++) {
//           if(Array[i][a]=='|') car++;
//           if(car==2){
//               for (int v = a+1;Array[v]!='|'; v++) {
//                   hora+=Array[v];
//                   if(let==Array[v]){
//                       cout<<"si hay clases"<<endl;

//                   }
//               }



//           }
//       }
//   }
}
