#pragma once
#include "func.h" // Incluyo los headers.
#include "struct.h"
#include "locale.h"
#include "string.h"
#define _CRT_SECURE_NO_WARNINGS

struct persona registro[50]; // Creo mi variable de la estructura en forma de array, que ser� el registro de cada persona. Hay un m�ximo de 50 personas para registrar.
int contadorRegistros = 0; // Variable global que mantiene el n�mero de personas registradas (he puesto 3 como m�ximo).
int contadorAutorrelleno = 0; // Contador del uso de la funci�n del autorrelleno.
int i = 0; // Variable global contador para las distintas posiciones dentro del struct persona registro [i].
int primerUso = 0; //Cuenta a partir del primer uso del men�.
int masDe10 = 0; // Contador para saber si hay m�s de 10 usuarios registrados.
// Funci�n del men�. Nos deja elegir entre las cuatro opciones abajo. Todo el c�digo est� pulcra y premeditadamente ordenado y estructurado para que quede bien (de ah� que haya muchos \n y \t).
char menu(char a)
{
	setlocale(LC_ALL, "");
	if (primerUso > 0) { // Si intercambiamos el plan por el bucle o el inicio del bucle cerrado, cambiamos las directrices del mismo, o las reglas.
		system("CLS");
		printf("\n\n\t************************************\n\t********  MEN� PRINCIPAL  **********\n\t************************************\n\n\n"); // Cabecera.  
	}
	char opcion; // La opci�n que registraremos.
	printf("\t�Qu� desea hacer?\n\n\n\tR: Registrarse.\n\n\tA: Acceder.\n\n\tI: Imprimir en un Fichero.\n\n\tB: Borrar usuario.\n\n\tX: Autorrellenar.\n\n\tS: Salir.\n\n");
	printf("\n\t");
	scanf_s("%c", &opcion); // Recojo la opci�n.
	getchar();
	// Switch para considerar cada opci�n.
	switch (opcion) {
	case 'R':
	case 'r':
		if (contadorRegistros > 50) { // Aqu� tenemos la primera condici�n que nos dir� que si el contador de registros supera el 3, nos imprima que se ha alcanzado el n�mero m�ximo.
			printf("\n\n\tSe ha alcanzado el n�mero m�ximo de Registros (Enter).\n\n\n"); // Si es as� no nos dejar� continuar y volveremos al men� para re-elegir opci�n.
			break;
		}  
		else {
			contadorRegistros++; //Si no hemos llegado al tope se incrementa el contador de registros.
			registrar(); //Llamada a la funci�n de registrar al usuario.
			break; // Salida del bucle una vez registrado el usuario y nos lleva de nuevo al men� principal ya que no hemos introducido S o s.	
		}

	case 'A':
	case 'a':
		if (contadorRegistros < 1 || i == 0) { // En este caso si no hemos registrado a nadie todav�a, no nos dejar� entrar a la opci�n de acceso a la informaci mn �n de los usuarios registrados.
			printf("\n\n\tNo hay ning�n usuario registrado en la Base de Datos (Enter).\n\n\n");
			.. 
		}
		else if (contadorRegistros >= 1) { // Sin embargo, si s� que hay usuarios registrados, nos dejar� llamar a la funci�n.
			acceder();

		}
		break;

	case 'I':
	case 'i':
		if (contadorRegistros < 1 || i == 0) { // Mismo control que en el campo de Acceder.
			printf("\n\n\tNo hay ning�n usuario registrado en la Base de Datos (Enter).\n\n\n");
		}
		else if (contadorRegistros >= 1) {
			imprimirFichero(); // Llamada a la funci�n.
		}
		break;

	case 'B':
	case 'b':
		if (i == 0) { // Mismo control que en el campo de Acceder.
			printf("\n\n\tNo hay ning�n usuario para borrar (Enter).\n\n\n");
		}
		else
			borrarPersona(); // Llamada a la funci�n.
		break;

	case 'X':
	case 'x':
		if (contadorAutorrelleno > 0) {
			printf("\n\n\tYa ha utilizado la funci�n de Autorrelleno. S�lo puede utilizarse una vez (Pulse doble ENTER).");
			break;
		}
		else {
			contadorRegistros++;
			autorrellenar(); // Funci�n para autorrellenar 5 personas.
			break;
		}

	case 'S':
	case 's':

		salir(); // Llamada a la funci�n y ser�a el fin del programa.
		break;

	default: // Si el usuario introduce cualquier otra cosa, da error.

		printf("\n\n\t�ERROR! Escoja otra vez (Enter).\n\n\n"); // He puesto Enter porque m�s abajo he puesto un getchar, es algo que el usuario tiene que introducir s� o s�, as� que mejor si queda dicho disimuladamente.
		break;
	}
	a = opcion; // Sencillamente asigno el valor de la opci�n a a para posteriormente devolver a al main.c, donde se llam� a �sta funci�n de men�.
	printf("\t"); // Sencillamente es para dejar la barra de texto de la consola debido al getchar de abajo en l�nea con la sangr�a.
	primerUso += 1;
	getchar(); // Para no tener problemas y limpiar el b�fer.
	return a;
}

