#include <stdio.h>
#include <stdlib.h>
#include "func.h" // Incluyo los headers.
#include "struct.h"
#include "locale.h"
// He decidido hacer un main sencillo y centrar el fuerte del c�digo en el archivo de las funciones.
main()
{
	setlocale(LC_ALL, "");
	char opcionMenu = '\0'; // Asigno "ning�n" car�cter a la variable de opci�n del men� porque me petaba el programa cuando igualaba la variable opci�n a la funci�n del men�, no es muy elegante pero tampoco queda mal.
	printf("\n\n\t************************************\n\t********  MEN� PRINCIPAL  **********\n\t************************************\n\n\n");
	printf("\n\t�Hola, bienvenid@ al sistema! "); // Introducci�n.
	// Aqu� empiezo el bucle del men�. Lo que va a hacer es llamar a la funci�n men�, y �sta recibir� el caracter, ejecutar� el c�digo y si no es un caracter permiti
	do {
		menu(opcionMenu); //Llamo a la funci�n que nos devuelve la opci�n escogida como opcionMenu.
	} while (opcionMenu != 'S' || opcionMenu != 's'); // En la funcion menu, S o s son las teclas de salida, con lo cual, si no es ninguna de ellas, el bucle se repite (m�s informaci�n en func.c, char menu(char).
	system("PAUSE"); //El fin del programa.
	return 0;
}
