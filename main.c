#include <stdio.h>
#include <stdlib.h>
#include "func.h" // Incluyo los headers.
#include "struct.h"
#include "locale.h"
// He decidido hacer un main sencillo y centrar el fuerte del código en el archivo de las funciones.
main()
{
	setlocale(LC_ALL, "");
	char opcionMenu = '\0'; // Asigno "ningún" carácter a la variable de opción del menú porque me petaba el programa cuando igualaba la variable opción a la función del menú, no es muy elegante pero tampoco queda mal.
	printf("\n\n\t************************************\n\t********  MENÚ PRINCIPAL  **********\n\t************************************\n\n\n");
	printf("\n\t¡Hola, bienvenid@ al sistema! "); // Introducción.
	// Aquí empiezo el bucle del menú. Lo que va a hacer es llamar a la función menú, y ésta recibirá el caracter, ejecutará el código y si no es un caracter permiti
	do {
		menu(opcionMenu); //Llamo a la función que nos devuelve la opción escogida como opcionMenu.
	} while (opcionMenu != 'S' || opcionMenu != 's'); // En la funcion menu, S o s son las teclas de salida, con lo cual, si no es ninguna de ellas, el bucle se repite (más información en func.c, char menu(char).
	system("PAUSE"); //El fin del programa.
	return 0;
}