// Aqu� empiezan las funciones que se encargan de comprobar si hay error en el texto introducido por el usuario. Empiezo con el control de eroor  de las palabras de texto nombre, apellidos, Calle, Localidad y Comunidad.
int errorLetras(char frase[MAX]) // Una variable que me devolver� un entero 0 o 1 ya que en todas las funciones est� la variable error dentro de un bucle con condici�n de repetirse si se devuelve error = 1;
{
	setlocale(LC_ALL, "");
	int error = NULL; //Mi variable de error.
	for (int j = 0; frase[j] != '\0'; j++) { // Empieza el bucle que nos recorre la frase.
		if ((frase[j] >= 'a' && frase[j] <= 'z') || (frase[j] >= 'A' && frase[j] <= 'Z') || frase[j] == ' ' || frase[j] == '-') { // Mientras sean letras, espacios para nombres compuestos o - para nombres con Gui�n, el error ser� 0.
			error = 0;
			continue;
		}
		else if ((frase[j] > 00 && frase[j] < 32) || (frase[j] > 32 && frase[j] < 45) || (frase[j] > 45 && frase[j] < 65) || (frase[j] > 90 && frase[j] < 97) || frase[j] > 122) { // En todo caso contrario el error ser� 1.
			printf("\n\n\t�ERROR! Ha introducido un car�cter no v�lido.\n\n"); // Imprime la frase  de error que sera muy parecida (o igual en algunos casos) a las de otras funciones de control de error.
			error = 1;
			break;
		}
	}
	return error; // Devuelve el error como 1 o 0.
}

int errorEdad(char numero[MAX]) // �sta funci�n devuelve el error y recibe el n�mero en cadena.
{
	setlocale(LC_ALL, "");
	int error;
	int j;
	for (j = 0; numero[j] != '\0'; j++) { // Recorre la cadena.
		if (numero[j] >= 48 && numero[j] <= 57) // Analiza si el caracter en la posici�n actual es un n�mero o no, y si no lo esos el error es 0 y contin�a.
			error = 0;
		else if (numero[j] < 48 || numero[j] > 57) { // Si no es un n�mero da error = 1 y se sale del bucle porque ya sabemos que est� mal y se vuelve de nuevo a la funci�n de registrar al bucle donde se ha llamado a esta funcion.
			printf("\n\n\t�ERROR! Ha introducido un car�cter no v�lido.\n\n");
			error = 1;
			break;
		}
	}
	if (j != 2) { // Si hay m�s de 3 car�cteres o menos de 2 (sabiendo ya que no se ha introducido ning�n car�cter no v�lido) da error ya que el rango de edad permitida est� entre 10 a�os y 99
		printf("\n\n\t�ERROR! La edad es incorrecta (El usuario debe ser mayor de 10 y menor de 100). Pruebe de nuevo.\n\n");
		error = 1; // Asigna 1 a error.
	}
	return error; // Devuelve el valor del error.
}

int errorNumOpcion(int numOpcion) // �sta funci�n devuelve el error y recibe el n�mero en cadena.
{
	setlocale(LC_ALL, "");
	int error = 0;
	if (masDe10 == 0 && numOpcion > 10) { // Si no hay m�s de 10 usuarios registrados y 
		printf("\n\n\t�ERROR! Ha introducido un n�mero mayor al n�mero de usuarios registrados (Pulse ENTER y pruebe de nuevo).\n\n");
		getchar();
		getchar();
		error = 1; // Asigna 1 a error.
		return error;
	}
	return error; // Devuelve el valor del error.
}
	
int errorNumCalle(char numero[MAX]) // �sta funci�n es igual a la anterior excepto al final.
{
	setlocale(LC_ALL, "");
	int error = NULL;
	int j;
	for (j = 0; numero[j] != '\0'; j++) {
		if (numero[j] >= 48 && numero[j] <= 57)
			error = 0;
		else if (numero[j] < 48 || numero[j] > 57) {
			printf("\n\n\t�ERROR! Ha introducido un car�cter no v�lido.\n\n");
			error = 1;
			break;
		}
	}
	if (j > 3) { // La calle con m�s n�meros de espa�a la Gran Via de les Corts Catalanes con 689, con lo cual pongo el tope en 3 cifras.
		printf("\n\n\t�ERROR! El n�mero de calle introducido es incorrecto. Pruebe de nuevo.\n\n");
		error = 1;
	}
	return error;
}

