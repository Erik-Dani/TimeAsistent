#include "funcionopc.h"

void RegistroMaterias(char ***Materias, int Num)
{
    /////////Declaracion e inicializacion de Variables///////
    char documento[20];
    cout<<"ingrese su numero de documento: ";
    cin>>documento;
    cout<<endl;
    Num++;

    Materias = new char**[Num];


    ofstream Archivo;//Variable para escribir el txt.
    int CT=0;

    //////////////// Matriz dinamica de Datos///////////////

    Materias[0]=new char*[6];

    MateriasFormat(Materias);

    for(int i=1; i<Num; i++){
        Materias[i]=new char*[6];

        Materias[i][0] = new char[10];
        cout<<"Ingrese el codigo de la materia ["<<i<<"] : ";
        cin>>Materias[i][0];
        FormatoTC(Materias[i][0],10);
        cout<<endl;
        Materias[i][1] = new char[25];
        cout<<"Ingrese el nombre de la materia : ";
        cin>>Materias[i][1];
        FormatoTC(Materias[i][1],25);
        cout<<endl;
        Materias[i][2] = new char[10];
        cout<<"Ingrese Horas de clase teorica : ";
        cin>>Materias[i][2];
        FormatoTC(Materias[i][2],10);
        cout<<endl;
        Materias[i][3] = new char[10];
        cout<<"Ingrese Horas de clase practica: ";
        cin>>Materias[i][3];
        FormatoTC(Materias[i][3],10);
        cout<<endl;
        Materias[i][4] = new char[10];
        cout<<"Ingrese el numero de creditos de la materia: ";
        cin>>Materias[i][4];
        FormatoTC(Materias[i][4],10);
        cout<<endl;
    }

    ////////////////////Imprimir Datos///////////////////////

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
    for (int a = 0; a < Num; a++) {
        for (int b = 0; b < 5; b++) {
            for (int c = 0; c < 25; c++) CT++;
        }
    }
    CT+=(Num*5);

    char *Caja=new char [CT];
    int paso=-1;
    ////////////////Pasar datos a Arreglo Lineal//////////////
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
    paso++;
    Caja[paso]='\0';

    //////////////////Escribimos el Archivo///////////////////

    Archivo.open(documento);
    Archivo <<Caja ;
    Archivo.close();

    //////////////////Borrar memoria reservada///////////////


    delete[] Caja;
    Caja=nullptr;

    ///////////////////Fin de la ejecucion///////////////////
}

void GenerarHorario(char ***horario)
{
    /////////Declaracion e inicializacion de Variables///////
    char name[20];//Numero de documento
    int CT=0;

    ///////////////Recepcion de datos por teclado////////////

    cout<<"ingrese el numbre con el que desea guardar su Horario de clases:  ";
    cin>>name;
    cout<<endl;
    cout<<endl;

    /////////////////////Generar memoria///////////////////////


    horario = new char**[14];
    int dia = 0, dia2 = 0, hora = 0;
    char eleccion;

    for (int i = 0; i < 14; i++) {
        horario[i] = new char*[6];
        for (int j = 0; j < 6; j++) {
            horario[i][j] = new char[10];
        }
    }
    /////////////// Generar Horario ////////////

    FormatoHorario(horario);

    Imprimir(horario,14);

    cout<<"\n\nBienvenido, Por ingrese los horarios de las materias gegistradas.\n\n"<<endl;

    do {
        cout << "//////////////////////Registro de Horario/////////////////////" << endl;

        cout << "\nIngrese el primer dia que desea registrar: " << endl;
        DiaFP();
        cin >> dia;
        cout << "\nIngrese el segundo dia que desea registrar: " << endl;
        DiaFP();
        cin >> dia2;
        HoraFP();
        cin >> hora;

        if (horario[hora][dia][0] == ' ' && horario[hora][dia2][0] == ' ') {
            cout << "\nIngresa el codigo de la materia: ";
            cin >> horario[hora][dia];
            cout<<endl;
            cout<<endl;

            horario[hora][dia]=horario[hora][dia];
            horario[hora][dia2]=horario[hora][dia];

            FormatoTC(horario[hora][dia],10);
            Imprimir(horario,14);
        }
        else {
            cout<< "\nYa esta ocupado el horario, intenta con otro. "<<endl;
        }
        cout << "\nMateria agregada, quiere ingresar otra materia? si=(Pulsa cualquier tecla.\nNo, pulsa  'n' para terminar: ";
        cin >> eleccion;
        cout << endl;

    } while (eleccion != 'n');

    GenerarTxT_M(horario,name,14);

}
