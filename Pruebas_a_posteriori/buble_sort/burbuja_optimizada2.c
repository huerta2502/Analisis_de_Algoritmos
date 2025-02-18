/**
 *  @author @Angel Alan Hernandez Dominguez
 *  Curso: Análisis de algoritmos
 *  (C) Septiembre 2021
 *  ESCOM-IPN
 *  Medición de tiempo del ordenamiento usando el algoritmo de burbuja optimizada 2 en C
 *  Compilación: "gcc burbuja_optimizada1.c ../tiempo.c -o bo2"
 *  Ejecución: "./bo2 n < ../../../numeros10millones.txt" o usando el script "./burbuja_optimizada2.sh"
*/

//*****************************************************************
//Librerias
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../tiempo.h"
//*****************************************************************
//DEFINICION DE CONSTANTES DEL PROGRAMA
//*****************************************************************
#define OK 1
#define ERR 0

#define SI 1
#define NO 0
//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************
int BurbujaOptimizada2(int** A, int n);

int main(int argc, char* argv[]) {
    int n;

    //Recepción y decodificación de argumentos
    if (argc!=2){ //Se espera el valor n
		printf("\nIngrese el # de números a ordenar: \n");
		exit(1);
	} 
	//Se obtiene el valor de n.
	else
		n=atoi(argv[1]);
	

    int* A = (int*)malloc(sizeof(int) * n);

    if(A == NULL){
        perror("Memoria insuficiente\n");
        exit(1);
    } 

    //Llena el arreglo
    int* aux = A;
    for(int i = 0; i < n; i++)
        scanf("%d", aux++);

    printf("Medicion n: %d\n", n);
    if( BurbujaOptimizada2(&A, n) != OK ){
        perror("Ha ocurrido un error\n");
        exit(1);
    }
    
    free(A);
    return OK;
}

//************************************************************************
//DEFINICIÓN DE FUNCIONES 
//************************************************************************
/**
 * Ordena un arreglo usando burbuja optimizada 2 y mide su rendimientp
 * @param A Apuntador a un arreglo de enteros. Arreglo a ordenar.
 * @param n tamaño del arreglo
 */
int BurbujaOptimizada2(int** A, int n) {
    if(A == NULL || *A == NULL) return ERR;

    double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos

    int aux;
    int i = 0;
    int cambios;

    cambios = SI; // true
    //Inicia el conteo de tiempo para la evaluación de rendimiento
    uswtime(&utime0, &stime0, &wtime0);
    while( i < n - 1 && cambios != NO ) {
        cambios = NO;
        for(int j = 0; j < n - 1 - i; j++)
            if( (*A)[j] > (*A)[j + 1] ){
                aux = (*A)[j];
                (*A)[j] = (*A)[j + 1];
                (*A)[j + 1] = aux;
                cambios = SI;
            }
        
        i++;
    }
    //Termina conteo de tiempo
    uswtime(&utime1, &stime1, &wtime1);
    //Cálculo del tiempo de ejecución del programa
	printf("\n");
    printf("\nn=%d\nreal (Tiempo total)  %.10f s\n", n, wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	
	//Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	//******************************************************************
    return OK;
}