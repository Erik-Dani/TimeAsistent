//#include "funcionesc.h"

//void imprimirhorario(char*** horario) {
//    for (int i = 0; i < 14; i++) {
//        for (int j = 0; j < 6; j++) {
//            cout << " | ";
//            for (int k = 0; k < 10; k++) {

//                cout << horario[i][j][k] << " ";
//            }
//        }
//        cout << " | "<<endl;
//    }
//}


//bool Comparar(char** Materias, char cad[], int c){
//    for(int i = 1; i < c-1; i++){
//        if(Materias[i][0]==Materias[i+1][0] || Materias[i][0]==Materias[i-1][0]){
//            return true;
//        }
//    }
//    return false;
//}

//void imprimirmate(char ***Materias, int Num){
//    for (int a = 0; a < Num; a++) {
//        for (int b = 0; b < 5; b++) {
//            for (int c = 0; c < 25; c++) {
//                cout<<Materias[a][b][c];
//                if (Materias[a][b][c]=='\0') break;
//            }
//            cout<<" | ";
//        }
//        cout<<endl;
//    }
//}

//void formatotxt(char ***Materias, int Num, int paso, char *Caja){
//    for (int a = 0; a < Num; a++) {
//        for (int b = 0; b < 5; b++) {
//            for (int c = 0; c < 25; c++) {
//                if (Materias[a][b][c]=='\0') break;

//                if (Materias[a][b][c]!='\0'){
//                    paso++;
//                    Caja[paso]= Materias[a][b][c];
//                }
//            }
//            paso++;
//            Caja[paso]='|';
//        }
//        paso++;
//        Caja[paso]='\n';
//    }
//}

//void liberador(char ***Materias, char ***horario, char *Cajahorario, char *Caja, int Num){
//    for (int i = 0; i < 14; i++) {
//        for (int j = 0; j < 6; j++) {
//            delete[] horario[i][j];
//        }
//        delete[] horario[i];
//    }
//    delete[] horario;

//    for (int a = 0; a < Num; a++) {
//        for (int b = 0; b < 5; b++) {
//            delete[] Materias[a];
//        }
//    }
//    delete[] Materias;
//    delete[] Caja;
//    delete[] Cajahorario;
//    Materias=nullptr;
//    Caja=nullptr;
//    Cajahorario=nullptr;
//}

//bool comparechars(char*** s1, char s2, int Num) {
//    for (int i = 0; i < Num; i++) {
//        if (*s1[i][0] == s2) {
//            return true;
//        }
//    }
//    return false;
//}
