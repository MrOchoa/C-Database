#pragma once
#include "func.h" // Incluyo los headers.
#include "struct.h"
#include "locale.h"
#include "string.h"
#define _CRT_SECURE_NO_WARNINGS

struct persona registro[50]; // Creo mi variable de la estructura en forma de array, que será el registro de cada persona. Hay un máximo de 50 personas para registrar.
int contadorRegistros = 0; // Variable global que mantiene el número de personas registradas (he puesto 3 como máximo).
int contadorAutorrelleno = 0; // Contador del uso de la función del autorrelleno.
int i = 0; // Variable global contador para las distintas posiciones dentro del struct persona registro [i].
int primerUso = 0; //Cuenta a partir del primer uso del menú.
int masDe10 = 0; // Contador para saber si hay más de 10 usuarios registrados.
// Función del menú. Nos deja elegir entre las cuatro opciones abajo. Todo el código está pulcra y premeditadamente ordenado y estructurado para que quede bien (de ahí que haya muchos \n y \t).
char menu(char a)
{
	setlocale(LC_ALL, "");
	if (primerUso > 0) { // Si intercambiamos el plan por el bucle o el inicio del bucle cerrado, cambiamos las directrices del mismo, o las reglas.
		system("CLS");
		printf("\n\n\t************************************\n\t********  MENÚ PRINCIPAL  **********\n\t************************************\n\n\n"); // Cabecera.  
	}
	char opcion; // La opción que registraremos.
	printf("\t¿Qué desea hacer?\n\n\n\tR: Registrarse.\n\n\tA: Acceder.\n\n\tI: Imprimir en un Fichero.\n\n\tB: Borrar usuario.\n\n\tX: Autorrellenar.\n\n\tS: Salir.\n\n");
	printf("\n\t");
	scanf_s("%c", &opcion); // Recojo la opción.
	getchar();
	// Switch para considerar cada opción.
	switch (opcion) {
	case 'R':
	case 'r':
		if (contadorRegistros > 50) { // Aquí tenemos la primera condición que nos dirá que si el contador de registros supera el 3, nos imprima que se ha alcanzado el número máximo.
			printf("\n\n\tSe ha alcanzado el número máximo de Registros (Enter).\n\n\n"); // Si es así no nos dejará continuar y volveremos al menú para re-elegir opción.
			break;
		}  
		else {
			contadorRegistros++; //Si no hemos llegado al tope se incrementa el contador de registros.
			registrar(); //Llamada a la función de registrar al usuario.
			break; // Salida del bucle una vez registrado el usuario y nos lleva de nuevo al menú principal ya que no hemos introducido S o s.	
		}

	case 'A':
	case 'a':
		if (contadorRegistros < 1 || i == 0) { // En este caso si no hemos registrado a nadie todavía, no nos dejará entrar a la opción de acceso a la informaci mn ón de los usuarios registrados.
			printf("\n\n\tNo hay ningún usuario registrado en la Base de Datos (Enter).\n\n\n");
			.. 
		}
		else if (contadorRegistros >= 1) { // Sin embargo, si sí que hay usuarios registrados, nos dejará llamar a la función.
			acceder();

		}
		break;

	case 'I':
	case 'i':
		if (contadorRegistros < 1 || i == 0) { // Mismo control que en el campo de Acceder.
			printf("\n\n\tNo hay ningún usuario registrado en la Base de Datos (Enter).\n\n\n");
		}
		else if (contadorRegistros >= 1) {
			imprimirFichero(); // Llamada a la función.
		}
		break;

	case 'B':
	case 'b':
		if (i == 0) { // Mismo control que en el campo de Acceder.
			printf("\n\n\tNo hay ningún usuario para borrar (Enter).\n\n\n");
		}
		else
			borrarPersona(); // Llamada a la función.
		break;

	case 'X':
	case 'x':
		if (contadorAutorrelleno > 0) {
			printf("\n\n\tYa ha utilizado la función de Autorrelleno. Sólo puede utilizarse una vez (Pulse doble ENTER).");
			break;
		}
		else {
			contadorRegistros++;
			autorrellenar(); // Función para autorrellenar 5 personas.
			break;
		}

	case 'S':
	case 's':

		salir(); // Llamada a la función y sería el fin del programa.
		break;

	default: // Si el usuario introduce cualquier otra cosa, da error.

		printf("\n\n\t¡ERROR! Escoja otra vez (Enter).\n\n\n"); // He puesto Enter porque más abajo he puesto un getchar, es algo que el usuario tiene que introducir sí o sí, así que mejor si queda dicho disimuladamente.
		break;
	}
	a = opcion; // Sencillamente asigno el valor de la opción a a para posteriormente devolver a al main.c, donde se llamó a ésta función de menú.
	printf("\t"); // Sencillamente es para dejar la barra de texto de la consola debido al getchar de abajo en línea con la sangría.
	primerUso += 1;
	getchar(); // Para no tener problemas y limpiar el búfer.
	return a;
}