int errorCP(char numero[MAX]) // Lo mismo que el anterior pero con una variaci�n al final.
{
	setlocale(LC_ALL, "");
	int error;
	int j;
	for (j = 0; numero[j] != '\0'; j++) {
		if (numero[j] >= 48 && numero[j] <= 57)
			error = 0;
		else if (numero[j] < 48 || numero[j] > 57) {
			printf("\n\n\t�ERROR! Ha introducido un car�cter no v�lido.\n\n");
			error = 1;
			break;
		}
	}
	if (j != 5) { // A�ado la condici�n de que si el c�digo postal tiene menos o m�s de 5 d�gitos nos da error, ya que los c�digos postales tienen todos 5 d�gitos en Espa�a.
		printf("\n\n\t�ERROR! El C�digo Postal debe tener 5 n�meros.\n\n");
		error = 1;
	}
	return error;
}

int errorTelefono(char numero[MAX]) // Lo mismo que el anterior excepto al final.
{
	setlocale(LC_ALL, "");
	int error;
	int j;
	for (j = 0; numero[j] != '\0'; j++) {
		if (numero[j] >= 48 && numero[j] <= 57)
			error = 0;
		else if (numero[j] < 48 || numero[j] > 57) {
			printf("\n\n\t�ERROR! Ha introducido un car�cter no v�lido.\n\n");
			error = 1;
			break;
		}
	}
	if (j != 9) { // En este caso s� que todos los n�meros de tel�fono en espa�a tienen 9 d�gitos, as� que si se han introducido menos o m�s de 9, da error y habr� que reintroducir el n�mero.
		printf("\n\n\t�ERROR! El n�mero de tel�fono es incorrecto (El n�mero debe tener 9 d�gitos). Pruebe de nuevo.\n\n");
		error = 1;
	}
	return error;
}

int errorSexo(char sexo[MAX]) // En el control de error del sexo recibimos la palabra introducida por el usuario que como se pide en el men� de arriba, debr�a ser s�lo la inicial del sexo, luego en otra funci�n se cambiar� al completo.
{
	setlocale(LC_ALL, "");
	int error = NULL;
	int numChar = 0; // Contador de car�cteres.
	for (int j = 0; sexo[j] != '\0'; j++) { //Recorre la palabra y si hay un car�cter distinto a las opciones del men� da error.
		if (sexo[j] == 'H' || sexo[j] == 'h' || sexo[j] == 'M' || sexo[j] == 'm' || sexo[j] == 'O' || sexo[j] == 'o')
			error = 0;
		else if (sexo[j] != 'H' || sexo[j] != 'h' || sexo[j] != 'M' || sexo[j] != 'm' || sexo[j] != 'O' || sexo[j] != 'o') {
			printf("\n\n\t�ERROR! Ha introducido un car�cter no v�lido.\n\n");
			error = 1;
			break;
		}
		if (numChar > 1) { // Como s�lo hay que meter la inicial, si hay m�s de 1 car�cter, da error.
			printf("\n\n\t�ERROR! Ha introducido m�s de un car�cter.\n\n");
			error = 1;
			break;
		}
		numChar++; // Aqu� tengo el incremento del contador de car�cteres.
	}
	return error;
}

