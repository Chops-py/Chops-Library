#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>


#include "funciones_chain_it.h"

#pragma comment(lib, "winmm.lib");

char matriz[MAX_FILAS][MAX_COLUMNAS][MAX_LONGITUD_PALABRA];
int total_filas = 0;
char linewords[10][32];
unsigned int colorX;
char command[20];
clock_t inicio, fin;
double tiempo_usado;
char nombresTop[3][32];
double tiemposTop[3];
char palabrasTop[3][10][32];
int cantidadActual = 0;
char matrizPersonalizada[99][10][32];

int obtenerColorActual(void) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        return csbi.wAttributes;
    }

    return 7; // valor por defecto si falla (blanco sobre negro)
}

void setColor(int colorS) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorS);
}

void reproducirEnBucle(const char *archivo) {
    PlaySound(archivo, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void redimensionarConsola(int cols, int lines) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT rectMin = {0, 0, 1, 1};
    SetConsoleWindowInfo(hOut, TRUE, &rectMin);

    COORD bufferSize = {(SHORT)cols, (SHORT)lines};
    SetConsoleScreenBufferSize(hOut, bufferSize);

    SMALL_RECT rect = {0, 0, (SHORT)(cols - 1), (SHORT)(lines - 1)};
    SetConsoleWindowInfo(hOut, TRUE, &rect);
}

void detenerSonido(void) {
    PlaySound(NULL, 0, 0);
}

void title(void) {
    printf("=======================================================================\n");
    printf("\n");
    printf("    ##\t    ##\n");
    printf("    ###\t   ###\n");
    printf("    ##**##**##\t\t     ######   ##  ##\t####\t##  ##\t    ##\n");
    printf("  --##\t##  ##--\t   ###\t  ##  ##  ##  ##    ##\t##  ####    ##\n");
    printf("  --##,,##,,##--\t   ##\t      ##  ##  ##    ##\t##  ##\t##  ##\n");
    printf("      ######   ####\t   ##\t      ######  ########\t##  ##\t##  ##\n");
    printf("      ######   #####\t   ###\t  ##  ##  ##  ##    ##\t##  ##\t  ####\n");
    printf("    ##########\t ####\t     ######   ##  ##  ##    ##\t##  ##\t    ##\n");
    printf("    ##########\t  ###\t\t\t\t\t\t      \n");
    printf("    ##########\t  ###\t\t\t\t\t   ##\t######\n");
    printf("    ##########\t  ###\t\t\t\t\t   ##\t  ##  \n");
    printf("  ##################\t\t\t\t\t   ##\t  ##  \n");
    printf("  ##############\t\t\t\t\t   ##\t  ##  \n");
    printf("\n");
    printf("=======================================================================\n");
}

void cat(void) {
    printf("=======================================================================\n");
    printf("\n");
    printf("    ##      ##\n");
    printf("    ###    ###\n");
    printf("    ##**##**##\n");
    printf("  --##  ##  ##--\n");
    printf("  --##,,##,,##--\n");
    printf("      ######   ####\n");
    printf("      ######   #####\n");
    printf("    ##########\t ####\n");
    printf("    ##########\t  ###\n");
    printf("    ##########\t  ###\n");
    printf("    ##########\t  ###\n");
    printf("  ##################\n");
    printf("  ##############\n");
    printf("\n");
    printf("=======================================================================\n");
}

void cat_WORDS(void) {
    printf("=======================================================================\n");
    printf("\n");
    printf("    ##      ##                   1. \t%s\n", linewords[0]);
    printf("    ###    ###                   2. \t%s\n", linewords[1]);
    printf("    ##**##**##                   3. \t%s\n", linewords[2]);
    printf("  --##  ##  ##--                 4. \t%s\n", linewords[3]);
    printf("  --##,,##,,##--                 5. \t%s\n", linewords[4]);
    printf("      ######   ####              6. \t%s\n", linewords[5]);
    printf("      ######   #####             7. \t%s\n", linewords[6]);
    printf("    ##########\t ####            8. \t%s\n", linewords[7]);
    printf("    ##########\t  ###            9. \t%s\n", linewords[8]);
    printf("    ##########\t  ###            10.\t%s\n", linewords[9]);
    printf("    ##########\t  ###            \n");
    printf("  ##################             \n");
    printf("  ##############                 \n");
    printf("\n");
    printf("=======================================================================\n");
}

int posicion_ultima_letra(char cadena[]) {
    int ultima_pos = -1;
    for (int i = 0; cadena[i] != '\0'; i++) {
        if ((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z')) {
            ultima_pos = i;
        }
    }
    return ultima_pos;
}

void juego_rapido(char palabra_anterior [], char inicial, int longer) {
    printf("=======================================================================\n");
    printf("Palabra anterior: %s\n", palabra_anterior);
    printf("Inicial de la siguiente palabra: %c", inicial);
    for (int i = 1; i <= longer; i++) {
        printf(" _");
    }
    printf("\n=======================================================================\n");
}
void GAME_OVER(char apodo[32], float time) {
    printf("\n=======================================================================\n");
    printf("                             GAME OVER\n");
    printf("Tiempo de partida: %.2f\n", time);
    printf("Nombre del jugador: %s\n", apodo);
    printf("LISTA DE PALABRAS: \n");
    for (int i = 0; i < 10; i++) {
        printf("%s\n", linewords[i]);
    }
    printf("\n");
    system("pause");

}
void instrucciones(void) {
    printf("==================================================\n");
    printf("            CHAIN IT - INSTRUCCIONES\n");
    printf("==================================================\n");
    printf("\n");
    printf("Chain It es un juego de palabras encadenadas.\n");
    printf("\n");
    printf("Cada ronda muestra una cadena de 10 palabras\n");
    printf("unidas por su significado o contexto.\n");
    printf("\n");
    printf("Ejemplo:\n");
    printf("Agua, Limon, Fruta, Arbol, Hoja, Te, Taza...\n");
    printf("\n");
    printf("Cada palabra estara relacionada directamente\n");
    printf("con la ultima palabra de la cadena adivinada\n");
    printf("\n");

    printf("Cada acierto suma puntos.\n");
    printf("Maximo de errores permitidos: 3\n");
    printf("\n");
    printf("Usa la logica y las asociaciones para\n");
    printf("completar la cadena en el menor tiempo.\n");
    printf("\n");
    printf("==================================================\n");
    system("pause");
}
void menu(void) {
    printf("\n");
    printf("\t\t\t Bienvenido a CHAIN IT!\n");
    printf("\t[1] Jugar\n");
    printf("\t[2] Estadisticas\n");
    printf("\t[3] Opciones\n");
    printf("\t[4] Salir\n");
}

void color(void) {
    char opcion[10];
    int salir = 0;

    do {
        system("cls");
        title();
        printf("\n \t1  Azul            5  Purpura\n");
        printf(" \t2  Verde           6  Amarillo\n");
        printf(" \t3  Aqua            9  Azul claro\n");
        printf(" \tA  Verde claro     E  Amarillo claro\n");
        printf(" \tB  Aqua claro      F  Blanco brillante\n");
        printf(" \tD  Magenta\n");
        printf(" \t0  Salir\n");
        printf("=======================================================================\n");
        printf(" \tElige un color: ");

        if (scanf("%9s", opcion) != 1) {
            while (getchar() != '\n');
            continue;
        }
        if (strlen(opcion) != 1 || !isxdigit((unsigned char)opcion[0])) {
            printf("Opcion invalida. Intenta de nuevo.\n");
            continue;
        }
        char c = toupper((unsigned char)opcion[0]);
        if (c == '0') {
            salir = 1;
            printf("Saliendo...\n");
            break;
        }
        if (c == '4' || c == 'C') {
            printf("Ese color no esta permitido.\n");
            continue;
        }
        if (c != '1' && c != '2' && c != '3' && c != '5' && c != '6' &&
            c != '9' && c != 'A' && c != 'B' && c != 'D' && c != 'E' && c != 'F') {
            printf("Opcion invalida. Intenta de nuevo.\n");
            continue;
        }
        sscanf(opcion, "%X", &colorX);
        sprintf(command, "color 0%X", colorX);
        system(command);
    } while (!salir);
                  
}

void switchSound(int *soundon) {
    if (*soundon) {
        detenerSonido();
        *soundon = 0;
    } else {
        reproducirEnBucle("bgmusic.wav");
        *soundon = 1;
    }
}

void game(void) {
    while (1) {
        system("cls");
        title();
        printf("\n\t[1] MODO HISTORIA\n");
        printf("\t[2] JUEGO RAPIDO\n");
        printf("\t[3] JUEGO PERSONALIZADO\n");
        printf("\t[4] VOLVER AL MENU\n");
        printf("=======================================================================\n");
        printf("\tElige una opcion: ");
        int op;
        if (scanf("%d", &op) != 1) {
            while (getchar() != '\n');
            continue;
        }
        switch (op) {
            case 1:
                system("cls");
                story_mode();
                return;
            case 2:
                system("cls");
                quick_game();
                return;
            case 3:
                system("cls");
                custom_game();
                return;
            case 4:
                return; // Volver al menú principal
            default:
                printf("Opcion invalida. Intenta de nuevo.\n");
                system("pause");
        }
    }
}

int cargar_matriz(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error al abrir el archivo %s\n", filename);
        return -1;
    }

    char line[1024];
    int fila = 0;

    while (fgets(line, sizeof(line), file) != NULL && fila < MAX_FILAS) {
        line[strcspn(line, "\n")] = '\0';
        line[strcspn(line, "\r")] = '\0';

        int columna = 0;
        char *token = strtok(line, ",");

        while (token != NULL && columna < MAX_COLUMNAS) {
            while (*token == ' ') token++;
            strncpy(matriz[fila][columna], token, MAX_LONGITUD_PALABRA - 1);
            matriz[fila][columna][MAX_LONGITUD_PALABRA - 1] = '\0';

            columna++;
            token = strtok(NULL, ",");
        }
        fila++;
    }

    total_filas = fila;
    fclose(file);
    return total_filas;
}

void imprimir_elemento(int fila, int columna) {
    if (fila >= 0 && fila < total_filas && columna >= 0 && columna < MAX_COLUMNAS) {
        printf("matriz[%d][%d] = %s\n", fila, columna, matriz[fila][columna]);
    } else {
        printf("Índice fuera de rango\n");
    }
}

char char_to_upper(char c) {
    return toupper((unsigned char)c);
}

int Comparador(char elegida[], char palabra[]) {
    int iguales = 1;
    for (int j = 0; elegida[j] != '\0' || palabra[j] != '\0'; j++) {
        if (char_to_upper(elegida[j]) != char_to_upper(palabra[j])) {
            iguales = 0;
            break;
        }
    }
    return iguales;
}
    
void insertarTop3(char nombre[], double tiempo, char listaPalabras[10][32]) {
    int pos = cantidadActual; 

    for (int i = 0; i < cantidadActual; i++) {
        if (tiempo < tiemposTop[i]) {
            pos = i;
            break;
        }
    }

    if (pos >= 3) {
        return;
    }

    int limite = (cantidadActual < 3) ? cantidadActual : 3 - 1;
    for (int i = limite; i > pos; i--) {
        strcpy(nombresTop[i], nombresTop[i - 1]);
        tiemposTop[i] = tiemposTop[i - 1];
        for (int j = 0; j < 10; j++) {
            strcpy(palabrasTop[i][j], palabrasTop[i - 1][j]);
        }
    }

    strcpy(nombresTop[pos], nombre);
    tiemposTop[pos] = tiempo;
    for (int j = 0; j < 10; j++) {
        strcpy(palabrasTop[pos][j], listaPalabras[j]);
    }

    if (cantidadActual < 3) {
        cantidadActual++;
    }
}

void story_mode(void) {
    printf("Iniciando modo historia...\n");
    // Lógica del modo historia
}

void quick_game(void) {
    for (int i = 0; i < 10; i++) {
        linewords[i][0] = '\0';
    }
    int RED_FLAG = 0;
    srand(time(NULL));
    if (cargar_matriz("ciclos_general.txt") <= 0) {
        printf("Error al cargar el archivo\n");
    }
    instrucciones();
    system("cls");
    char name[32];
    cat();
    printf("Ingrese su nombre de jugador: "); scanf("%s", name);
    system("cls");
    int random_row = rand() % total_filas;
    strcpy(linewords[0], matriz[random_row][0]);
    inicio = clock();
    int z = 0;
    for (int i = 1; i <10; i++) {
        int n = 0;
        while (1) {
            if (n == 3) {
                RED_FLAG = 1;
                break;
            }
            system("cls");
            cat_WORDS();
            printf("ERRORES EN LA PALABRA ACTUAL: %d\n", n);
            printf("ERRORES TOTALES: %d\n", z);
            juego_rapido(matriz[random_row][i-1], matriz[random_row][i][0], posicion_ultima_letra(matriz[random_row][i]));
            if (RED_FLAG == 1) {
                int colorAnterior = obtenerColorActual();
                setColor(12);
                printf("SE A PERDIDO LA OPORTUNIDAD DE HIGH SCORE\n\n");
                setColor(colorAnterior);
            }
            char input[64];
            printf("Ingresa la siguiente palabra: ");
            if (scanf("%63s", input) != 1) {
                while (getchar() != '\n');
                continue;
            }
            if (Comparador(matriz[random_row][i], input)) {
                break;
            } else {
                int colorAnterior = obtenerColorActual();
                setColor(12);
                printf("Incorrecto. Intenta de nuevo.\n");
                system("pause");
                setColor(colorAnterior);
                n++;
                z++;
            }
        } 
        strcpy(linewords[i], matriz[random_row][i]);
    }
    fin = clock();
    tiempo_usado = ((double)(fin - inicio)) / CLOCKS_PER_SEC;
    system("cls");
    GAME_OVER(name, tiempo_usado);
    if (RED_FLAG == 0){
        insertarTop3(name, tiempo_usado, linewords);
    }
    
}

void ingresarCadenas(void) {
    system("cls");

    FILE *archivo = fopen("ciclos_personalizados.txt", "a");
    if (archivo == NULL) {
        return;
    }

    printf("\n=======================================================================\n");
    printf("AGREGANDO PALABRAS AL ARCHIVO DE GUARDADO\n");
    for (int i = 0; i < 10; i++) {
        printf("INGRESE LA PALABRA %d: ", i); 
        char wordsp[32]; 
        scanf("%s", &wordsp);
        fprintf(archivo, "%s", wordsp);
        if (i < 9) { 
            fprintf(archivo, ", ");
        }

    }
    fprintf(archivo, "\n");
    fclose(archivo);
}

void custom_game(void) {
    title();
    printf("1. INGRESAR PALABRAS\n");
    printf("2. JUGAR PARTIDA\n");
    printf("3. REGRESAR AL MENU\n");
    int op;
    scanf("%d", &op);
    switch (op) {
        case 1:
            ingresarCadenas();
            break;
        case 2:
            if (cargar_matriz("ciclos_personalizados.txt") <= 0) {
                printf("Error al cargar el archivo\n");
            }
            system("cls");
            printf("\n=======================================================================\n");
            printf("                     TOTAL DE CADENAS DISPONIBLES: %d\n", total_filas);
            printf("=======================================================================\n\n");
            printf("ELIJA UNA CADENA: "); scanf("%d", &op);
            for (int i = 0; i < 10; i++) {
                linewords[i][0] = '\0';
            }
            system("cls");
            int random_row = rand() % total_filas;
            strcpy(linewords[0], matriz[op][0]);
            inicio = clock();
            int RED_FLAG = 0;
            for (int i = 1; i <10; i++) {
                int n = 0;
                while (1) {
                    if (n == 3) {
                        RED_FLAG = 1;
                        break;
                    }
                    system("cls");
                    cat_WORDS();
                    printf("ERRORES EN LA PALABRA ACTUAL: %d\n", n);
                    juego_rapido(matriz[op][i-1], matriz[op][i][0], posicion_ultima_letra(matriz[op][i]));
                    if (RED_FLAG == 1) {
                        int colorAnterior = obtenerColorActual();
                        setColor(12);
                        printf("ERES TERRIBLE HASTA EN TU PROPIO JUEGO\n\n");
                        setColor(colorAnterior);
                    }
                    char input[64];
                    printf("Ingresa la siguiente palabra: ");
                    if (scanf("%63s", input) != 1) {
                        while (getchar() != '\n');
                        continue;
                    }
                    if (Comparador(matriz[op][i], input)) {
                        break;
                    } else {
                        int colorAnterior = obtenerColorActual();
                        setColor(12);
                        printf("Incorrecto. Intenta de nuevo.\n");
                        system("pause");
                        setColor(colorAnterior);
                        n++;
                    }
                } 
                strcpy(linewords[i], matriz[op][i]);
            }
            fin = clock();
            tiempo_usado = ((double)(fin - inicio)) / CLOCKS_PER_SEC;
            system("cls");
            char name[32] = {'N', 'O', 'N', 'A', 'M', 'E'};
            GAME_OVER(name, tiempo_usado);
            break;
        case 3:
            break;
        default:
            printf("Opción inválida.\n");
    }
}

void estadisticas(void) {
    system("cls");
    printf("\n=======================================================================\n");
    printf("                          TOP 3 MEJORES TIEMPOS\n");
    printf("=======================================================================\n\n");

    if (cantidadActual == 0) {
        printf("Aun no hay partidas registradas.\n");
    } else {
        for (int i = 0; i < cantidadActual; i++) {
            printf("%d) %-20s  Tiempo: %.2f segundos\n", i + 1, nombresTop[i], tiemposTop[i]);
            printf("   Palabras jugadas: ");

            for (int j = 0; j < 10; j++) {
                if (palabrasTop[i][j][0] != '\0') {
                    printf("%s ", palabrasTop[i][j]);
                }
            }
            printf("\n\n");
        }
    }

    printf("=======================================================================\n");
    system("pause");
}