// Aquí empiezan las funciones que se encargan de comprobar si hay error en el texto introducido por el usuario. Empiezo con el control de eroor  de las palabras de texto nombre, apellidos, Calle, Localidad y Comunidad.
int errorLetras(char frase[MAX]) // Una variable que me devolverá un entero 0 o 1 ya que en todas las funciones está la variable error dentro de un bucle con condición de repetirse si se devuelve error = 1;
{
	setlocale(LC_ALL, "");
	int error = NULL; //Mi variable de error.
	for (int j = 0; frase[j] != '\0'; j++) { // Empieza el bucle que nos recorre la frase.
		if ((frase[j] >= 'a' && frase[j] <= 'z') || (frase[j] >= 'A' && frase[j] <= 'Z') || frase[j] == ' ' || frase[j] == '-') { // Mientras sean letras, espacios para nombres compuestos o - para nombres con Guión, el error será 0.
			error = 0;
			continue;
		}
		else if ((frase[j] > 00 && frase[j] < 32) || (frase[j] > 32 && frase[j] < 45) || (frase[j] > 45 && frase[j] < 65) || (frase[j] > 90 && frase[j] < 97) || frase[j] > 122) { // En todo caso contrario el error será 1.
			printf("\n\n\t¡ERROR! Ha introducido un carácter no válido.\n\n"); // Imprime la frase  de error que sera muy parecida (o igual en algunos casos) a las de otras funciones de control de error.
			error = 1;
			break;
		}
	}
	return error; // Devuelve el error como 1 o 0.
}

int errorEdad(char numero[MAX]) // Ésta función devuelve el error y recibe el número en cadena.
{
	setlocale(LC_ALL, "");
	int error;
	int j;
	for (j = 0; numero[j] != '\0'; j++) { // Recorre la cadena.
		if (numero[j] >= 48 && numero[j] <= 57) // Analiza si el caracter en la posición actual es un número o no, y si no lo esos el error es 0 y continúa.
			error = 0;
		else if (numero[j] < 48 || numero[j] > 57) { // Si no es un número da error = 1 y se sale del bucle porque ya sabemos que está mal y se vuelve de nuevo a la función de registrar al bucle donde se ha llamado a esta funcion.
			printf("\n\n\t¡ERROR! Ha introducido un carácter no válido.\n\n");
			error = 1;
			break;
		}
	}
	if (j != 2) { // Si hay más de 3 carácteres o menos de 2 (sabiendo ya que no se ha introducido ningún carácter no válido) da error ya que el rango de edad permitida está entre 10 años y 99
		printf("\n\n\t¡ERROR! La edad es incorrecta (El usuario debe ser mayor de 10 y menor de 100). Pruebe de nuevo.\n\n");
		error = 1; // Asigna 1 a error.
	}
	return error; // Devuelve el valor del error.
}

int errorNumOpcion(int numOpcion) // Ésta función devuelve el error y recibe el número en cadena.
{
	setlocale(LC_ALL, "");
	int error = 0;
	if (masDe10 == 0 && numOpcion > 10) { // Si no hay más de 10 usuarios registrados y 
		printf("\n\n\t¡ERROR! Ha introducido un número mayor al número de usuarios registrados (Pulse ENTER y pruebe de nuevo).\n\n");
		getchar();
		getchar();
		error = 1; // Asigna 1 a error.
		return error;
	}
	return error; // Devuelve el valor del error.
}
	