int errorEmail(char mail[MAX]) // El control de error m�s complejo, basado en el de los ejercicios de clase (creo que pusiste mi c�digo en el blackboard como ejemplo de soluci�n) y perfeccionado para este programa. 
{
	setlocale(LC_ALL, "");
	int j, contarrobas = 0, contapuntos = 0, puntoTrasArroba = 0, contaGuiones = 0, error = 0; // Variables contadores.
	for (j = 0; mail[j] != '\0'; j++) { // Recorre el email
		if (mail[j] == '@') {
			contarrobas++; // Si la posici�n actual es una @ se incrementa el contador de arrobas.
			if (j == 0) { // Si hay una en la posici�n 0, da error y sale del bucle y devuelve error al bucle de la funci�n de registrar en el campo del email.
				error = 1;
				printf("\n\n\t�Email incorrecto!\n\n"); // Texto de error.
				return error;
			}
		}
		if (mail[j] == '-') { // En el caso del gui�n se utiliza el contador si hay uno en la posici�n actual.
			contaGuiones++;
			if (contarrobas == 0 && contaGuiones > 1 || contarrobas == 1 && contaGuiones > 1) { // Tanto antes como despu�s de la arroba, s�lo puede haber 1 gui�n, si no es el caso, como dice la condici�n, devuelve error = 1.
				error = 1;
				printf("\n\n\t�Email incorrecto!\n\n"); // Texto de error.
				return error;
			}
		}
		if (mail[j] == '.') { // Lo mismo para el punto.
			contapuntos++;
			if (mail[j - 1] == '@' || mail[j + 1] == '@') { // No puede haber un punto inmediatamente antes o despu�s de una @.
				error = 1;
				printf("\n\n\t�Email incorrecto!\n\n"); // Texto de error.
				return error;
			}
			if (mail[j - 1] == '.' || mail[j + 1] == '.') { // Tampoco puede haber un punto inmediatamente antes o despu�s de otro punto.
				error = 1;
				printf("\n\n\t�Email incorrecto!\n\n"); // Texto de error.
				return error;
			}
			if (j == 0 || mail[j + 1] == '\0') { // Si estando en un punto en la posici�n actualy resulta que estamos en la posici�n 0 o la �ltima (antes del '\0') devuelve error = 1.
				error = 1;
				printf("\n\n\t�Email incorrecto!\n\n"); // Texto de error.
				return error;
			}
		}
		if (mail[j] == '.' && contarrobas == 1) // Sigo estando con un punto en la posici�n actual, y si adem�s ya ha habido una arroba antes, s�lo puede haber 2 puntos tras la arroba (ej: @live.u-tad.com).
			puntoTrasArroba++; // As� que para llevar la cuenta anotamos en el contador.
	}
	if (contarrobas == 0 && contapuntos > 1) { // Si antes de la arroba hay m�s de un punto da error = 1.
		error = 1;
		printf("\n\n\t�Email incorrecto!\n\n"); // Texto de error.
		return error;
	}
	if (contarrobas != 1) { // La condici�n final es que si hay m�s o menos de 1 arroba, me devuelve error = 1.
		error = 1;
		printf("\n\n\t�Email incorrecto!\n\n"); // Texto de error.
		return error;
	}
	if (puntoTrasArroba < 1 || puntoTrasArroba > 2) { // Si despu�s de la arroba hay m�s de dos puntos o menos de uno, da error = 1.
		error = 1;
		printf("\n\n\t�Email incorrecto!\n\n"); // Texto de error.
		return error;
	}
}

