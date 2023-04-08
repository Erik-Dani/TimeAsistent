# TimeAsistent

Se agrega el proyecto del git al github despues de mucho esfuerzo.

como primera parte le trabajamos al registro de materias. 
en esta primera parte nos vamos a centrar en tener el siguiente formato:

|codigo de la materia |Nombre de la materia |horario de la clases en la semana de la materia |Horas practicas |Horas teoricas |Numero de creditos 

A continuacion se ilustra con un ejemplo:

|2536101 |Descubriendo la fisica  |MJ 10-12 |4 |0 |3 
|2555131 |Calculo diferencial     |MJ 10-12 |4 |0 |3 
|2555101 |Algebra y trigonometria |MJ 10-12 |4 |0 |3 
|2555121 |Geometria vectorial     |MJ 10-12 |4 |0 |3 
|2598511 |Informatica I           |MJ 10-12 |4 |3 |4

Para el calculo de las horas por semana vamos a tomar el valor de los creditos y lo vamos a usar en la siguiente operacion:
int horasPorSemana =(numero de creditos)  3 - 4;

Las materias con laboratorio seran incluidas en su horario y dias de la para clase de teoria y clase practica en la semana por separado.
