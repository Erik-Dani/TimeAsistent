#include <iostream>
#include <fstream>
#include <istream>
#include <time.h>
#include <stdlib.h>
#include "funcionesc.h"

void imprimirhorario(char*** horario);
void llenar(char*** horario);
void formatotxt(char ***Materias, int Num, int paso, char *Caja);
void liberador(char ***Materias, char ***horario, char *Caja, char *Cajahorario, int Num);
bool comparechars(char*** s1, char s2, int Num);
void random(char ***horario, char ***Materias, int Num);
void rellenarArreglo(char *arreglo, int longitud, char relleno);
void formatohorariotxt(char ***horario, int paso, char *Cajahorario);

using namespace std;

int main()
{
    /////////Declaracion e inicializacion de Variables///////

    ofstream Archivo2;
    char ***Materias=nullptr; // Arreglo dinamico con ptr
    int Num=0;//Numero de materias;
    char documento[11];
    int dia = 0, dia2 = 0, hora = 0;
    char eleccion = ' ';

    char ***horario = nullptr;
    horario = new char**[14];

//    ///////////////Recepcion de datos por teclado////////////

//    cout<<"ingrese su numero de documento: ";
//    cin>>documento;

//    cout<<"ingrese el numero de materias que va a registrar: ";
//    cin>>Num;
//    Num++;
//    //////////////// Matriz dinamica de Datos///////////////

//    Materias = new char**[Num];
//    Materias[0]=new char*[6];
//    ////////////////////Registrar Materias /////////////////

//    RegistroMaterias(Materias,Num);

//    ////////////////Imprimir y Guardar Datos///////////////
//    MateriasFormat(Materias);

//    Imprimir(Materias,Num,5);

//    GenerarTxT(Materias,documento,Num);
//}
    //////////////////////Segunda parte///////////////////
          ///////////Generar espacios///////////////

    for (int i = 0; i < 14; i++) {
        horario[i] = new char*[6];
        for (int j = 0; j < 6; j++) {
            horario[i][j] = new char[10];
        }
    }

    FormatoHorario(horario);

    Imprimir(horario,14,6);

    do {
        cout << "//////////////////////CRONOGRAMA/////////////////////" << endl;

        cout << "Ingrese el primer dia que desea registrar: " << endl;
        DiaFP();
        cin >> dia;
        cout << "Ingrese el segundo dia que desea registrar: " << endl;
        DiaFP();
        cin >> dia2;
        HoraFP();
        cin >> hora;

        if (horario[hora][dia][0] == ' ' && horario[hora][dia2][0] == ' ') {
            cout << "Ingresa el codigo de la materia: ";
            cin >> horario[hora][dia];
            horario[hora+1][dia]=horario[hora][dia];
            horario[hora+2][dia]=horario[hora][dia];

            FormatoTC(horario[hora][dia],10);

            horario[hora][dia2] = horario[hora][dia];
            horario[hora+1][dia2]= horario[hora][dia2];
            horario[hora+2][dia2]= horario[hora][dia2];

            Imprimir(horario,14,6);
        }
        else {
            cout<< "Ya esta ocupado el horario, intenta con otro. "<<endl;
        }
        cout << "\nEl usuario ha sido agregado. Presiona cualquier tecla para agregar otro usuario\no '*' para terminar: ";
        cin >> eleccion;
        cout << endl;

    } while (eleccion != '*');

    ////////GUARDAR TXT HORARIO////////
/*    char *Cajahorario= new char [1200];

    formatohorariotxt(horario, paso, Cajahorario);
    //////////////////Escribimos el Archivo///////////////////

    Archivo2.open(documento2);
    Archivo2 <<Cajahorario*/ ;
    //Archivo2.close();

    cout << "\nproceso de eleccion de horas de repaso"<<endl;

    int opc=0;

    cout<<"Elige el metodo de asignacion de horas de repaso"<<endl;
    cout<<"1. Manual(Falta adecuar). "<<endl;
    cout<<"2. Automatico(No recomendable)"<<endl;
    cin>>opc;

    switch(opc){
    case 1:
        break;
    case 2:
        random(horario, Materias, Num);
        break;
    }
}

void formatohorariotxt(char ***horario, int paso, char *Cajahorario){
    for (int i = 0; i < 14; i++) {
        for (int b = 0; b < 6; b++) {

            for (int c = 0; c < 10; c++) {
                if (horario[i][b][c]=='\0') break;

                if (horario[i][b][c]!='\0'){
                    paso++;
                    Cajahorario[paso]= horario[i][b][c];
                }
            }
            paso++;
            Cajahorario[paso]='|';
        }
        paso++;
        Cajahorario[paso]='\n';
    }
}

//void rellenarArreglo(char *arreglo, int longitud, char relleno) {

//    int tamanoActual = 0;
//    while (arreglo[tamanoActual] != '\0') {
//        tamanoActual++;
//    }
//    int espaciosSobrantes = longitud - tamanoActual;
//    if (espaciosSobrantes > 0) {
//        for (int i = tamanoActual; i < longitud; i++) {
//            arreglo[i] = relleno;
//        }
//        arreglo[longitud] = '\0';
//    }
//}



int conversor(char Dato[30]){

    int n=0;
    for(int i=0; Dato[i]!='\0'; i++){
        n=n*10+(Dato[i]-'0');
    }
    return n;
}


void random(char ***horario, char ***Materias, int Num){

    for(int i = 0; i<Num; i++){


        int aux = (conversor(Materias[i][4])*3)-(conversor(Materias[i][2])+conversor(Materias[i][3]));
        cout<<"la operacion da: "<<aux<<endl;





        for(int j = 0; j<5; j++){
            int dia = 1+rand()%(6-1);

            int hora = 1+rand()%(5-1);

            cout<<dia<<" "<<hora<<endl;

            if(horario[hora][dia][0] == ' '){

                cout<<"Funciona :D"<<endl;

                horario[hora][dia] = Materias[i][0];
                Imprimir(horario,14,6);

                break;
            }

        }
    }

}


bool Comparar(char** Materias, char cad[], int c){
    for(int i = 1; i < c-1; i++){
        if(Materias[i][0]==Materias[i+1][0] || Materias[i][0]==Materias[i-1][0]){
            return true;
        }
    }
    return false;
}


void formatotxt(char ***Materias, int Num, int paso, char *Caja){
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
}

void liberador(char ***Materias, char ***horario, char *Cajahorario, char *Caja, int Num){
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 6; j++) {
            delete[] horario[i][j];
        }
        delete[] horario[i];
    }
    delete[] horario;

    for (int a = 0; a < Num; a++) {
        for (int b = 0; b < 5; b++) {
            delete[] Materias[a];
        }
    }
    delete[] Materias;
    delete[] Caja;
    delete[] Cajahorario;
    Materias=nullptr;
    Caja=nullptr;
    Cajahorario=nullptr;
}

bool comparechars(char*** s1, char s2, int Num) {
    for (int i = 0; i < Num; i++) {

        if (*s1[i][0] == s2) {
            return true;
        }

    }
    return false;
}



