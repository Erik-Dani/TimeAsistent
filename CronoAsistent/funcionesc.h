#ifndef FUNCIONESC_H
#define FUNCIONESC_H

#include <iostream>
#include <fstream>
#include <istream>
#include <time.h>
#include <stdlib.h>
#include "funcionesc.h"

using namespace std;

void RegistroMaterias(char ***, int , char []);
void GenerarTxT(char*** horario,char *Caja, int Fila,int columna, int dim);
void ImprimirHorario(char ***, int );
void ImprimirMaterias(char ***, int );
void MateriasFormat(char*** ); //Formato de cabecera de texto

///////////////////// F2 ///////////////////

void FormatoHorario(char*** );//Genera el formato de la mattiz del horario
void HoraFP();//muestra enunciado
void DiaFP();//muestra enunciado
void FormatoTC(char *, int ); //formatea una cadena
int DatNum(char []);//pasa de str a int
void AsignacionRandom(char ***, char ***, int ); //Asignar materias mode random
void CrearHorario(char ***,char Dato[]);
void MemoriaHorario(char ***);

#endif // FUNCIONESC_H
