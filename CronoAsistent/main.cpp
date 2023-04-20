#include <iostream>
#include <fstream>
#include <istream>
#include <time.h>
#include <stdlib.h>

void MateriasFormat(char*** Materias);
void imprimirhorario(char*** horario);
void llenar(char*** horario);
void imprimirmate(char ***Materias, int Num);
void formatotxt(char ***Materias, int Num, int paso, char *Caja);
void liberador(char ***Materias, char ***horario, char *Caja, char *Cajahorario, int Num);
bool comparechars(char*** s1, char s2, int Num);
void random(char ***horario, char ***Materias, int Num);
void rellenarArreglo(char *arreglo, int longitud, char relleno);
void formatohorariotxt(char ***horario, int paso, char *Cajahorario);

void FormatDt(char ***Materias,int a,int b, int Num);

using namespace std;

int main()
{
    /////////Declaracion e inicializacion de Variables///////

    ofstream Archivo;//Variable para escribir el txt.
    ofstream Archivo2;
    char ***Materias=nullptr; // Arreglo dinamico con ptr
    int Num=0;//Numero de materias;
    char documento[11], documento2[11];//Numero de documento

    int dia = 0, dia2 = 0, hora = 0;
    char eleccion = ' ';
    char ***horario = nullptr;
    ///////////////Recepcion de datos por teclado////////////

//    cout<<"ingrese su numero de documento: ";
//    cin>>documento;
//    for(int i = 0; i<11; i++){
//        documento2[i] = documento[i];
//    }
//    cout<<"documento dos "<<documento2<<endl;

    cout<<"ingrese el numero de materias: ";
    cin>>Num;
    //////////////// Matriz dinamica de Datos///////////////

    Materias = new char**[Num+1];
    for(int i=1; i<Num; i++){
        Materias[i]=new char*[6];
        if(i==1) MateriasFormat(Materias);

        Materias[i][0] = new char[10];
        cout<<"Ingrese el codigo de la materia ["<<i+1<<"] : ";
        cin>>Materias[i][0];

        Materias[i][1] = new char[30];
        cout<<"Ingrese el nombre de la materia : ";
        cin>>Materias[i][1];

        Materias[i][2] = new char[4];
        cout<<"Ingrese Horas de clase teorica : ";
        cin>>Materias[i][2];

        Materias[i][3] = new char[4];
        cout<<"Ingrese Horas de clase practica: ";
        cin>>Materias[i][3];

        Materias[i][4] = new char[4];
        cout<<"Ingrese el numero de creditos de la materia: ";
        cin>>Materias[i][4];
    }
    for (int i = 0; i < Num; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 10; k++) cout << Materias [i][j][k];
        }
    }

    ////////////////////Imprimir Datos///////////////////////

    imprimirmate(Materias, Num);
    char *Caja=new char [50];
    int paso=-1;
    ////////////////Pasar datos a Arreglo Lineal//////////////

    formatotxt(Materias, Num, paso, Caja);
    //////////////////Escribimos el Archivo///////////////////

    Archivo.open(documento);
    Archivo <<Caja ;
    Archivo.close();

    //////////////////Borrar memoria reservada///////////////



    ///////////////////Fin de la ejecucion///////////////////
    ///
    ///
    //crear matriz para horarios
    horario = new char**[14];
    for (int i = 0; i < 14; i++) {
        horario[i] = new char*[6];
        for (int j = 0; j < 6; j++) {
            horario[i][j] = new char[10];
        }
    }

    llenar(horario);

    imprimirhorario(horario);

    do {
        cout << "-----------------CRONOGRAMA--------------------" << endl;
        cout << "Ingrese el primer dia que desea registrar: " << endl;
        cout << "1-Lunes" << endl;
        cout << "2-Martes" << endl;
        cout << "3-Miercole" << endl;
        cout << "4-Jueves" << endl;
        cout << "5-Viernes" << endl;
        cin >> dia;

        cout << "Ingrese el segundo dia que desea registrar: " << endl;
        cout << "1-Lunes" << endl;
        cout << "2-Martes" << endl;
        cout << "3-Miercole" << endl;
        cout << "4-Jueves" << endl;
        cout << "5-Viernes" << endl;
        cin >> dia2;

        cout << "Ingrese el horario donde registrara la materia: " << endl;
        cout << "1-> 6-8" << endl;
        cout << "2-> 8-10" << endl;
        cout << "3-> 10-12" << endl;
        cout << "4-> 12-14" << endl;
        cout << "5-> 14-16" << endl;
        cout << "6-> 16-18" << endl;
        cin >> hora;

        if (horario[hora][dia][0] == ' ' && horario[hora][dia2][0] == ' ') {
            cout << "Ingresa el codigo de la materia: ";
            cin >> horario[hora][dia];
            rellenarArreglo(horario[hora][dia], 10,  ' ');
            horario[hora][dia2] = horario[hora][dia];
            cout << endl;
            imprimirhorario(horario);
        }
        else {
            cout<< "Ya esta ocupado el horario, intenta con otro. "<<endl;
        }
        cout << "\nRegistrar Horario? SI :presione cualquier tecla, No, presione * para terminar: ";
        cin >> eleccion;
        cout << endl;
    } while (eleccion != '*');

    ////////GUARDAR TXT HORARIO////////
    char *Cajahorario= new char [1200];
    paso=-1;

    formatohorariotxt(horario, paso, Cajahorario);
    //////////////////Escribimos el Archivo///////////////////

    Archivo2.open(documento2);
    Archivo2 <<Cajahorario ;
    Archivo2.close();

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
    liberador(Materias, horario, Cajahorario, Caja, Num);
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

