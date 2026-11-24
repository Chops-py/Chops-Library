#ifndef FUNCIONES_CHAIN_IT_H
#define FUNCIONES_CHAIN_IT_H

#define MAX_FILAS 66
#define MAX_COLUMNAS 10
#define MAX_LONGITUD_PALABRA 50

extern char matriz[MAX_FILAS][MAX_COLUMNAS][MAX_LONGITUD_PALABRA];
extern int total_filas;
extern char linewords[10][32];
extern unsigned int colorX;
extern char command[20];
extern clock_t inicio, fin;
extern double tiempo_usado;
extern char nombresTop[3][32];
extern double tiemposTop[3];
extern char palabrasTop[3][10][32];
extern int cantidadActual;
extern char matrizPersonalizada[99][10][32];

int obtenerColorActual(void);
void setColor(int colorS);
void reproducirEnBucle(const char *archivo);
void redimensionarConsola(int cols, int lines);
void detenerSonido(void);
void title(void);
void cat(void);
int posicion_ultima_letra(char cadena[]);
void juego_rapido(char palabra_anterior [], char inicial, int longer);
void GAME_OVER(char apodo[32], float time);
void instrucciones(void);
void menu(void);
void game(void);
void color(void);
void switchSound(int *soundon);
int cargar_matriz(const char *filename);
void imprimir_elemento(int fila, int columna);
char char_to_upper(char c);
int Comparador(char elegida[], char palabra[]);
void insertarTop3(char nombre[], double tiempo, char listaPalabras[10][32]);

void story_mode(void);
void quick_game(void);
void ingresarCadenas(void);
void custom_game(void);
void estadisticas(void);

#endif
