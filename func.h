#pragma once // Directivas del Preprocesador. Incluyo las librerías estándar de C.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 30 // Defino la constante MAX con valor de 30 que nos afectará a todo el proyecto.

// Aquí declaro todas las funciones del programa.
char menu(char);
int errorLetras(char[MAX]);
int errorEdad(char[MAX]);
int errorNumOpcion(int);
int errorNumCalle(char[MAX]);
int errorCP(char[MAX]);
int errorTelefono(char[MAX]);
int errorSexo(char[MAX]);
int errorEmail(char[MAX]);
void registrar();
void acceder();
void autorrellenar();
void imprimirFichero();
void borrarPersona();
void salir();