void registrar() // Funci�n que registra los usuarios. 
{
	setlocale(LC_ALL, "");
	system("CLS"); // Limpiar pantalla.

	printf("\n\n\t************************************\n\t*****   REGISTRO DE PERSONA   ******\n\t************************************\n\n\n"); // Cabecera.

	int error; // Variable de error.

	registro[i].nombre[MAX] = '\0'; // Me daba error y me cog�a datos de distintas posiciones del array de la variable del struct persona registro, as� que para arreglarlo empiezo asignando ning�n car�cter a todos los campos del array.
	do { // Bucle por si hay error, repetir el proceso.
		printf("\n\tIntroduzca su nombre: ");
		printf("\n\n\t");
		gets(registro[i].nombre); // La i es la variable contador global, empiezo en 0 y al final de la funci�n co un i+=1 subo una posici�n, pasando a la siguiente persona a registrar.
		error = errorLetras(registro[i].nombre); // Igualo error a lo que devuelve la funci�n pertinente de control de error.
		if (error == 1) { // Si hay error, vuelvo a limpiar lo que hab�a introducido y repito el bucle, hay que mantener todo limpio.
			registro[i].nombre[MAX] = '\0';
		}
	} while (error == 1); // El bucle se repite mientras haya error.

	registro[i].apellido1[MAX] = '\0'; //Es lo mismo que lo anterior para todos los campos, lo �nico que var�a son los controles de error. Nos vemos al final de la funci�n.
	do {
		printf("\n\tIntroduzca su primer apellido:");
		printf("\n\n\t");
		gets(registro[i].apellido1);
		error = errorLetras(registro[i].apellido1);
		if (error == 1) {
			registro[i].apellido1[MAX] = '\0';
		}
	} while (error == 1);

	registro[i].apellido2[MAX] = '\0';
	do {
		printf("\n\tIntroduzca su segundo apellido:");
		printf("\n\n\t");
		gets(registro[i].apellido2);
		error = errorLetras(registro[i].apellido2);
		if (error == 1) {
			registro[i].apellido2[MAX] = '\0';
		}
	} while (error == 1);

	registro[i].edad[MAX] = '\0';
	do {
		printf("\n\tIntroduzca su edad:");
		printf("\n\n\t");
		gets(registro[i].edad);
		error = errorEdad(registro[i].edad);
		if (error == 1) {
			registro[i].edad[MAX] = '\0';
		}
	} while (error == 1);

	registro[i].sexo[MAX] = '\0';
	do {
		printf("\n\tIntroduzca su sexo: H (Hombre) / M (Mujer) / O (Otro)");
		printf("\n\n\t");
		gets(registro[i].sexo);
		error = errorSexo(registro[i].sexo);
		if (error == 1) {
			registro[i].sexo[MAX] = '\0';
		}
	} while (error == 1);

	registro[i].calle[MAX] = '\0';
	do {
		printf("\n\tIntroduzca su calle:");
		printf("\n\n\t");
		gets(registro[i].calle);
		error = errorLetras(registro[i].calle);
		if (error == 1) {
			registro[i].calle[MAX] = '\0';
		}
	} while (error == 1);

	registro[i].numeroDireccion[MAX] = '\0';
	do {
		printf("\n\tIntroduzca su n�mero de calle:");
		printf("\n\n\t");
		gets(registro[i].numeroDireccion);
		error = errorNumCalle(registro[i].numeroDireccion);
		if (error == 1) {
			registro[i].numeroDireccion[MAX] = '\0';
		}
	} while (error == 1);

	registro[i].codigoPostal[MAX] = '\0';
	do {
		printf("\n\tIntroduzca su c�digo postal:");
		printf("\n\n\t");
		gets(registro[i].codigoPostal);
		error = errorCP(registro[i].codigoPostal);
		if (error == 1) {
			registro[i].codigoPostal[MAX] = '\0';
		}
	} while (error == 1);

	registro[i].localidad[MAX] = '\0';
	do {
		printf("\n\tIntroduzca su localidad:");
		printf("\n\n\t");
		gets(registro[i].localidad);
		error = errorLetras(registro[i].localidad);
		if (error == 1) {
			registro[i].localidad[MAX] = '\0';
		}
	} while (error == 1);

	registro[i].comunidad[MAX] = '\0';
	do {
		printf("\n\tIntroduzca su comunidad:");
		printf("\n\n\t");
		gets(registro[i].comunidad);
		error = errorLetras(registro[i].comunidad);
		if (error == 1) {
			registro[i].comunidad[MAX] = '\0';
		}
	} while (error == 1);

	registro[i].telefono[MAX] = '\0';
	do {
		printf("\n\tIntroduzca su n�mero de tel�fono:");
		printf("\n\n\t");
		gets(registro[i].telefono);
		error = errorTelefono(registro[i].telefono);
		if (error == 1) {
			registro[i].telefono[MAX] = '\0';
		}
	} while (error == 1);

	registro[i].email[MAX] = '\0';
	do {
		printf("\n\tIntroduzca su email:");
		printf("\n\n\t");
		gets(registro[i].email);
		error = errorEmail(registro[i].email);
		if (error == 1) {
			registro[i].email[MAX] = '\0';
		}
	} while (error == 1);

	printf("\n\n\t�Persona registrada con �xito! (Pulse Doble ENTER)"); // El doble enter es porque tengo un getchar al final de �sta funci�n y otro afuera, en la elecci�n de la opci�n en el men� para evitar problemas.
	printf("\n\t"); // Que el getchar quede alineado con la sangr�a.
	getchar();
	i += 1; // Incremento una posici�n en el array de registro.
	if (i < 10) { // Control para saber si hay ya 11 usuarios registrados ya que el numero maximo de opci�n a introducir ya son 2 d�gitos.
		masDe10 = 0;
	}
	else if (i >= 10)
		masDe10 = 1;
}