int errorNumCalle(char numero[MAX]) // Ésta función es igual a la anterior excepto al final.
{
	setlocale(LC_ALL, "");
	int error = NULL;
	int j;
	for (j = 0; numero[j] != '\0'; j++) {
		if (numero[j] >= 48 && numero[j] <= 57)
			error = 0;
		else if (numero[j] < 48 || numero[j] > 57) {
			printf("\n\n\t¡ERROR! Ha introducido un carácter no válido.\n\n");
			error = 1;
			break;
		}
	}
	if (j > 3) { // La calle con más números de españa la Gran Via de les Corts Catalanes con 689, con lo cual pongo el tope en 3 cifras.
		printf("\n\n\t¡ERROR! El número de calle introducido es incorrecto. Pruebe de nuevo.\n\n");
		error = 1;
	}
	return error;
}

int errorCP(char numero[MAX]) // Lo mismo que el anterior pero con una variación al final.
{
	setlocale(LC_ALL, "");
	int error;
	int j;
	for (j = 0; numero[j] != '\0'; j++) {
		if (numero[j] >= 48 && numero[j] <= 57)
			error = 0;
		else if (numero[j] < 48 || numero[j] > 57) {
			printf("\n\n\t¡ERROR! Ha introducido un carácter no válido.\n\n");
			error = 1;
			break;
		}
	}
	if (j != 5) { // Añado la condición de que si el código postal tiene menos o más de 5 dígitos nos da error, ya que los códigos postales tienen todos 5 dígitos en España.
		printf("\n\n\t¡ERROR! El Código Postal debe tener 5 números.\n\n");
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
			printf("\n\n\t¡ERROR! Ha introducido un carácter no válido.\n\n");
			error = 1;
			break;
		}
	}
	if (j != 9) { // En este caso sé que todos los números de teléfono en españa tienen 9 dígitos, así que si se han introducido menos o más de 9, da error y habrá que reintroducir el número.
		printf("\n\n\t¡ERROR! El número de teléfono es incorrecto (El número debe tener 9 dígitos). Pruebe de nuevo.\n\n");
		error = 1;
	}
	return error;
}

int errorSexo(char sexo[MAX]) // En el control de error del sexo recibimos la palabra introducida por el usuario que como se pide en el menú de arriba, debría ser sólo la inicial del sexo, luego en otra función se cambiará al completo.
{
	setlocale(LC_ALL, "");
	int error = NULL;
	int numChar = 0; // Contador de carácteres.
	for (int j = 0; sexo[j] != '\0'; j++) { //Recorre la palabra y si hay un carácter distinto a las opciones del menú da error.
		if (sexo[j] == 'H' || sexo[j] == 'h' || sexo[j] == 'M' || sexo[j] == 'm' || sexo[j] == 'O' || sexo[j] == 'o')
			error = 0;
		else if (sexo[j] != 'H' || sexo[j] != 'h' || sexo[j] != 'M' || sexo[j] != 'm' || sexo[j] != 'O' || sexo[j] != 'o') {
			printf("\n\n\t¡ERROR! Ha introducido un carácter no válido.\n\n");
			error = 1;
			break;
		}
		if (numChar > 1) { // Como sólo hay que meter la inicial, si hay más de 1 carácter, da error.
			printf("\n\n\t¡ERROR! Ha introducido más de un carácter.\n\n");
			error = 1;
			break;
		}
		numChar++; // Aquí tengo el incremento del contador de carácteres.
	}
	return error;
}

