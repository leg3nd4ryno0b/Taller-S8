#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main()
{
    int opc = 0;
    int validar;
    char nombres[5][50] = {0};
    int tiempoF[5] = {0};
    int cantidad[5]= {0};
    int productos[5] = {0};
    int cont = 0;
    int pantallas[5]={0};
    int tarjetaR[5]={0};
    int memorias[5]={0};
    int discoD[5]={0};
    int pantallasF=0;
    int tarjetaRF=0;
    int memoriasF=0;
    int discoDF=0;


    do
    {
        printf("----------MENU----------\n");
        printf("1. Ingresar productos\n");
        printf("2. Informacion de productos\n");
        printf("3. Editar productos\n");
        printf("4. Eliminar productos\n");
        printf("5. Abastecer inventario\n");
        printf("6. Registrar un pedido\n");
        printf("7. Informacion de inventario\n");
        printf("8. Salir\n");
        printf("--------------------------\n");
        printf("Seleccione una opcion: ");
        validar = scanf("%d", &opc);

        if (validar != 1 || opc < 1 || opc > 8)
        {
            printf("Seleccione una opcion valida\n");
            while (getchar() != '\n');
            opc=-1;
        }

        while (getchar() != '\n')
            ;

        switch (opc)
        {
        case 1:
            if (cont >= 5)
            {
                printf("\nSe alcanzo el maximo de 5 productos\n");
                break;
            }
            else
            {
                cont = ingresoDatos(nombres, tiempoF, pantallas, tarjetaR, memorias, discoD, cont);
            }
            break;

        case 2:
        {
            if (cont == 0)
            {
                printf("No hay productos ingresados aun.\n");
                break;
            }

            tabla1(nombres, cont, tiempoF, pantallas, tarjetaR, memorias, discoD);
            char comparacion[50];

            break;
        }
        case 3:
        {
            if (cont == 0)
            {
                printf("No hay productos ingresados aun.\n");
                break;
            }

            char comparacion[50];
            printf("%d \n", cont);
            int c;
            printf("Ingrese el nombre del producto que desea editar: ");
            fgets(comparacion, 50, stdin);
            comparacion[strcspn(comparacion, "\n")] = '\0';
            int editar = compararProdcutos(nombres, comparacion, cont);
            if (editar != -1)
            {
                EditarProducto(nombres, tiempoF, pantallas, tarjetaR, memorias, discoD, editar);
            }

            break;
        }
        case 4:
            if (cont == 0)
            {
                printf("No hay productos ingresados aun.\n");
                break;
            }
        {
            char borrar[50];
            printf("Ingrese el nombre del producto que desea borrar: ");
            fgets(borrar, 50, stdin);
            borrar[strcspn(borrar, "\n")] = '\0';
            int pos = compararProdcutos(nombres, borrar, cont);

            if (pos != -1)
            {
                eliminar(nombres, tiempoF, cantidad, productos, pos, cont);
                cont--;
            }
            else
            {
                printf("Producto no encontrado\n");
            }
            break;
        }
        case 5:
            abastecer(&pantallasF, &tarjetaRF, &memoriasF, &discoDF);
        break;
        case 6:{
            if (cont == 0)
            {
                printf("No hay productos ingresados aun.\n");
                break;
            }
            

            pedidos(nombres, cont, cantidad);

            int pantallasNecesarias = 0;
            int tarjetasNecesarias = 0;
            int memoriasNecesarias = 0;
            int discosNecesarios = 0;

            for (int i = 0; i < cont; i++)
            {
                pantallasNecesarias += pantallas[i] * cantidad[i];
                tarjetasNecesarias += tarjetaR[i] * cantidad[i];
                memoriasNecesarias += memorias[i] * cantidad[i];
                discosNecesarios += discoD[i] * cantidad[i];
            }


            if (pantallasNecesarias > pantallasF ||
                tarjetasNecesarias > tarjetaRF ||
                memoriasNecesarias > memoriasF ||
                discosNecesarios > discoDF)
            {

                printf("\n------------------------------------------------\n");
                printf(" NO ES POSIBLE REALIZAR EL PEDIDO.\n");
                printf(" No hay suficientes recursos en el inventario.\n");
                printf("------------------------------------------------\n");
                break;
            }


            pantallasF -= pantallasNecesarias;
            tarjetaRF -= tarjetasNecesarias;
            memoriasF -= memoriasNecesarias;
            discoDF -= discosNecesarios;

            tiempo(tiempoF, cont, cantidad);
            printf("\n------------------------------------------------\n");
            printf(" PEDIDO REGISTRADO EXITOSAMENTE!\n");
            printf(" Recursos descontados del inventario.\n");
            printf("------------------------------------------------\n");

            break;
        }

        case 7:
            if (cont == 0){
                printf("No hay productos ingresados aun.\n");
                break;
                }
            if (pantallasF <0 && tarjetaRF <0 && memoriasF <0 && discoDF <0){
                printf("No hay inventario ingresado aun.\n");
                break;
            }
            printf("\n === INVENTARIO ACTUAL ===\n");
            tablaInventario(pantallasF, tarjetaRF, memoriasF, discoDF);
        break;  
        case 8:
            printf("Gracias por usar el programa!\n");
            break;
        default:
            printf("Seleccione una opcion valida\n");
            break;
    }

    } while (opc != 8);

    return 0;
}