void rellenarArreglo(char *arreglo, int longitud, char relleno) {

    int tamanoActual = 0;
    while (arreglo[tamanoActual] != '\0') {
        tamanoActual++;
    }
    int espaciosSobrantes = longitud - tamanoActual;
    if (espaciosSobrantes > 0) {
        for (int i = tamanoActual; i < longitud; i++) {
            arreglo[i] = relleno;
        }
        arreglo[longitud] = '\0';
    }
}

int conversor(char Dato[30]){
    int n=0;
    for(int i=0; Dato[i]!='\0'; i++) n=n*10+(Dato[i]-'0');
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
                imprimirhorario(horario);
                break;
            }
        }
    }
}

void MateriasFormat(char*** Materias){

    Materias[0][0]= "Codigo     |";
    Materias[0][1]= "Materia    |";
    Materias[0][2]= "H_Teoria   |";
    Materias[0][3]= "H_practica |";
    Materias[0][4]= "4.Jueves   |";
    Materias[0][5]= "5.Viernes  |";
}

void llenar(char*** horario) {

    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 10; k++) {
                horario[i][j][k] = ' ';
            }
        }
    }

    horario[0][0]= "Hora       |";
    horario[0][1]= "1.Lunes    |";
    horario[0][2]= "2.Martes   |";
    horario[0][3]= "3.Miercole |";
    horario[0][4]= "4.Jueves   |";
    horario[0][5]= "5.Viernes  |";

    horario[1][0]= "6          |" ;
    horario[2][0]= "7          |" ;
    horario[3][0]= "8          |" ;
    horario[4][0]= "9          |" ;
    horario[5][0]= "10         |" ;
    horario[6][0]= "11         |" ;
    horario[7][0]= "12         |" ;
    horario[8][0]= "13         |" ;
    horario[9][0]= "14         |" ;
    horario[10][0]="15         |" ;
    horario[11][0]="16         |" ;
    horario[12][0]="17         |" ;
    horario[13][0]="18         |" ;
}

void imprimirhorario(char*** horario) {
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 6; j++) {
            cout << " | ";
            for (int k = 0; k < 10; k++) {

                cout << horario[i][j][k] << " ";
            }
        }
        cout << " | "<<endl;
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

void imprimirmate(char ***Materias, int Num){
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



//void FormatDt(char ***Materias,int a,int b, int Num){
//    char Format[30];
//    cin>>Format;
//    for (int r = 0; r < Num; r++){
//        if(r<Num-1) Materias[a][b][r]= ' ';
//        else {
//            Materias[a][b][r]='|';
//        }
//    }

//    for (int i = 0; Format[i] != '\0'; i++)
//        Materias[a][b][i]=Format[i];
//    cout<<endl;
//}
