#ifndef FUNCIONESC_H
#define FUNCIONESC_H


void imprimirhorario(char*** horario);
void llenar(char*** horario);
void imprimirmate(char ***Materias, int Num);
void formatotxt(char ***Materias, int Num, int paso, char *Caja);
void liberador(char ***Materias, char ***horario, char *Caja, char *Cajahorario, int Num);
bool comparechars(char*** s1, char s2, int Num);
void random(char ***horario, char ***Materias, int Num);
void rellenarArreglo(char *arreglo, int longitud, char relleno);
void formatohorariotxt(char ***horario, int paso, char *Cajahorario);


#endif // FUNCIONESC_H
