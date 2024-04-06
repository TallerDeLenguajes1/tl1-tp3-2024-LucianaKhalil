#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ANIO 5
#define MES 12

void cargarMatriz(int matriz[ANIO][MES]);
void mostrarMatriz(int matriz[ANIO][MES]);
void calcularPromedio(int matriz[ANIO][MES]);
int mostrarMax(int matriz[ANIO][MES]);
int mostrarMin(int matriz[ANIO][MES]);

void cargarMatriz(int matriz[ANIO][MES]){
     for(int i=0; i<ANIO; i++){
        for(int j=0; j<MES; j++){
            matriz[i][j]= 10000 + rand() % (50000 - 10000 + 1);
        }
    }
}
void mostrarMatriz(int matriz[ANIO][MES]){
     for(int i=0; i<ANIO; i++){
        for(int j=0; j<MES; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
void calcularPromedio(int matriz[ANIO][MES]){
    
    for(int i=0; i<ANIO; i++){
        float totalAnual=0;  
        for(int j=0; j<MES; j++){
            totalAnual+=matriz[i][j];
        }
    totalAnual=totalAnual/MES;
      printf("El promedio total del anio %d es %.2f\n", i+1, totalAnual);
    }

}
int mostrarMax(int matriz[ANIO][MES]){
    int max=matriz[0][0];
    int anioMayor=0;
    int mesMayor=0;
    int i, j;
    for(i=0; i<ANIO; i++){
        for(j=0; j<MES; j++){
            if(matriz[i][j]>max){
                max=matriz[i][j];
                anioMayor=i;
                mesMayor=j;
            }
        }
    }
    printf("El anio con mayor ventas es el %d\n", anioMayor+1);
    printf("El mes con mayor ventas es el mes %d\n", mesMayor+1);
}
int mostrarMin(int matriz[ANIO][MES]){
    int min=matriz[0][0];
    int anioMenor=0;
    int mesMenor=0;
    int i, j;
    for(i=0; i<ANIO; i++){
        for(j=0; j<MES; j++){
            if(matriz[i][j]<min){
                min=matriz[i][j];
                anioMenor=i;
                mesMenor=j;
            }
        }
    }
      printf("El anio con menor ventas es el %d\n", anioMenor+1);
    printf("El mes con menor ventas es el mes %d\n", mesMenor+1);
}




void main(){
    srand(time(NULL));
    int matriz[ANIO][MES];
    cargarMatriz(matriz);
    printf("La matriz es:\n");
    mostrarMatriz(matriz);
    calcularPromedio(matriz);
    mostrarMax(matriz);
    mostrarMin(matriz);
    
}
