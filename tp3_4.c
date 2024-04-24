#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LONGITUD_NOMBRE 50
#define MAX_PRODUCTOS 5

char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

typedef struct {
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} Producto;

typedef struct {
    int ClienteID;                  // Numerado en el ciclo iterativo
    char NombreCliente[MAX_LONGITUD_NOMBRE]; // Ingresado por usuario
    int CantidadProductosAPedir;    // (aleatorio entre 1 y MAX_PRODUCTOS)
    Producto *Productos;
} Cliente;

float calcularCostoProducto(Producto *producto) {
    return producto->Cantidad * producto->PrecioUnitario;
}

int main() {
    srand(time(NULL));
    int cantClientes;

    do {
        printf("Ingrese la cantidad de clientes (maximo 5): ");
        scanf("%d", &cantClientes);

        if (cantClientes > 5) {
            printf("No puede atender más de 5 clientes. Ingrese otro nro.\n");
        }
    } while (cantClientes > 5);

    Cliente *clientes = malloc(cantClientes * sizeof(Cliente)); // Reserva lugar para la cantidad de clientes


    for (int i = 0; i < cantClientes; i++) {//el puntero cliente recorre todo el arreglo
        printf("\nIngrese el ID del cliente: ");
        scanf("%d", &clientes->ClienteID);

        printf("Ingrese el nombre del cliente: ");
        scanf(" %[^\n]s", clientes->NombreCliente);

        clientes->CantidadProductosAPedir = 1 + rand() % MAX_PRODUCTOS;
        clientes->Productos = malloc(clientes->CantidadProductosAPedir * sizeof(Producto));

        for (int j=0; j<clientes->CantidadProductosAPedir;j++) {
            clientes->Productos->ProductoID = i+1;
            clientes->Productos->Cantidad = 1 + rand() % 10;
            clientes->Productos->TipoProducto = TiposProductos[rand() % 5]; // Tipo de producto aleatorio
            clientes->Productos->PrecioUnitario = 10 + rand() % 91;         // Precio unitario entre 10 y 100

            // Calcular costo del producto
            float costoProducto = calcularCostoProducto(clientes->Productos);

            // Mostrar detalles del producto
            printf("\nProducto ID: %d\n", clientes->Productos->ProductoID);
            printf("Cantidad: %d\n", clientes->Productos->Cantidad);
            printf("Tipo de producto: %s\n", clientes->Productos->TipoProducto);
            printf("Precio unitario: %.2f\n", clientes->Productos->PrecioUnitario);
            printf("Costo producto: %.2f\n", costoProducto);

            // Actualizar el precio unitario del producto con el costo calculado
            clientes->Productos->PrecioUnitario = costoProducto;
        }

        // Calcular total a pagar por cliente
        float total = 0.0;
        for (Producto *producto = clientes->Productos; producto < clientes->Productos + clientes->CantidadProductosAPedir; producto++) {
            total += producto->PrecioUnitario;
        }
        printf("\nTotal a pagar por el cliente %d: %.2f\n", clientes->ClienteID, total);

    }

    // Liberar memoria utilizada
    for (Cliente *cliente = clientes; cliente < clientes + cantClientes; cliente++) {
        free(cliente->Productos);
    }
    free(clientes);

    return 0;
}