void acceder() // La funci�n para acceder a las distintas personas registradas.
{
	setlocale(LC_ALL, "");
	int error;

	do {
		system("CLS"); // Limpiar pantalla.

		printf("\n\n\t************************************\n\t********   ACCESO A DATOS  **********\n\t************************************\n\n\n"); // Cabecera.

		int j, opcion; // Variables.
		printf("\n\n\t�A qu� persona desea acceder?\n\n\n\tLISTA DE USUARIOS REGISTRADOS:\n");
		// En este bucle pido una opci�n que vendr� indicada en una lista impresa por pantalla que muestra el nombre de cada persona registrada y su c�digo de acceso. Va del 0 hasta i, que es el n�mero de usuario por el que vamos registrados.
		for (j = 0; j < i; j++)
		{
			printf("\n\t%s: Introduzca %i\n", registro[j].nombre, j);
		}
		printf("\n\n\tIntroduzca su elecci�n:");
		printf("\n\n\t");
		scanf_s("%i", &opcion); // En este caso no pongo control de error porque el c�digo ya est� super hinflado y no quiero arriesgarme a que me salga algo raro, ya lo he intentado y me peta por varios sitios. Conf�o en que el usuario no falle.
		error = errorNumOpcion(opcion);
		if (opcion > contadorRegistros) {
			printf("\n\n\tEl n�mero m�ximo de ID de usuario es %i. Vuelva a intentarlo.\n\n", contadorRegistros - 2);
			getchar();
			getchar();
			error = 1;
		}
		if (error == 0) {
			system("CLS");
			printf("\n\n     **************************************"); // Al imprimir todos los datos tiene que quedar todo pulcro y bonito, ordenado, que al usuario le sea agradable.
			printf("\n\n\tDatos de %s ", registro[opcion].nombre);
			printf("%s ", registro[opcion].apellido1);
			printf("%s", registro[opcion].apellido2);
			printf("\n\n     **************************************");
			printf("\n\n\tEdad: %s a�os.", registro[opcion].edad);
			if (registro[opcion].sexo[0] == 'H' || registro[opcion].sexo[0] == 'h') // Aqu� est�n las sentencias que me cambian las iniciales introducidas en el campo de sexo por la palabra completa (era para hacerlo m�s c�modo para el usuario).
				printf("\n\n\tSexo: Hombre.");
			else if (registro[opcion].sexo[0] == 'M' || registro[opcion].sexo[0] == 'm')
				printf("\n\n\tSexo: Mujer.");
			else if (registro[opcion].sexo[0] == 'O' || registro[opcion].sexo[0] == 'o')
				printf("\n\n\tSexo: Otro.");
			printf("\n\n\tDirecci�n: %s ", registro[opcion].calle);
			printf("%s, ", registro[opcion].numeroDireccion);
			printf("%s ", registro[opcion].codigoPostal);
			printf("%s, ", registro[opcion].localidad);
			printf("%s. ", registro[opcion].comunidad);
			printf("\n\n\tN�mero de Tel�fono: %s.", registro[opcion].telefono);
			printf("\n\n\tDirecci�n de email: %s.", registro[opcion].email);
			printf("\n\n\n\tGracias por utilizar nuestra plataforma (Pulse ENTER).\n\n\n"); // Hay que ser educados y transmitir buenas impresiones al usuario.
			getchar();
		}
	} while (error == 1);
}

void autorrellenar() // Funci�n para autorrellenar.
{
	setlocale(LC_ALL, "");
	// Persona 1.
	system("CLS"); // Limpiar pantalla.
	strcpy(registro[i].nombre, "Jaime");
	strcpy(registro[i].apellido1, "Perez");
	strcpy(registro[i].apellido2, "Santana");
	strcpy(registro[i].edad, "20");
	strcpy(registro[i].sexo, "H");
	strcpy(registro[i].calle, "Santa Barbara");
	strcpy(registro[i].numeroDireccion, "14");
	strcpy(registro[i].codigoPostal, "27032");
	strcpy(registro[i].localidad, "Moratalla");
	strcpy(registro[i].comunidad, "Region de Murcia");
	strcpy(registro[i].telefono, "673625342");
	strcpy(registro[i].email, "mazinger@yahoo.es");
	i += 1;
	// Persona 2.
	strcpy(registro[i].nombre, "Natalia");
	strcpy(registro[i].apellido1, "Soroa");
	strcpy(registro[i].apellido2, "Tabernero");
	strcpy(registro[i].edad, "20");
	strcpy(registro[i].sexo, "M");
	strcpy(registro[i].calle, "Goya");
	strcpy(registro[i].numeroDireccion, "42");
	strcpy(registro[i].codigoPostal, "23043");
	strcpy(registro[i].localidad, "Madrid");
	strcpy(registro[i].comunidad, "Comunidad de Madrid");
	strcpy(registro[i].telefono, "608084524");
	strcpy(registro[i].email, "natalia.soroa@gmail.com");
	i += 1;
	// Persona 3.
	strcpy(registro[i].nombre, "Jose Luis");
	strcpy(registro[i].apellido1, "Yosta");
	strcpy(registro[i].apellido2, "Bellosta");
	strcpy(registro[i].edad, "20");
	strcpy(registro[i].sexo, "H");
	strcpy(registro[i].calle, "San Martin");
	strcpy(registro[i].numeroDireccion, "12");
	strcpy(registro[i].codigoPostal, "28021");
	strcpy(registro[i].localidad, "Madrid");
	strcpy(registro[i].comunidad, "Comunidad de Madrid");
	strcpy(registro[i].telefono, "698374563");
	strcpy(registro[i].email, "yosta.bellosta@hotmail.com");
	i += 1;
	// Persona 4.
	strcpy(registro[i].nombre, "Mariana");
	strcpy(registro[i].apellido1, "Lapetra");
	strcpy(registro[i].apellido2, "Botas");
	strcpy(registro[i].edad, "21");
	strcpy(registro[i].sexo, "M");
	strcpy(registro[i].calle, "Peguerinos");
	strcpy(registro[i].numeroDireccion, "8");
	strcpy(registro[i].codigoPostal, "28022");
	strcpy(registro[i].localidad, "Madrid");
	strcpy(registro[i].comunidad, "Comunidad de Madrid");
	strcpy(registro[i].telefono, "608754362");
	strcpy(registro[i].email, "marianalpb@gmail.com");
	i += 1;
	// Persona 5.
	strcpy(registro[i].nombre, "Ruben");
	strcpy(registro[i].apellido1, "Doblas");
	strcpy(registro[i].apellido2, "Rubiuh");
	strcpy(registro[i].edad, "24");
	strcpy(registro[i].sexo, "H");
	strcpy(registro[i].calle, "Herrera Oria");
	strcpy(registro[i].numeroDireccion, "2");
	strcpy(registro[i].codigoPostal, "23024");
	strcpy(registro[i].localidad, "Madrid");
	strcpy(registro[i].comunidad, "Comunidad de Madrid");
	strcpy(registro[i].telefono, "690785643");
	strcpy(registro[i].email, "rubius@youtube.com");
	i += 1;
	printf("\n\n\n\tPersonas a�adidas con �xito (Pulse doble ENTER).\n\n\n\t"); // Hay que ser educados y transmitir buenas impresiones al usuario.
	getchar();
	contadorRegistros += 5;
}

