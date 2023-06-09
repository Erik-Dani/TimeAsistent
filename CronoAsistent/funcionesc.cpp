#include "funcionesc.h"

void GenerarTxT_M(char*** Materias,char Dato[12], int Num){
    int ML=0;

    ofstream Archivo;//Variable para escribir el txt.
      for (int a = 0; a < Num; a++) {
          for (int b = 0; b < 5; b++) {
              for (int c = 0; c < 25; c++) ML++;
          }
      }
      ML+=(4*Num);

      char *Caja=new char [ML];
      int paso=-1;
      char Horario[20];

    ////////////////Pasar datos a Arreglo Lineal//////////////
    for (int a = 0; a < Num; a++) {
        for (int b = 0; b < 6; b++) {
            for (int c = 0; c < 10; c++) {
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

    //////////////////Escribimos el Archivo///////////////////

    Archivo.open(Dato);
    Archivo <<Caja ;
    Archivo.close();

    //////////////////Borrar memoria reservada///////////////
    delete[] Caja;
    Caja=nullptr;
}

void ImprimirMaterias(char ***Matriz, int Num){
    for (int a = 0; a < Num; a++) {
        for (int b = 0; b < 5; b++) {
            for (int c = 0; c < 25; c++) {
                cout<<Matriz[a][b][c];
                if (Matriz[a][b][c]=='\0') break;
            }
            cout<<" | ";
        }
        cout<<endl;
    }
}

void Imprimir(char ***Matriz, int Num){
    for (int a = 0; a < Num; a++) {
        for (int b = 0; b < 6; b++) {
            for (int c = 0; c < 10; c++) {
                cout<<Matriz[a][b][c];
                if (Matriz[a][b][c]=='\0') break;
            }
            cout<<" | ";
        }
        cout<<endl;
    }
}

void RegMateria(char ***Materias, int a){
    bool Reg=true;
    do{
        Materias[a][0] = new char[8];
        cout<<"Ingrese el codigo de la materia ["<<a<<"] : ";
        cin>>Materias[a][0];
        if (a>1){
            for (int i = 0; i<a; i++) {
                int A= DatNum(Materias[a][0]);
                int B=DatNum(Materias[i][0]);
                if (A==B){
                    Reg=false;
                }else break;
            }
        }
        if(Reg!=true){
            cout<<"La materia ya se encuentra registrada, por favor ingrese una diferente."<<endl;
            cout<<"\nIngrese el codigo de la materia a registrar: ";
            cin>>Materias[a][0];
        }else cout<<"Nuevo codigo de materia registrado."<<endl;

    }while(Reg==false);
    FormatoTC(Materias[a][0],10);
}

void RegistroMaterias(char ***Materias, int Num, char dato[14]){

    for(int i=1; i<Num; i++){

        Materias[i]=new char*[6];

        RegMateria(Materias,i);

        Materias[i][1] = new char[25];
        cout<<"Ingrese el nombre de la materia : ";
        cin>>Materias[i][1];
        //FormatoTC(Materias[i][1],25);

        Materias[i][2] = new char[3];
        cout<<"Ingrese Horas de clase teorica : ";
        cin>>Materias[i][2];
        //FormatoTC(Materias[i][2],10);

        Materias[i][3] = new char[3];
        cout<<"Ingrese Horas de clase practica: ";
        cin>>Materias[i][3];
        //FormatoTC(Materias[i][3],10);

        Materias[i][4] = new char[3];
        cout<<"Ingrese el numero de creditos de la materia: ";
        cin>>Materias[i][4];
        //FormatoTC(Materias[i][4],10);
    }

    GenerarTxT_M(Materias,dato,Num);
}
void MateriasFormat(char*** Materias){

    Materias[0][0]= "Codigo    ";
    Materias[0][1]= "Nombre                   ";
    Materias[0][2]= "H_Teoria  ";
    Materias[0][3]= "H_Practica";
    Materias[0][4]= "Creditos  ";
}
///////////////////////FUNCIONES 2////////////////////////////////



void FormatoHorario(char*** horario) {


    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 10; k++) {
                horario[i][j][k] = ' ';
            }
        }
    }

    horario[0][0]= "Hora      ";
    horario[0][1]= "1.Lunes   ";
    horario[0][2]= "2.Martes  ";
    horario[0][3]= "3.Miercole";
    horario[0][4]= "4.Jueves  ";
    horario[0][5]= "5.Viernes ";

    horario[1][0]= "6         " ;
    horario[2][0]= "7         " ;
    horario[3][0]= "8         " ;
    horario[4][0]= "9         " ;
    horario[5][0]= "10        " ;
    horario[6][0]= "11        " ;
    horario[7][0]= "12        " ;
    horario[8][0]= "13        " ;
    horario[9][0]= "14        " ;
    horario[10][0]="15        " ;
    horario[11][0]="16        " ;
    horario[12][0]="17        " ;
    horario[13][0]="18        " ;
}
void HoraFP(){//imprime una seccion de texto
    cout << "Ingrese el horario donde registrara la materia: " << endl;
    cout << "1-> 6" << endl;
    cout << "2-> 7" << endl;
    cout << "3-> 8" << endl;
    cout << "4-> 9" << endl;
    cout << "5-> 10" << endl;
    cout << "6-> 11" << endl;
    cout << "7-> 12" << endl;
    cout << "8-> 13" << endl;
    cout << "9-> 14" << endl;
    cout << "10-> 15" << endl;
    cout << "11-> 16" << endl;
}
void DiaFP(){ //imprime una seccion de texto
    cout << "1-Lunes" << endl;
    cout << "2-Martes" << endl;
    cout << "3-Miercole" << endl;
    cout << "4-Jueves" << endl;
    cout << "5-Viernes" << endl;
}


