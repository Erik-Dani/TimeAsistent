#ifndef FUNCIONESC_H
#define FUNCIONESC_H

#include <iostream>
#include <fstream>
#include <istream>
#include <time.h>
#include <stdlib.h>
#include "funcionesc.h"

using namespace std;

void RegistroMaterias(char ***, int);
void GenerarTxT(char***,char[], int);
void Imprimir(char ***, int , int );
void MateriasFormat(char*** ); //Formato de cabecera de texto

///////////////////// F2 ///////////////////

void FormatoHorario(char*** );//Genera el formato de la mattiz del horario
void HoraFP();//muestra enunciado
void DiaFP();//muestra enunciado
void FormatoTC(char *, int ); //formatea una cadena
int DatNum(char []);//pasa de str a int

void rellenarArreglo(char *arreglo, int longitud, char relleno) ;

#endif // FUNCIONESC_H