void imprimirFichero()  // Aqu� est� la funcion que imprimir� a gusto y elecci�n del usuario, los datos de las personas que quiera en un ficher (se crear� en la carpeta donde est� guardado el proyecto como personas.txt).
{
	setlocale(LC_ALL, "");
	int error;
	do {
		system("CLS"); // Limpiar pantalla.

		printf("\n\n\t*******************************************\n\t****   IMPRIMIR DATOS DE UNA PERSONA   ****\n\t*******************************************\n\n\n"); // Cabecera.

		int j, opcion;
		printf("\n\n\t�Qu� persona desea imprimir en el Fichero?\n\n\n\tLISTA DE USUARIOS REGISTRADOS:\n"); // Vuelvo a imprimir por pantalla la lista de usuarios registrados y sus c�digos para imprimir los datos de cada uno.
		for (j = 0; j < i; j++)
		{
			printf("\n\t%s: Introduzca %i\n", registro[j].nombre, j);
		}
		printf("\n\n\tIntroduzca su elecci�n:");
		printf("\n\n\t");
		scanf_s("%i", &opcion); // Lo mismo que en el campo acceder.
		error = errorNumOpcion(opcion);
		if (error == 0) {
			FILE* fichero = fopen("personas.txt", "a"); // Creo y abro mi fichero como personas.txt
			if (fichero == NULL)
			{
				printf("\n\n\tNo se ha podido crear el fichero de texto.\n\n");
			}
			else if (fichero) { // En el caso de que s� que se haya podido crear.
				printf("\n\n\tFichero personas.txt con los datos de %s creado.\n\n", registro[opcion].nombre); //Imprimo por pantalla que se ha creado el fichero con los datos de la persona de la opci�n introducida.
				fprintf(fichero, "\n\n     **************************************"); // Todo tiene que quedar bien presentado.
				fprintf(fichero, "\n\n\tDatos de %s ", registro[opcion].nombre);
				fprintf(fichero, "%s ", registro[opcion].apellido1);
				fprintf(fichero, "%s", registro[opcion].apellido2);
				fprintf(fichero, "\n\n     **************************************");
				fprintf(fichero, "\n\n\tEdad: %s a�os.", registro[opcion].edad); // En este caso, como imprimimos directamente en un fichero de texto y no en consola, no importan los car�cteres raros.
				if (registro[opcion].sexo[0] == 'H' || registro[opcion].sexo[0] == 'h')
					fprintf(fichero, "\n\n\tSexo: Hombre."); // Lo mismo que en la funci�n Acceder, cambia la opci�n introducida por la palabra completa.
				else if (registro[opcion].sexo[0] == 'M' || registro[opcion].sexo[0] == 'm')
					fprintf(fichero, "\n\n\tSexo: Mujer.");
				else if (registro[opcion].sexo[0] == 'O' || registro[opcion].sexo[0] == 'o')
					fprintf(fichero, "\n\n\tSexo: Otro.");
				fprintf(fichero, "\n\n\tDirecci�n: %s ", registro[opcion].calle);
				fprintf(fichero, "%s, ", registro[opcion].numeroDireccion);
				fprintf(fichero, "%s ", registro[opcion].codigoPostal);
				fprintf(fichero, "%s, ", registro[opcion].localidad);
				fprintf(fichero, "%s. ", registro[opcion].comunidad);
				fprintf(fichero, "\n\n\tN�mero de Tel�fono: %s.", registro[opcion].telefono);
				fprintf(fichero, "\n\n\tDirecci�n de email: %s.", registro[opcion].email);
				fclose(fichero); // Cierra el fichero y se guardan los datos.
			}
			printf("\n\n\tGracias por utilizar nuestra plataforma (Pulse ENTER).\n\n\n"); // Mensaje cordial.
			getchar();
			contadorRegistros -= 1;
		}
	} while (error == 1);
}

