#include "func.h" // Incluyo func.h, que en este caso es necesario para los usos de MAX.

// Creo mi estructura persona con varios campos que corresponden a los datos personales.
struct persona
{
	// He decidido utilizar strings para poder luego aplicar controles de error más específicos y que no me "pete" el programa si introduzco varios char en un int, por ejemplo.
	char nombre[MAX];
	char apellido1[MAX];
	char apellido2[MAX];
	char edad[MAX];
	char sexo[MAX];
	char calle[MAX];
	char numeroDireccion[MAX];
	char codigoPostal[MAX];
	char localidad[MAX];
	char comunidad[MAX];
	char telefono[MAX];
	char email[MAX];
};