int errorEmail(char mail[MAX]) // El control de error más complejo, basado en el de los ejercicios de clase (creo que pusiste mi código en el blackboard como ejemplo de solución) y perfeccionado para este programa. 
{
	setlocale(LC_ALL, "");
	int j, contarrobas = 0, contapuntos = 0, puntoTrasArroba = 0, contaGuiones = 0, error = 0; // Variables contadores.
	for (j = 0; mail[j] != '\0'; j++) { // Recorre el email
		if (mail[j] == '@') {
			contarrobas++; // Si la posición actual es una @ se incrementa el contador de arrobas.
			if (j == 0) { // Si hay una en la posición 0, da error y sale del bucle y devuelve error al bucle de la función de registrar en el campo del email.
				error = 1;
				printf("\n\n\t¡Email incorrecto!\n\n"); // Texto de error.
				return error;
			}
		}
		if (mail[j] == '-') { // En el caso del guión se utiliza el contador si hay uno en la posición actual.
			contaGuiones++;
			if (contarrobas == 0 && contaGuiones > 1 || contarrobas == 1 && contaGuiones > 1) { // Tanto antes como después de la arroba, sólo puede haber 1 guión, si no es el caso, como dice la condición, devuelve error = 1.
				error = 1;
				printf("\n\n\t¡Email incorrecto!\n\n"); // Texto de error.
				return error;
			}
		}
		if (mail[j] == '.') { // Lo mismo para el punto.
			contapuntos++;
			if (mail[j - 1] == '@' || mail[j + 1] == '@') { // No puede haber un punto inmediatamente antes o después de una @.
				error = 1;
				printf("\n\n\t¡Email incorrecto!\n\n"); // Texto de error.
				return error;
			}
			if (mail[j - 1] == '.' || mail[j + 1] == '.') { // Tampoco puede haber un punto inmediatamente antes o después de otro punto.
				error = 1;
				printf("\n\n\t¡Email incorrecto!\n\n"); // Texto de error.
				return error;
			}
			if (j == 0 || mail[j + 1] == '\0') { // Si estando en un punto en la posición actualy resulta que estamos en la posición 0 o la última (antes del '\0') devuelve error = 1.
				error = 1;
				printf("\n\n\t¡Email incorrecto!\n\n"); // Texto de error.
				return error;
			}
		}
		if (mail[j] == '.' && contarrobas == 1) // Sigo estando con un punto en la posición actual, y si además ya ha habido una arroba antes, sólo puede haber 2 puntos tras la arroba (ej: @live.u-tad.com).
			puntoTrasArroba++; // Así que para llevar la cuenta anotamos en el contador.
	}
	if (contarrobas == 0 && contapuntos > 1) { // Si antes de la arroba hay más de un punto da error = 1.
		error = 1;
		printf("\n\n\t¡Email incorrecto!\n\n"); // Texto de error.
		return error;
	}
	if (contarrobas != 1) { // La condición final es que si hay más o menos de 1 arroba, me devuelve error = 1.
		error = 1;
		printf("\n\n\t¡Email incorrecto!\n\n"); // Texto de error.
		return error;
	}
	if (puntoTrasArroba < 1 || puntoTrasArroba > 2) { // Si después de la arroba hay más de dos puntos o menos de uno, da error = 1.
		error = 1;
		printf("\n\n\t¡Email incorrecto!\n\n"); // Texto de error.
		return error;
	}
}

void registrar() // Función que registra los usuarios. 
{
	setlocale(LC_ALL, "");
	system("CLS"); // Limpiar pantalla.

	printf("\n\n\t************************************\n\t*****   REGISTRO DE PERSONA   ******\n\t************************************\n\n\n"); // Cabecera.

	int error; // Variable de error.

	registro[i].nombre[MAX] = '\0'; // Me daba error y me cogía datos de distintas posiciones del array de la variable del struct persona registro, así que para arreglarlo empiezo asignando ningún carácter a todos los campos del array.
	do { // Bucle por si hay error, repetir el proceso.
		printf("\n\tIntroduzca su nombre: ");
		printf("\n\n\t");
		gets(registro[i].nombre); // La i es la variable contador global, empiezo en 0 y al final de la función co un i+=1 subo una posición, pasando a la siguiente persona a registrar.
		error = errorLetras(registro[i].nombre); // Igualo error a lo que devuelve la función pertinente de control de error.
		if (error == 1) { // Si hay error, vuelvo a limpiar lo que había introducido y repito el bucle, hay que mantener todo limpio.
			registro[i].nombre[MAX] = '\0';
		}
	} while (error == 1); // El bucle se repite mientras haya error.

	registro[i].apellido1[MAX] = '\0'; //Es lo mismo que lo anterior para todos los campos, lo único que varía son los controles de error. Nos vemos al final de la función.
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
		printf("\n\tIntroduzca su número de calle:");
		printf("\n\n\t");
		gets(registro[i].numeroDireccion);
		error = errorNumCalle(registro[i].numeroDireccion);
		if (error == 1) {
			registro[i].numeroDireccion[MAX] = '\0';
		}
	} while (error == 1);

	registro[i].codigoPostal[MAX] = '\0';
	do {
		printf("\n\tIntroduzca su código postal:");
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
		printf("\n\tIntroduzca su número de teléfono:");
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

	printf("\n\n\t¡Persona registrada con éxito! (Pulse Doble ENTER)"); // El doble enter es porque tengo un getchar al final de ésta función y otro afuera, en la elección de la opción en el menú para evitar problemas.
	printf("\n\t"); // Que el getchar quede alineado con la sangría.
	getchar();
	i += 1; // Incremento una posición en el array de registro.
	if (i < 10) { // Control para saber si hay ya 11 usuarios registrados ya que el numero maximo de opción a introducir ya son 2 dígitos.
		masDe10 = 0;
	}
	else if (i >= 10)
		masDe10 = 1;
}