int DatNum(char Dato[20]){

    int n=0;
    for(int i=0; Dato[i]!='\0'; i++){
        n=n*10+(Dato[i]-'0');
    }
    return n;
}
void FormatoTC(char *Caja, int dim) //Adapta el formato de los datos a la cantidad de memoria reservada
{
    int Tam=0;
    for (int i=0;Caja[i]!='\0';i++,Tam++); //Determinar tamaño de la cadena.
    int Format=dim-Tam;
    if(Format>0){
        for (int i = Tam; i < dim; i++) Caja[i]=' ';//Cubrir tamaño total;

        Caja[dim]='\0';
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

void random(char ***horario, char ***Materias, int Num){

    for(int i = 1; i<Num; i++){
        int aux = (NumReturn(Materias[i][4])*3)-(NumReturn(Materias[i][2]))+(NumReturn(Materias[i][3]));
        int Q = 0;
        while(Q<aux){
            int dia = 1+rand()%(6-1);
            int hora = 1+rand()%(14-1);
            if(horario[hora][dia][0] == ' '){
                Q++;
                horario[hora][dia] = Materias[i][0];
                FormatoTC(horario[hora][dia],10);
            }
        }
    }
}

void CrearHorario(char ***horario, char Dato[13]){

    horario = new char**[14];
    int dia = 0, dia2 = 0, hora = 0;
    char eleccion = ' ';


    for (int i = 0; i < 14; i++) {
        horario[i] = new char*[6];
        for (int j = 0; j < 6; j++) {
            horario[i][j] = new char[10];
        }
    }
    ///////////////Nombre para Horario Formato TXT////////////

    char DatoH[14]; DatoH[0]='H'; DatoH[1]='_';

    for (int i = 2; Dato[i]!='\0'; i++) DatoH[i] = Dato[i-2];

    FormatoHorario(horario);

    Imprimir(horario,14);

    do {
        cout << "//////////////////////Registro de Horario/////////////////////" << endl;

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
            horario[hora][dia]=horario[hora][dia];
            horario[hora][dia2]=horario[hora][dia];

            FormatoTC(horario[hora][dia],10);
            Imprimir(horario,14);
        }
        else {
            cout<< "Ya esta ocupado el horario, intenta con otro. "<<endl;
        }
        cout << "\nMateria agregada, quiere ingresar otra materia? si=(Pulsa cualquier tecla.\nNo, pulsa  'n' para terminar: ";
        cin >> eleccion;
        cout << endl;

    } while (eleccion != 'n');

    //GenerarHorarioTxT(horario,DatoH,14);

}

int conversor(char Dato[30]){

    int n=0;
    for(int i=0; Dato[i]!='\0'; i++){
        n=n*10+(Dato[i]-'0');

    }
    return n;
}

int NumReturn(char Caja[20]){
    char Cajanum[20];
    for (int c =0, p=0 ; Caja[c]!='\0';c++) {
        if(Caja[c]>=48 && Caja[c]<=57){
            Cajanum[p]=Caja[c];
            p++;
        }
    }
     return conversor(Cajanum);
}
