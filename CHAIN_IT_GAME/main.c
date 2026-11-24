#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "funciones_chain_it.h"

int soundon = 1;

int main(void) {
    int op;
    redimensionarConsola(71, 30);
    system("color 0E");
    system("cls");
    reproducirEnBucle("bgmusic.wav");
    do{
        system("cls");
        title();
        menu();
        printf("\n\tElija una opcion: "); scanf("%d", &op);
        switch (op) {
            case 1:
                system("cls");
                game();
                break;
            case 2:
                estadisticas();
                break;
            case 3:
                system("cls");
                title();
                printf("\n\tOpciones:\n");
                printf("\t[1] Cambiar color de la consola\n");
                printf("\t[2] Apagar/Encender musica de fondo\n");
                printf("\t[3] Volver al menu principal\n");
                printf("\n\tElija una opcion: ");
                scanf("%d", &op);
                switch (op) {
                    case 1:
                        color();
                        break;
                    case 2:
                        switchSound(&soundon);
                        break;
                    case 3:
                        break;
                    default:
                        printf("Opción inválida.\n");
                }
                break;
            case 4:
                detenerSonido();
                printf("Saliendo del juego...\n");
                break;
            default:
                printf("Opcion invalida. Por favor, elija una opcion valida.\n");
        }
    } while(op != 4);
    return 0;
}