void acceder() // La función para acceder a las distintas personas registradas.
{
	setlocale(LC_ALL, "");
	int error;

	do {
		system("CLS"); // Limpiar pantalla.

		printf("\n\n\t************************************\n\t********   ACCESO A DATOS  **********\n\t************************************\n\n\n"); // Cabecera.

		int j, opcion; // Variables.
		printf("\n\n\t¿A qué persona desea acceder?\n\n\n\tLISTA DE USUARIOS REGISTRADOS:\n");
		// En este bucle pido una opción que vendrá indicada en una lista impresa por pantalla que muestra el nombre de cada persona registrada y su código de acceso. Va del 0 hasta i, que es el número de usuario por el que vamos registrados.
		for (j = 0; j < i; j++)
		{
			printf("\n\t%s: Introduzca %i\n", registro[j].nombre, j);
		}
		printf("\n\n\tIntroduzca su elección:");
		printf("\n\n\t");
		scanf_s("%i", &opcion); // En este caso no pongo control de error porque el código ya está super hinflado y no quiero arriesgarme a que me salga algo raro, ya lo he intentado y me peta por varios sitios. Confío en que el usuario no falle.
		error = errorNumOpcion(opcion);
		if (opcion > contadorRegistros) {
			printf("\n\n\tEl número máximo de ID de usuario es %i. Vuelva a intentarlo.\n\n", contadorRegistros - 2);
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
			printf("\n\n\tEdad: %s años.", registro[opcion].edad);
			if (registro[opcion].sexo[0] == 'H' || registro[opcion].sexo[0] == 'h') // Aquí están las sentencias que me cambian las iniciales introducidas en el campo de sexo por la palabra completa (era para hacerlo más cómodo para el usuario).
				printf("\n\n\tSexo: Hombre.");
			else if (registro[opcion].sexo[0] == 'M' || registro[opcion].sexo[0] == 'm')
				printf("\n\n\tSexo: Mujer.");
			else if (registro[opcion].sexo[0] == 'O' || registro[opcion].sexo[0] == 'o')
				printf("\n\n\tSexo: Otro.");
			printf("\n\n\tDirección: %s ", registro[opcion].calle);
			printf("%s, ", registro[opcion].numeroDireccion);
			printf("%s ", registro[opcion].codigoPostal);
			printf("%s, ", registro[opcion].localidad);
			printf("%s. ", registro[opcion].comunidad);
			printf("\n\n\tNúmero de Teléfono: %s.", registro[opcion].telefono);
			printf("\n\n\tDirección de email: %s.", registro[opcion].email);
			printf("\n\n\n\tGracias por utilizar nuestra plataforma (Pulse ENTER).\n\n\n"); // Hay que ser educados y transmitir buenas impresiones al usuario.
			getchar();
		}
	} while (error == 1);
}

void autorrellenar() // Función para autorrellenar.
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
	printf("\n\n\n\tPersonas añadidas con éxito (Pulse doble ENTER).\n\n\n\t"); // Hay que ser educados y transmitir buenas impresiones al usuario.
	getchar();
	contadorRegistros += 5;
}

