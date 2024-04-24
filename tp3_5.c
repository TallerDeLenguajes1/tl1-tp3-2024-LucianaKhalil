#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LONGITUD_NOMBRE 50

void main() {

    int cantNombres;
    printf("Cuantos nombres desea ingresar? ");
    scanf("%d", &cantNombres);

    char *nombres[cantNombres];//vector de punteros
    char buffer[MAX_LONGITUD_NOMBRE];

    // Leer cada nombre y almacenarlo en el vector de punteros
    for (int i = 0; i < cantNombres; i++) {
        printf("Nombre %d: ", i + 1);
        fflush(stdin);
        gets(buffer);
        
        // Asignar memoria para almacenar el nombre en el vector de punteros
        nombres[i] = malloc((strlen(buffer)+1) * sizeof(char));//+1 para el caracter nulo
        strcpy(nombres[i], buffer);//copiar nombres de buffer en nombres
    }
    printf("\nNombres ingresados:\n");

    // Mostrar los nombres almacenados en el vector
    for (int i = 0; i < cantNombres; i++) {
        printf("%d. %s\n", i + 1, nombres[i]);
    }
    // Liberar la memoria asignada para cada nombre en el vector de punteros
    for (int i = 0; i < cantNombres; i++) {
        free(nombres[i]);
    }
}