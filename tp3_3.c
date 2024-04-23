#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRES 5
#define MAX_LONGITUD_NOMBRE 50

void main() {
    char *nombres[MAX_NOMBRES];//vector de punteros
    char buffer[MAX_LONGITUD_NOMBRE];

    printf("Ingrese 5 nombres:\n");

    // Leer cada nombre y almacenarlo en el vector de punteros
    for (int i = 0; i < MAX_NOMBRES; i++) {
        printf("Nombre %d: ", i + 1);
        fflush(stdout); 
        gets(buffer);
     
        // Asignar memoria para almacenar el nombre en el vector de punteros
        nombres[i] = malloc((strlen(buffer)+1) * sizeof(char));//+1 para el caracter nulo
        strcpy(nombres[i], buffer);//copiar nombres de buffer en nombres
    }
    printf("\nNombres ingresados:\n");

    // Mostrar los nombres almacenados en el vector
    for (int i = 0; i < MAX_NOMBRES; i++) {
        printf("%d. %s\n", i + 1, nombres[i]);
    }
    // Liberar la memoria asignada para cada nombre en el vector de punteros
    for (int i = 0; i < MAX_NOMBRES; i++) {
        free(nombres[i]);
    }
}