void imprimirFichero()  // Aquí está la funcion que imprimirá a gusto y elección del usuario, los datos de las personas que quiera en un ficher (se creará en la carpeta donde está guardado el proyecto como personas.txt).
{
	setlocale(LC_ALL, "");
	int error;
	do {
		system("CLS"); // Limpiar pantalla.

		printf("\n\n\t*******************************************\n\t****   IMPRIMIR DATOS DE UNA PERSONA   ****\n\t*******************************************\n\n\n"); // Cabecera.

		int j, opcion;
		printf("\n\n\t¿Qué persona desea imprimir en el Fichero?\n\n\n\tLISTA DE USUARIOS REGISTRADOS:\n"); // Vuelvo a imprimir por pantalla la lista de usuarios registrados y sus códigos para imprimir los datos de cada uno.
		for (j = 0; j < i; j++)
		{
			printf("\n\t%s: Introduzca %i\n", registro[j].nombre, j);
		}
		printf("\n\n\tIntroduzca su elección:");
		printf("\n\n\t");
		scanf_s("%i", &opcion); // Lo mismo que en el campo acceder.
		error = errorNumOpcion(opcion);
		if (error == 0) {
			FILE* fichero = fopen("personas.txt", "a"); // Creo y abro mi fichero como personas.txt
			if (fichero == NULL)
			{
				printf("\n\n\tNo se ha podido crear el fichero de texto.\n\n");
			}
			else if (fichero) { // En el caso de que sí que se haya podido crear.
				printf("\n\n\tFichero personas.txt con los datos de %s creado.\n\n", registro[opcion].nombre); //Imprimo por pantalla que se ha creado el fichero con los datos de la persona de la opción introducida.
				fprintf(fichero, "\n\n     **************************************"); // Todo tiene que quedar bien presentado.
				fprintf(fichero, "\n\n\tDatos de %s ", registro[opcion].nombre);
				fprintf(fichero, "%s ", registro[opcion].apellido1);
				fprintf(fichero, "%s", registro[opcion].apellido2);
				fprintf(fichero, "\n\n     **************************************");
				fprintf(fichero, "\n\n\tEdad: %s años.", registro[opcion].edad); // En este caso, como imprimimos directamente en un fichero de texto y no en consola, no importan los carácteres raros.
				if (registro[opcion].sexo[0] == 'H' || registro[opcion].sexo[0] == 'h')
					fprintf(fichero, "\n\n\tSexo: Hombre."); // Lo mismo que en la función Acceder, cambia la opción introducida por la palabra completa.
				else if (registro[opcion].sexo[0] == 'M' || registro[opcion].sexo[0] == 'm')
					fprintf(fichero, "\n\n\tSexo: Mujer.");
				else if (registro[opcion].sexo[0] == 'O' || registro[opcion].sexo[0] == 'o')
					fprintf(fichero, "\n\n\tSexo: Otro.");
				fprintf(fichero, "\n\n\tDirección: %s ", registro[opcion].calle);
				fprintf(fichero, "%s, ", registro[opcion].numeroDireccion);
				fprintf(fichero, "%s ", registro[opcion].codigoPostal);
				fprintf(fichero, "%s, ", registro[opcion].localidad);
				fprintf(fichero, "%s. ", registro[opcion].comunidad);
				fprintf(fichero, "\n\n\tNúmero de Teléfono: %s.", registro[opcion].telefono);
				fprintf(fichero, "\n\n\tDirección de email: %s.", registro[opcion].email);
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
		printf("\n\n\t¿A qué persona desea acceder?\n\n\n\tLISTA DE USUARIOS REGISTRADOS:\n");
		// En este bucle pido una opción que vendrá indicada en una lista impresa por pantalla que muestra el nombre de cada persona registrada y su código de acceso. Va del 0 hasta i, que es el número de usuario por el que vamos registrados.
		for (j = 0; j < i; j++)
		{
			printf("\n\t%s: Introduzca %i\n", registro[j].nombre, j);
		}
		printf("\n\n\tIntroduzca su elección:");
		printf("\n\n\t");
		scanf_s("%i", &opcion); // En este caso no pongo control de error porque el código ya está super hinflado y no quiero arriesgarme a que me salga algo raro, ya lo he intentado y me peta por varios sitios. Confío en que el usuario no falle.
		error = errorNumOpcion(opcion);

		if (error == 0) { // Si no hay error.
			for (k = opcion; k < i; k++) // En este bucle recorro todos los campos desde el que tengo que borrar y le asigno los campos de la posición siguiente del array de struct.
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
			//Aquí borro toda la información de la última posición del array de struct ya que no hace falta, está pasada a la anterior.
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
			i -= 1; // Resto i para retroceder en el array 1 posición por la posición borrada.

			printf("\n\n\tEl usuario ha sido elminado de la base de datos con éxito(Pulse Enter).\n\n"); // Mensaje de borrado.
			getchar();
			printf("\n\n\tPulse enter para continuar.\n\n");
		}
	} while (error == 1);
	contadorRegistros -= 1;
}

void salir() // La última función, la función que imprime una línea de despedida y cierra el program con exit.
{
	setlocale(LC_ALL, "");
	printf("\n\n\t¡Gracias por confiar en nosotros! ¡Hasta la próxima!\n\n\n\n\n\n\t");
	system("PAUSE");
	exit(+1);
}