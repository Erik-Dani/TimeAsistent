#include "funciones.h"

int Dia(){
    int opp=0;
    cout<<"Ingrese la opcion de el dia de la siguiente manera: "<<endl;
    cout<<"1--> Lunes\n2--> Martes\n3--> Miercoles\n4--> Jueves\n5--> Viernes\n";
    cout<<"Opcion: ";
    cin>>opp;
    return opp;
}
int Horas(){
    int opp=0;
    cout<<"Ingrese la opcion de la Hora de la siguiente manera: "<<endl;
    cout<<"1--> 06-08\n2--> 08-10\n3--> 10-12\n4--> 12-14\n5--> 14-16\n6--> 16-18\n";
    cout<<"Opcion: ";
    cin>>opp;
    return opp;
}
