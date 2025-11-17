#include <stdio.h>
#include <string.h>
#include "funciones.h"

int ingresoDatos(char nombres[][50], int tiempoF[], int pantallas[],
int tarjetaR[], int memorias[], int discoD[], int cont)
{
    int cantidad = 0;
    int validarCantidad;


    do {
        printf("Ingrese la cantidad de productos que desea registrar (max 5): ");

        validarCantidad = scanf("%d", &cantidad);

        if (validarCantidad != 1) {
            printf("ERROR: debe ingresar un numero.\n");
            while (getchar() != '\n');
            continue;
        }

        while (getchar() != '\n');

        if (cantidad < 1 || cantidad > 5) {
            printf("ERROR: ingrese un numero entre 1 y 5.\n");
            continue;
        }

        if (cont + cantidad > 5) {
            printf("ERROR: ya existen %d productos. Solo puede agregar %d mas.\n",
                   cont, 5 - cont);
            continue;
        }

        break;

    } while (1);



    for (int i = 0; i < cantidad; i++)
    {
        printf("Ingrese el nombre del producto %d: ", cont + 1);
        fgets(nombres[cont], 50, stdin);
        nombres[cont][strcspn(nombres[cont], "\n")] = '\0';


        int validar;
        do {
            printf("Ingrese el tiempo de fabricacion del producto %d (en minutos): ", cont + 1);
            validar = scanf("%d", &tiempoF[cont]);

            if (validar != 1 || tiempoF[cont] < 0) {
                printf("ERROR: ingrese un numero valido.\n");
                while (getchar() != '\n');
            }

        } while (validar != 1 || tiempoF[cont] < 0);

        while (getchar() != '\n');


        printf("Ingrese la cantidad de pantallas que requiere %s: ", nombres[cont]);
        while (scanf("%d", &pantallas[cont]) != 1 || pantallas[cont] < 0) {
            printf("ERROR: ingrese un numero valido.\n");
            while (getchar() != '\n');
        }
        while (getchar() != '\n');

        printf("Ingrese la cantidad de tarjetas ram que requiere %s: ", nombres[cont]);
        while (scanf("%d", &tarjetaR[cont]) != 1 || tarjetaR[cont] < 0) {
            printf("ERROR: ingrese un numero valido.\n");
            while (getchar() != '\n');
        }
        while (getchar() != '\n');


        printf("Ingrese la cantidad de memorias que requiere %s: ", nombres[cont]);
        while (scanf("%d", &memorias[cont]) != 1 || memorias[cont] < 0) {
            printf("ERROR: ingrese un numero valido.\n");
            while (getchar() != '\n');
        }
        while (getchar() != '\n');


        printf("Ingrese la cantidad de discos duros que requiere %s: ", nombres[cont]);
        while (scanf("%d", &discoD[cont]) != 1 || discoD[cont] < 0) {
            printf("ERROR: ingrese un numero valido.\n");
            while (getchar() != '\n');
        }
        while (getchar() != '\n');
        printf("--------------------------");

        cont++; 
    }

    return cont;
}


int compararProdcutos(char nombres[][50], char comparacion[], int cont){

    int encontrado=0;
    for (int i = 0; i < cont; i++)
    {
        int j=0;
        int iguales =1;

        while (nombres[i][j] != '\0' && comparacion[j] != '\0')
        {
            if( nombres[i][j]!= comparacion[j]){
                iguales=0;
                break;
            }
            j++;
        }

        if (iguales && nombres[i][j]== '\0' && comparacion[j] == '\0'){
            printf("Producto encontrado: %s\n", nombres[i]);
                encontrado=1;
                return i;
                

        }
    }
    if (encontrado==0){
        printf("No se encontro el producto '%s'\n", comparacion);
        return-1;
    }

    
}
void tabla1(char nombres[][50], int cont, int tiempoF[5], int pantallas[5], int tarjetaR[5], int memorias[5], int discoD[5]) {


    printf("%-4s %-20s %-15s %-12s %-12s %-12s %-12s\n",
           "#", "Producto", "Tiempo (min)", "Pantallas", "Tarj. RAM", "Memorias", "Discos D");

    printf("---------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < cont; i++) {
        printf("%-4d %-20s %-15d %-12d %-12d %-12d %-12d\n", i + 1,nombres[i],tiempoF[i],pantallas[i],tarjetaR[i],memorias[i],discoD[i]);
    }

    printf("---------------------------------------------------------------------------------------------\n");
}


