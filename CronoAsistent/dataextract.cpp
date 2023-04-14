#include "dataextract.h"


//void Horario(string, string, string)
//{
//    char WeekDay[5] ={'L','M','W','J','V'};

//}

//void Mat_Registr()
//{
//    ofstream Formato_R;//escritura
//    Formato_R.open("Registro.txt");
//    int num_materias=0;
//    string Formato, codigo, materia, Horario ,H_teoria,H_practica, creditos;

//    cout<<"Por favor ingrese el numero de materias que va a registrar: ";
//    cin>>num_materias;

//    cout<<"Ingrese el Numero de Codigo de la mateira: ";
//    cin>>codigo;
//    cout<<"Ingrese el Nombre de la materia: ";
//    cin>>materia;
//    cout<<"Ingrese el Horario de la materia";
//    cin>>Horario;
//    cout<<"Ingrese el Numero de horas teoricas:  ";
//    cin>>H_teoria;
//    cout<<"Ingrese el Numero de horas practicas: ";
//    cin>>H_practica;
//    cout<<"Ingrese el Numero de Creditos de la Materia: ";
//    cin>>creditos;

//    cout<<Formato<< endl;
//    Formato="|"+codigo+"|"+materia+"|"+Horario+"|"+H_teoria+"|"+H_practica+"|"+creditos;
//    Formato_R <<Formato;

//    Formato_R.close();
//}

//int ValNum(char *Num)//de str a int
//{
//    int numE=0;
//    for (unsigned int i = 0, pot=Num.size()-1; i < Num.size(); i++,pot--) {;
//        numE+=(Num[i]-48)*(pow(10,pot));
//    }
//    return numE;
//}

//char NumCad(int num){ //de entero a string 1
//    int numE=0;
//    char caja[10];
//    cadena(num, &numE, &caja);
//    return caja;
//}

//void cadena(int num, int *nump, char *contr){ //de entero a string 2
//    char cad[10];
//    int res=0, cont =0;
//    for (int i = 0; num>0; i++,cont++) {
//        res=num%10;
//        num=num/10;
//        cad[i]=res+'0';
//    }
//    *nump=cont;
//    cad[cont]='\0';
//    char box[cont];
//    for (int i =1 ; i <= cont; i++) box[i-1]=cad[cont-i];
//    for (int i = 0; i < cont; ++i) *contr+= box[i];
//}