void borrarPersona()
{
	setlocale(LC_ALL, "");
	int error;

	do {
		system("CLS"); // Limpiar pantalla.

		printf("\n\n\t*******************************************\n\t****  BORRAR DATOS DE UNA PERSONA  ****\n\t*******************************************\n\n\n"); // Cabecera.

		int j, k, opcion, aux1 = 0;; // Variables.
		printf("\n\n\t�A qu� persona desea acceder?\n\n\n\tLISTA DE USUARIOS REGISTRADOS:\n");
		// En este bucle pido una opci�n que vendr� indicada en una lista impresa por pantalla que muestra el nombre de cada persona registrada y su c�digo de acceso. Va del 0 hasta i, que es el n�mero de usuario por el que vamos registrados.
		for (j = 0; j < i; j++)
		{
			printf("\n\t%s: Introduzca %i\n", registro[j].nombre, j);
		}
		printf("\n\n\tIntroduzca su elecci�n:");
		printf("\n\n\t");
		scanf_s("%i", &opcion); // En este caso no pongo control de error porque el c�digo ya est� super hinflado y no quiero arriesgarme a que me salga algo raro, ya lo he intentado y me peta por varios sitios. Conf�o en que el usuario no falle.
		error = errorNumOpcion(opcion);

		if (error == 0) { // Si no hay error.
			for (k = opcion; k < i; k++) // En este bucle recorro todos los campos desde el que tengo que borrar y le asigno los campos de la posici�n siguiente del array de struct.
			{
				aux1 = k;
				strcpy(registro[k].nombre, registro[k + 1].nombre);
				strcpy(registro[k].apellido1, registro[k + 1].apellido1);
				strcpy(registro[k].apellido2, registro[k + 1].apellido2);
				strcpy(registro[k].edad, registro[k + 1].edad);
				strcpy(registro[k].sexo, registro[k + 1].sexo);
				strcpy(registro[k].calle, registro[k + 1].calle);
				strcpy(registro[k].numeroDireccion, registro[k + 1].numeroDireccion);
				strcpy(registro[k].codigoPostal, registro[k + 1].codigoPostal);
				strcpy(registro[k].localidad, registro[k + 1].localidad);
				strcpy(registro[k].comunidad, registro[k + 1].comunidad);
				strcpy(registro[k].telefono, registro[k + 1].telefono);
				strcpy(registro[k].email, registro[k + 1].email);
				aux1++;
			}
			//Aqu� borro toda la informaci�n de la �ltima posici�n del array de struct ya que no hace falta, est� pasada a la anterior.
			strcpy(registro[i].nombre, "\0");
			strcpy(registro[i].apellido1, "\0");
			strcpy(registro[i].apellido2, "\0");
			strcpy(registro[i].edad, "\0");
			strcpy(registro[i].sexo, "\0");
			strcpy(registro[i].calle, "\0");
			strcpy(registro[i].numeroDireccion, "\0");
			strcpy(registro[i].codigoPostal, "\0");
			strcpy(registro[i].localidad, "\0");
			strcpy(registro[i].comunidad, "\0");
			strcpy(registro[i].telefono, "\0");
			strcpy(registro[i].email, "\0");
			i -= 1; // Resto i para retroceder en el array 1 posici�n por la posici�n borrada.

			printf("\n\n\tEl usuario ha sido elminado de la base de datos con �xito(Pulse Enter).\n\n"); // Mensaje de borrado.
			getchar();
			printf("\n\n\tPulse enter para continuar.\n\n");
		}
	} while (error == 1);
	contadorRegistros -= 1;
}

void salir() // La �ltima funci�n, la funci�n que imprime una l�nea de despedida y cierra el program con exit.
{
	setlocale(LC_ALL, "");
	printf("\n\n\t�Gracias por confiar en nosotros! �Hasta la pr�xima!\n\n\n\n\n\n\t");
	system("PAUSE");
	exit(+1);
}