void EditarProducto (char nombres[][50], int tiempoF[], int pantallas[], int tarjetaR[], int memorias[], int discoD[], int posicion ){
    int validar=1;

    printf("Ingrese el nuevo nombre del producto %d: ", posicion+1);
    fgets(nombres[posicion], 50, stdin);
    nombres[posicion][strcspn(nombres[posicion], "\n")] = '\0';

    do
    {
        printf("Ingrese el nuevo tiempo de Fabricacion del producto %d: ", posicion + 1);
        validar=scanf("%d", &tiempoF[posicion]);
        while (getchar() != '\n');

        if (validar!=1 || validar<1)
        {
            printf("Ingrese una cantidad valida!\n");
            tiempoF[posicion]=0;
            while (getchar() != '\n'); 
        }
        
    } while (validar!=1 || validar<1);
    
    do
    {
        printf("Ingrese la nueva cantidad de pantallas que requiere el prodcuto %d: ", posicion + 1);
        validar=scanf("%d", &pantallas[posicion]);
        while (getchar() != '\n');

        if (validar!=1 || validar<1)
        {
            printf("Ingrese una cantidad valida!\n");
            pantallas[posicion]=0;
            while (getchar() != '\n'); 
        }
        
    } while (validar!=1 || validar<1);

        do
    {
        printf("Ingrese la nueva cantidad de tarjetas RAM que requiere el prodcuto %d: ", posicion + 1);
        validar=scanf("%d", &tarjetaR[posicion]);
        while (getchar() != '\n');

        if (validar!=1 || validar<1)
        {
            printf("Ingrese una cantidad valida!\n");
            tarjetaR[posicion]=0;
            while (getchar() != '\n'); 
        }
        
    } while (validar!=1 || validar<1);

        do
    {
        printf("Ingrese la nueva cantidad de memorias que requiere el prodcuto %d: ", posicion + 1);
        validar=scanf("%d", &memorias[posicion]);
        while (getchar() != '\n');

        if (validar!=1 || validar<1)
        {
            printf("Ingrese una cantidad valida!\n");
            memorias[posicion]=0;
            while (getchar() != '\n'); 
        }
        
    } while (validar!=1 || validar<1);

        do
    {
        printf("Ingrese la nueva cantidad de Discos Duros que requiere el prodcuto %d: ", posicion + 1);
        validar=scanf("%d", &discoD[posicion]);
        while (getchar() != '\n');

        if (validar!=1 || validar<1)
        {
            printf("Ingrese una cantidad valida!\n");
            discoD[posicion]=0;
            while (getchar() != '\n'); 
        }
        
    } while (validar!=1 || validar<1);

    
    
    printf("Su producto ha sido actualizado\n");
    printf("----------------------------------\n");
    
}


void eliminar(char nombre[][50], int tiempoF[], int cantidad[], int productos[], int posicion, int cont) {
    int i, j;

    for (i = posicion; i < cont - 1; i++) {
        for (j = 0; j < 50; j++) {
            nombre[i][j] = nombre[i + 1][j];
        }

        tiempoF[i] = tiempoF[i + 1];
        cantidad[i] = cantidad[i + 1];
        productos[i] = productos[i+1]; 
    }

    
    nombre[cont - 1][0] = '\0';
    tiempoF[cont - 1] = 0;
    cantidad[cont - 1] = 0;
    

    printf("Producto eliminado correctamente\n");
}





void abastecer(int *pantallasF, int *tarjetaRF, int *memoriasF, int *discoDF){

    printf("Ingrese la cantidad de pantallas que desea anadir al inventario : ");
    while (scanf("%d", pantallasF) != 1)
    {
        printf("Entrada invalida. Ingrese un numero: ");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');

    printf("Ingrese la cantidad de Tarjetas RAM que desea anadir al inventario : ");
    while (scanf("%d", tarjetaRF) != 1)
    {
        printf("Entrada invalida. Ingrese un numero: ");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');

    printf("Ingrese la cantidad de memorias que desea anadir al inventario : ");
    while (scanf("%d", memoriasF) != 1)
    {
        printf("Entrada invalida. Ingrese un numero: ");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');

    printf("Ingrese la cantidad de discos duros que desea anadir al inventario : ");
    while (scanf("%d", discoDF) != 1)
    {
        printf("Entrada invalida. Ingrese un numero: ");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');


    printf("Inventario abastecido exitosamente!\n");
}

void pedidos(char nombres[][50], int cont, int cantidad[]) {
    int validar;

    for (int i = 0; i < cont; i++) {
        do {
            printf("Cuantas unidades de %s desea fabricar?\n", nombres[i]);

            validar = scanf("%d", &cantidad[i]);

            if (validar != 1) {
                printf("ERROR: debe ingresar un numero.\n");
                cantidad[i] = -1; 
                while (getchar() != '\n'); 
                continue;
            }


            while (getchar() != '\n');

            if (cantidad[i] < 0) {
                printf("ERROR: no se permiten numeros negativos.\n");
            }

        } while (cantidad[i] < 0);
    }
}


void tablaInventario(int pantallasF, int tarjetaRF, int memoriasF, int discoDF)
{
    printf("-------------------------------------------------------------\n");
    printf("  %-25s %-20s\n", "RECURSO", "CANTIDAD DISPONIBLE");
    printf("-------------------------------------------------------------\n");

    printf("  %-25s %-20d\n", "Pantallas", pantallasF);
    printf("  %-25s %-20d\n", "Tarjetas RAM", tarjetaRF);
    printf("  %-25s %-20d\n", "Memorias", memoriasF);
    printf("  %-25s %-20d\n", "Discos Duros", discoDF);

    printf("-------------------------------------------------------------\n");
}

void tiempo(int tiempoF[], int cont, int cantidad[]) {
    int dias;
    int validar;

    for (int i = 0; i < cont; i++) {

        do {
            printf("En cuantos dias necesita listo el pedido del producto %d?: ", i + 1);

            validar = scanf("%d", &dias);

            if (validar != 1) {
                printf("ERROR: debe ingresar un numero.\n");
                dias = -1;
                while (getchar() != '\n');
                continue;
            }

            while (getchar() != '\n');

            if (dias < 0) {
                printf("ERROR: no se permiten numeros negativos.\n");
            }

        } while (dias < 0);

        int minutos_disponibles = dias * 24 * 60;
        int minutos_necesarios = tiempoF[i] * cantidad[i];

        if (minutos_disponibles >= minutos_necesarios) {
            printf("El tiempo ES suficiente para completar la fabricacion.\n");
        } else {
            printf("El tiempo NO es suficiente para completar la fabricacion.\n");
        }
    }
}

int inventarioVacio(int cantidad[], int cont) {
    int suma = 0;

    for (int i = 0; i < cont; i++) {
        if (cantidad[i] > 0) {
            return 0; // hay inventario
        }
    }

    return 1; // no hay inventario
}

