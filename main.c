#include <ctype.h>  // Incluye funciones para clasificacion de caracteres (ej: isalpha, isdigit).
#include <stdio.h>  // Incluye funciones estandar de entrada/salida (ej: printf, scanf).
#include <stdlib.h> // Incluye funciones de utilidad general (ej: malloc, exit).
#include <string.h> // Incluye funciones de manipulacion de cadenas (ej: strcpy, strcmp).
#include <math.h>   // Incluye funciones matematicas (ej: sqrt, sin, cos).

#define MAX_WORDS 5    // Define una constante para el numero maximo de palabras que se pueden almacenar para el ejercicio de Ordenacion de palabras.
#define MAX_LENGTH 21  // Define una constante para la longitud maxima de una palabra o cadena (incluyendo el terminador nulo '\0').


typedef struct {                // Define un nuevo tipo llamado "Employee" que es una estructura.
    char name[21];              // Almacena el nombre del empleado.
    char surname[2][21];        // Almacena los dos apellidos del empleado.
    int employeeCode;           // Almacena el codigo del empleado (entero).
    struct {                    // Estructura anidada para guardar los detalles del puesto.
        char name[21];          // Almacena el nombre del puesto.
        char studies[21];       // Almacena los estudios requeridos para el puesto.
        float salary;           // Almacena el salario para el puesto.
    } position;                 // Fin de la definición de la estructura anidada "position". "position" es el nombre de la variable de tipo struct anidada dentro de Employee.
} Employee;                     // Define una estructura llamada Employee para almacenar la informacion del empleado.


// Declaraciones de funciones (prototipos):

void chooseOption(int *optionNumber);           // Pide al usuario que elija una opcion y la guarda en optionNumber.

int validateNumbers(char chain[MAX_LENGTH]);    // Valida si una cadena contiene solo numeros.

void chooseOperation(int *operationSelected);   // Pide al usuario que elija una operacion de matrices.
void readMatrix(double (*matrix)[2]);           // Lee una matriz 2x2 desde el usuario.
void printMatrix(double (*matrix)[2]);          // Imprime una matriz 2x2.
void sumMatrix(double (*matrixA)[2], double (*matrixB)[2], double (*sum)[2]); // Suma dos matrices 2x2.
void transposeMatrix(double matrix[2][2], double (*transposed)[2]);           // Transpone una matriz 2x2.

void readEmployee(Employee *employee); // Lee los datos de un empleado.
void printEmployee(Employee *employee); // Imprime los datos de un empleado.

void chooseOrder(int *orderSelected); // Pide al usuario que elija un tipo de orden para las palabras.
void readWords(char words[MAX_WORDS][MAX_LENGTH]);  // Lee varias palabras del usuario.
void printWords(char words[MAX_WORDS][MAX_LENGTH]); // Imprime las palabras almacenadas.
void orderWords(int orderSelected, char words[MAX_WORDS][MAX_LENGTH]); // Ordena las palabras segun la seleccion del usuario.

void selectConversion (int *conversionSelected); // Pide al usuario que elija un tipo de conversion.
void cartesianToPolar(double x, double y, double *r, double *theta); // Convierte coordenadas cartesianas a polares.
void polarToCartesian(double r, double theta, double *x, double *y); // Convierte coordenadas polares a cartesianas.
int validateDecimals(char chain[MAX_LENGTH]); // Valida si una cadena contiene solo numeros (incluidos los decimales y negativos).
void readCoordenates(double *coordenate); //Lee un numero decimal.
void printResults(double x, double y, double r, double theta, int conversionSelected); // Imprime los resultados de las conversiones del ejercicio 4.


int main(void) {

    int optionNumber; // Variable para almacenar el numero de opcion del menu principal.

    chooseOption(&optionNumber); // Llama a la funcion para que el usuario elija una opcion del menu principal.

    printf("Seleccionaste la opcion %d\n", optionNumber); // Imprime la opcion seleccionada por el usuario.

    switch (optionNumber) { // Comienza una estructura switch para ejecutar diferentes bloques de codigo segun la opcion elegida.
        case 1: // Caso 1: Operaciones con matrices.

            int operationSelected; // Variable para almacenar la operacion de matriz seleccionada

            chooseOperation(&operationSelected); // Llama a la funcion para que el usuario elija una operacion con matrices

            double matrixA[2][2]; // Declara una matriz A de 2x2
            double matrixB[2][2]; // Declara una matriz B de 2x2

            if (operationSelected != 3) { // Si la operacion no es "salir" (opcion 3)
                printf("\nIngresa los elementos de una matriz\n2x2, fila por fila,"
                           "separados dentro de cada fila por espacio.\n\n"); // Pide al usuario que ingrese los elementos de la matriz A.
                readMatrix(matrixA); // Llama a la funcion para leer la matriz A desde la entrada del usuario.
                printf("Ahora ingresa la segunda matriz.\n"); // Pide al usuario que ingrese los elementos de la matriz B.
                readMatrix(matrixB); // Llama a la funcion para leer la matriz B desde la entrada del usuario.
            }

            switch (operationSelected) { // Comienza una estructura switch para ejecutar diferentes operaciones con matrices.

                case 1: // Caso 1: Suma de matrices.
                    double sum[2][2]; // Declara una matriz para almacenar la suma.
                    sumMatrix(matrixA, matrixB, sum); // Llama a la función para sumar las matrices A y B, y guardar el resultado en sum.

                    printf("La suma de las matrices A:\n"); // Imprime un mensaje indicando la matriz A.
                    printMatrix(matrixA); // Imprime la matriz A.

                    printf("y B:\n");  // Imprime un mensaje indicando la matriz B.
                    printMatrix(matrixB); // Imprime la matriz B.

                    printf("es:\n"); // Imprime un mensaje indicando la matriz suma.
                    printMatrix(sum); // Imprime la matriz suma.

                    printf("Gracias por utilizar el programa. Hasta pronto."); // Mensaje de despedida.
                    break;

                case 2: // Caso 2: Transposicion de matrices.
                    double transposedA[2][2]; // Declara una matriz para almacenar la transpuesta de A.
                    double transposedB[2][2]; // Declara una matriz para almacenar la transpuesta de B.
                    transposeMatrix(matrixA, transposedA); // Llama a la funcion para transponer la matriz A.
                    transposeMatrix(matrixB, transposedB); // Llama a la funcion para transponer la matriz B.

                    printf("La transposicion de las matrices A:\n");
                    printMatrix(matrixA); // Imprime la matriz A

                    printf("y B:\n");
                    printMatrix(matrixB); // Imprime la matriz B

                    printf("son At:\n");
                    printMatrix(transposedA); // Imprime la matriz transpuesta de A
                    printf("y Bt:\n");
                    printMatrix(transposedB); // Imprime la matriz transpuesta de B

                    printf("Gracias por utilizar el programa. Hasta pronto."); // Mensaje de despedida cuando termina la operacion
                    break;

                case 3:
                    printf("Gracias por utilizar el programa. Hasta pronto."); // Mensaje de despedida si el usuario elije la opcion salir.
                break;

                default: // Caso por defecto: Por si hay algun error inesperado.
                    printf("Lo siento, ha habido un error. Fin del programa.\n");
            }

            break; // Sale del caso 1 del switch principal

        case 2: // Caso 2: Registro de empleado.

            printf("\nVamos a rellenar la ficha de un o una empleada\n"); // Mensaje informativo

            Employee employee; // Declara una variable de tipo Employee (el tipo esta definido al principio del programa)

            readEmployee(&employee); // Llama a la funcion para leer la informacion del empleado.
            printEmployee(&employee); // Llama a la funcion para imprimir la informacion del empleado.
            break; // Sale del caso 2

        case 3: // Caso 3: Ordenacion de palabras.

            int orderSelected; // Declara una variable entera para almacenar la opcion de ordenacion seleccionada por el usuario.

            chooseOrder(&orderSelected); // Llama a la funcion chooseOrder para que el usuario elija el tipo de ordenacion (ascendente, descendente o salir). Se pasa la dirección de memoria de orderSelected para modificar su valor.

            char words[MAX_WORDS][MAX_LENGTH]; // Declara un array bidimensional de caracteres para almacenar las palabras. MAX_WORDS define el numero maximo de palabras y MAX_LENGTH la longitud maxima de cada palabra.
            if (orderSelected != 3) { // Verifica si la opcion seleccionada no es la de salir (caso 3).
                readWords(words); // Si no es salir, llama a la funcion readWords para leer las palabras del usuario y almacenarlas en el array words.
            }

            switch (orderSelected) { // Inicia una estructura switch para ejecutar diferentes acciones segun la opcion de ordenacion seleccionada.
                case 1: // Caso 1: Ordenacion ascendente.
                case 2: // Caso 2: Ordenacion descendente. (Ambos casos comparten el mismo bloque de codigo)
                    orderWords(orderSelected, words); // Llama a la funcion orderWords para ordenar las palabras segun la opción seleccionada (1 o 2).
                    printWords(words); // Llama a la funcion printWords para imprimir las palabras ordenadas.
                    break; // Sale del switch despues de ejecutar el caso 1 o 2.

                case 3: // Caso 3: El usuario elige salir del programa.
                    printf("Gracias por utilizar el programa. Hasta pronto."); // Imprime un mensaje de despedida.
                return 0; // Termina la ejecución del programa con código de salida 0 (exito).

                default: // Caso default: Se ejecuta si la opcion seleccionada no coincide con ninguno de los casos anteriores (error).
                    printf("Lo siento, ha habido un error. Fin del programa.\n"); // Imprime un mensaje de error.
            }

        break; // Sale del case 3 del switch principal.

        case 4:  // Caso 4: Conversion de coordenadas
            int conversionSelected; // Declara una variable para almacenar la opcion de conversion seleccionada
            selectConversion(&conversionSelected); // Llama a la funcion para que el usuario seleccione el tipo de conversion.

            double x, y, r, theta; // Declara variables para las coordenadas cartesianas (x, y) y polares (r, theta)

            switch (conversionSelected) { // Comienza un switch anidado basado en la opcion de conversion.

                case 1: // Caso 1: Conversion de coordenadas cartesianas a polares
                    printf("Ingresa la coordenada cartesiana x: ");
                    readCoordenates(&x); // Lee la coordenada x ingresada por el usuario
                    printf("Ingresa la coordenada cartesiana y: ");
                    readCoordenates(&y); // Lee la coordenada y ingresada por el usuario
                    cartesianToPolar(x, y, &r, &theta); // Llama a la funcion para realizar la conversion de cartesianas a polares
                    printResults(x, y, r, theta, conversionSelected); // Imprime los resultados de la conversion
                    break;

                case 2: // Caso 2: Conversion de coordenadas polares a cartesianas
                    printf("Ingresa la coordenada polar r: ");
                    readCoordenates(&r); // Lee la coordenada r ingresada por el usuario.
                    printf("Ingresa la coordenada polar theta: ");
                    readCoordenates(&theta); // Lee la coordenada theta ingresada por el usuario.
                    polarToCartesian(r, theta, &x, &y); // Llama a la funcion para realizar la conversion de polares a cartesianas.
                    printResults(x, y, r, theta, conversionSelected); // Imprime los resultados de la conversion
                    break;

                case 3: // Caso 5: Salida del programa
                    printf("Gracias por utilizar el programa. Hasta pronto.");
                    break;
            } // Cierra el switch anidado.

            break; // Sale del caso 4 del switch principal.

        case 5: // Caso 5: Salida del programa.
            printf("Gracias por utilizar el programa. Hasta pronto."); // Imprime un mensaje de despedida.
            break;

        default: // Caso por defecto: Manejo de errores
            printf("Lo siento, ha habido un error. Fin del programa.\n");
         } // Cierra el switch principal.
    return 0; // Retorna 0 para indicar que el programa finalizó correctamente.
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////FUNCIONES GENERALES:

// Funcion para validar si una cadena contiene solo digitos numericos.
int validateNumbers(char chain[MAX_LENGTH]) {
    // Primero itera a traves de cada caracter de la cadena.
    for (int i = 0; i < strlen(chain); i++) {
        // isdigit() es una funcion de la biblioteca <ctype.h> que verifica si un caracter es un digito (0-9).
        // Si el caracter actual (chain[i]) NO es un digito (!isdigit(...)), La funcion retorna 0, indicando
        // que la cadena NO es valida porque contiene al menos un caracter no numerico.
        if (!isdigit(chain[i])) {
            return 0;
        }
    }
    // Si el bucle 'for' se completa sin encontrar ningun caracter no numerico,
    // significa que todos los caracteres de la cadena son dígitos.
    // En este caso, la funcion retorna 1, indicando que la cadena es valida.
    return 1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////FUNCIONES DEL MENU PRINCIPAL:

// Funcion para que el usuario elija una opcion del menu principal.
void chooseOption( int *optionNumber) { // Recibe un puntero a un entero (*optionNumber) para modificar
    // la variable que almacena la opcion elegida en la funcion que la llama.
    char optionSelected[MAX_LENGTH];

    printf("\n");
    printf("Hola :)\n\n");
    printf("Escribe la opcion que quieras:\n\n"); // Pide al usuario que elija una opcion.

    do { // Bucle do-while para repetir el menu hasta que el usuario ingrese una opcion valida.
        printf("Opcion 1: Calculadora de matrices\n");
        printf("Opcion 2: Ficha de empleado\n");
        printf("Opcion 3: Ordenacion de palabras\n");
        printf("Opcion 4: Conversion de coordenadas\n");
        printf("Opcion 5: Salir del programa\n\n");


        do { // Bucle do-while interno para la validacion de la entrada que escribe el usuario.
            printf("Ingresa la opcion: "); // Pide al usuario que ingrese una opcion.
            fgets(optionSelected, MAX_LENGTH, stdin); // Lee la entrada del usuario, incluyendo espacios, y la guarda en optionSelected.
            // fgets es más seguro que scanf para evitar desbordamientos de buffer.

            optionSelected[strcspn(optionSelected, "\n")] = '\0'; // Elimina el caracter de nueva linea ('\n') que
            // fgets puede dejar al final de la cadena. strcspn encuentra la primera ocurrencia de '\n' y devuelve su indice, para que despues el
            // valor a ese indice sea igual a nulo ('\0')

            if (!validateNumbers(optionSelected) || strlen(optionSelected) > 1) { // Valida si la entrada contiene solo numeros y si es de longitud 1.
                printf("Solamente se puede introducir un numero.\n"); // Mensaje de error para el usuario si la entrada no es valida.
                *optionNumber = 0; // Asigna 0 a *optionNumber para que el bucle interno se repita.
            } else { // Si la entrada es un numero de un solo digito, convierte la cadena a un entero usando atoi() y lo guarda en la variable apuntada por optionNumber.
                *optionNumber = atoi(optionSelected);
            }
        } while (*optionNumber == 0); // // El bucle interno se repite mientras *optionNumber sea 0 (es decir, mientras la entrada no sea un numero valido).

        if (*optionNumber < 1 || *optionNumber > 5) { // Valida si el numero ingresado esta dentro del rango de opciones validas (1-5).
            printf("Opcion no valida. Por favor, ingresa una opcion entre 1 y 5.\n"); // Mensaje de error si la opcion no es valida.
        }

    } while (*optionNumber < 1 || *optionNumber > 5); // El bucle externo se repite mientras la opcion no este dentro del rango valido.

}

////////////////////////////////////////////////////////////////////////////////////////////////////
////FUNCIONES DE LA OPCION 1 - Calculadora de matrices:

// Funcion para que el usuario elija una opcion del menu del ejercicio 1. Es exactamente igual a la función chooseOption, solo que apunta a otra variable y pone otras condiciones numericas:
void chooseOperation(int *operationSelected) {

    char introducedOption[MAX_LENGTH];

    do {
        printf("Elige una de las dos operaciones con matrices: \n\n");
        printf("Opcion 1: Suma de matrices\n");
        printf("Opcion 2: Transposicion de matrices: \n");
        printf("Opcion 3: Salir del programa: \n\n");
        do {
            printf("Ingresa la opcion: ");
            fgets(introducedOption, MAX_LENGTH, stdin);

            introducedOption[strcspn(introducedOption, "\n")] = '\0';

            if (!validateNumbers(introducedOption) || strlen(introducedOption) > 1) {
                printf("Solamente se puede introducir un numero.\n");
                *operationSelected = 0;
            } else {
                *operationSelected = atoi(introducedOption);
            }
        } while (*operationSelected == 0);

        if (*operationSelected < 1 || *operationSelected > 3) {
            printf("Opcion no valida. Por favor, ingresa la primera, la segunda o la tercera opcion.\n");
        }

    } while (*operationSelected < 1 || *operationSelected > 3);
}

// Funcion para leer una matriz 2x2 desde la entrada estandar (teclado).
// Recibe un puntero a un array de 2 elementos de tipo double (*matrix)[2] (el definido en la funcion main(void)
// Esto permite modificar directamente la matriz original.
void readMatrix(double (*matrix)[2]) {

    printf("Ingresa la primera fila (dejando un espacio entre los dos numeros): \n"); // Pide al usuario que ingrese la primera fila de la matriz.

    // Bucle while para la validacion de la entrada de la primera fila.
    // scanf intenta leer dos numeros de punto flotante de precision doble (%lf).
    // El bucle continua mientras scanf no lea correctamente dos numeros (es decir, devuelve un valor diferente de 2).
    while (scanf("%lf %lf", &matrix[0][0], &matrix[0][1]) != 2) {
        printf("Error: Ingresa la primera fila: \n"); // Mensaje de error si la entrada no es valida.
        while (getchar() != '\n'); // Limpia el buffer de entrada para evitar un bucle infinito en caso de entrada incorrecta.
        // getchar() lee un caracter del buffer de entrada.
        // El bucle while (getchar() != '\n') lee y descarta todos los caracteres restantes en la linea,
        // incluyendo cualquier caracter no numerico que haya causado el fallo de scanf, hasta encontrar un salto de linea ('\n').
    }

    // A continuacion se procede con la segunda fila igual que con la primera:
    printf("Ahora la segunda fila (dejando un espacio entre los dos numeros): \n");

    while (scanf("%lf %lf", &matrix[1][0], &matrix[1][1]) != 2) {
        printf("Error: Ingresa la segunda fila: \n");
        while (getchar() != '\n');
    }
}

// Funcion para imprimir una matriz 2x2 de numeros de punto flotante.
// Recibe un puntero al array de 2 elementos de tipo double que definimos en la funcion main(void).
void printMatrix(double (*matrix)[2]) {
    // "%8.4f": Especificador de formato.
    //    - %f: Indica que se va a imprimir un numero de punto flotante.
    //    - 8: Indica que se reservaran 8 espacios en total para el numero. Si el numero ocupa menos de 8 espacios, se rellenara con espacios en blanco a la izquierda.
    // "\n": Caracter de nueva linea para pasar a la siguiente linea en la salida.
    printf("%8.4f %8.4f\n", matrix[0][0], matrix[0][1]);
    // Imprime la segunda fila de la matriz, usando el mismo formato.
    // "\n\n": Dos caracteres de nueva linea para dejar una linea en blanco despues de la matriz.
    printf("%8.4f %8.4f\n\n", matrix[1][0], matrix[1][1]);
}

// Funcion para sumar dos matrices 2x2.
// Recibe:
//   - matrixA: La primera matriz (pasada como array bidimensional).
//   - matrixB: La segunda matriz (pasada como array bidimensional).
//   - sum: Un puntero a un array de 2 elementos de tipo double (*sum)[2], donde se almacenara el resultado de la suma.
void sumMatrix(double (matrixA)[2][2], double matrixB[2][2], double (*sum)[2]) {
    // Suma los elementos correspondientes de matrixA y matrixB y los guarda en la matriz sum, uno por uno:
    sum[0][0] = matrixA[0][0] + matrixB[0][0];
    sum[0][1] = matrixA[0][1] + matrixB[0][1];
    sum[1][0] = matrixA[1][0] + matrixB[1][0];
    sum[1][1] = matrixA[1][1] + matrixB[1][1];
}

// Funcion para transponer una matriz 2x2.
// Recibe:
//   - matrix: La matriz original (pasada como array bidimensional).
//   - transposed: Un puntero a un array de 2 elementos de tipo double (*transposed)[2], donde se almacenara la matriz transpuesta.
void transposeMatrix(double matrix[2][2], double (*transposed)[2]) {
    // A continuacion se van introduciendo los numeros de la matriz original a los lugares correspondientes de la matriz 'transposed' para conseguir la transpuesta de la matriz original.
    transposed[0][0] = matrix[0][0];
    transposed[0][1] = matrix[1][0];
    transposed[1][0] = matrix[0][1];
    transposed[1][1] = matrix[1][1];
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////FUNCIONES DE LA OPCION 2 - Ficha de empleado:

void readEmployee(Employee *employee) {
    // Bucle para leer el nombre del empleado, validando la longitud.
    do {
        printf("Ingresa su nombre: "); // Pide al usuario que ingrese el nombre.
        scanf("%21s", employee->name); // Lee el nombre, con un maximo de 20 caracteres + el caracter nulo '\0'. El %21s previene el desbordamiento del buffer.
        while (getchar() != '\n'); // Limpia el buffer de entrada para evitar problemas con lecturas posteriores. Consume cualquier caracter restante, incluyendo el '\n'.
        if (strlen(employee->name) > 20) { // Verifica si la longitud del nombre excede 20 caracteres.
            printf("El nombre supera los 20 caracteres.\n"); // Mensaje de error si el nombre es demasiado largo.
        }
    } while (strlen(employee->name) > 20); // Repite si el nombre excede la longitud.

    // Bucle para leer los apellidos del empleado, validando la longitud de ambos.
    do {
        printf("Ingresa sus apellidos (separados por un espacio): "); // Pide al usuario que ingrese los apellidos.
        scanf("%21s %21s", employee->surname[0], employee->surname[1]); // Lee como maximo 20 caracteres + el nulo para cada apellido
        while (getchar() != '\n'); // Limpia el buffer de entrada
        if (strlen(employee->surname[0]) > 20 || strlen(employee->surname[1]) > 20) { // Verifica si alguno de los apellidos excede los 20 caracteres
            printf("Uno de los apellidos supera los 20 caracteres.\n"); // Mensaje de error
        }
    } while (strlen(employee->surname[0]) > 20 || strlen(employee->surname[1]) > 20); // Repite si algun apellido excede la longitud

    int codeResult;
    // Bucle para leer el codigo de empleado, validando la entrada (que sea un entero)
    do {
        printf("Ingrese el codigo de empleado: ");
        codeResult = scanf("%d", &employee->employeeCode); // Intenta leer un entero y lo almacena en employee->employeeCode. Asigna el numero de items leidos exitosamente a codeResult.
        if (codeResult != 1) { //Verifica si scanf leyo correctamente un entero. Si no se ingresa un entero, scanf devuelve 0.
            printf("Por favor escribe solo numeros\n"); // Mensaje de error si no se ingresa un numero.
            while (getchar() != '\n'); // Limpia el buffer de entrada para descartar la entrada incorrecta.
        }
    } while (codeResult != 1); // Repite el bucle si no se ingreso un entero valido.

    do {
        printf("Ingresa el nombre del puesto (sin espacios): "); // Pide al usuario que ingrese el nombre del puesto.
        scanf("%21s", employee->position.name); // Lee el nombre del puesto, con un maximo de 20 caracteres + '\0'
        while (getchar() != '\n'); // Limpia el buffer de entrada.
        if (strlen(employee->position.name) > 20) { // Verifica si el nombre del puesto excede los 20 caracteres.
            printf("El nombre supera los 20 caracteres.\n"); // Mensaje de error.
        }
    } while (strlen(employee->position.name) > 20); // Repite si el nombre excede la longitud.

    // Bucle do-while para la lectura y validacion de los estudios del puesto.
    do {
        printf("Ingresa los estudios del puesto (sin espacios): "); // Pide al usuario que ingrese los estudios.
        scanf("%21s", employee->position.studies); // Lee los estudios del puesto, con un maximo de 20 caracteres + '\0'
        while (getchar() != '\n'); // Limpia el buffer de entrada.
        if (strlen(employee->position.studies) > 20) { // Verifica si los estudios exceden los 20 caracteres.
            printf("El nombre supera los 20 caracteres.\n"); // Repite si los estudios exceden la longitud.
        }
    } while (strlen(employee->position.studies) > 20);

    int salaryResult;
    // Bucle do-while para la lectura y validacion del sueldo del puesto.
    do {
        printf("Ingresa el sueldo del puesto: "); // Pide al usuario que ingrese el sueldo.
        salaryResult = scanf("%f", &employee->position.salary); // Intenta leer un flotante y lo almacena en employee->position.salary. Asigna el numero de items leidos a salaryResult.
        if (salaryResult != 1) { // Verifica si scanf leyó correctamente un flotante.
            printf("Por favor escribe solo numeros\n"); // Mensaje de error si no se ingresa un numero valido.
            while (getchar() != '\n');
        }
    } while (salaryResult != 1); // Repite si no se ingreso un flotante valido.

    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Limpia cualquier carácter restante en el buffer de entrada,
    //incluyendo posibles entradas erroneas que queden luego de los scanf anteriores o en caso de que el usuario
    //ingrese mas datos de los que se le piden. EOF (End Of File) se incluye para robustez en caso de lectura desde un archivo.
}

void printEmployee(Employee *employee) {
    // Imprime un encabezado para la información del empleado.
    printf("\nLos datos del o la empleada son:\n\n");

    // Imprime los datos del empleado de forma ordenada gracias a los saltos de pagina ('\n')
    printf("Nombre: %s\n", employee->name); // %s es el especificador de formato para cadenas de caracteres (strings).
    printf("Apellidos: %s %s\n", employee->surname[0], employee->surname[1]);// Imprime los apellidos del empleado usando el miembro 'surname' (que es un array) de la estructura 'employee'
    printf("Codigo de empleado: %d\n", employee->employeeCode);
    printf("\nPuesto:\n\n"); // Imprime un encabezado para la información del puesto del empleado
    printf("Nombre: %s\n", employee->position.name);  // Imprime el nombre del puesto usando el miembro 'name' dentro de la estructura anidada 'position' de la estructura 'employee'
    printf("Estudios del puesto: %s\n", employee->position.studies); // Imprime los estudios del puesto usando el miembro 'studies' dentro de la estructura anidada 'position' de la estructura 'employee'
    printf("Sueldo del puesto: %.2f\n", employee->position.salary); // %.2f es el especificador de formato para numeros de punto flotante con dos decimales.

}

////////////////////////////////////////////////////////////////////////////////////////////////////
////FUNCIONES DE LA OPCION 3 - Ordenacion de palabras:

// Funcion para que el usuario elija una opcion del menu del ejercicio 3. Es exactamente igual a la funcion chooseOption, solo que apunta a otra variable y pone otras condiciones numericas:
void chooseOrder(int *orderSelected) {
    char introducedOrder[MAX_LENGTH];

    do {
        printf("Elige un orden para tus palabras: \n\n");
        printf("Opcion 1: Creciente\n");
        printf("Opcion 2: Decreciente \n");
        printf("Opcion 3: Salir del programa: \n\n");

        do {
            printf("Ingresa la opcion: ");
            fgets(introducedOrder, MAX_LENGTH, stdin);

            introducedOrder[strcspn(introducedOrder, "\n")] = '\0';

            if (!validateNumbers(introducedOrder) || strlen(introducedOrder) > 1) {
                printf("Solamente se puede introducir un numero.\n");
                *orderSelected = 0;
            } else {
                *orderSelected = atoi(introducedOrder);
            }
        } while (*orderSelected == 0);

        if (*orderSelected < 1 || *orderSelected > 3) {
            printf("Opcion no valida. Por favor, ingresa la primera, la segunda o la tercera opcion.\n");
        }

    } while (*orderSelected < 1 || *orderSelected > 3);
}

void readWords(char words[MAX_WORDS][MAX_LENGTH]) {

    while (getchar() != '\n'); // Esta expresion descarta los elementos leidos,
    //para que no quede nada en el buffer. Si quedara algo, un espacio o lo que sea,
    //así es como se rellenaría la primera palabra antes de que podamos los usuarios introducir ninguna palabra.

    //A partir de aqui, vamos loopeando palabra por palabra, para rellenarla con lo que introduzcamos y para
    // que se valide que sea correcto lo que introducimos. 1 - que no se introduzca una palabra vacia, 2 - que no se
    // introduzca una palabra mayor de 20 caracteres, 3 - que no haya espacios en la palabra, ni antes ni durante ni despues.
    for (int i = 0; i < MAX_WORDS; i++) {

        // Creamos una variable que hara que pasemos a la siguiente palabra siempre y cuando este correcta.
        int valid = 0;

        //Creamos un buffer temporal para que el fgets no rompa palabras mas largas de 40 caracteres y los trozos los vaya
        //distribuyendo entres las restantes palabras
        char buffer[MAX_LENGTH * 2];

        //Aqui comienza el bucle de las validaciones de la palabra, y se repetira hasta que alguna de las partes de la
        //siguiente estructura de control no cambie el valor de 'valid' a otro numero que no sea 0.
        while (valid == 0) {

            //Informamos al usuario de que introduzca la palabra concreta (la 1, la 2, la 3, etc)
            printf("Introduce la palabra %d: ", i + 1);

            // Aqui estamos recogiendo el input del usuario, pero en vez de meterlo directamente en la words[indice]
            //correspondiente, la metemos en el buffer que hemos creado antes. Si hubiera algun error, seria considerado
            //null, y por tanto imprimiriamos el error que sigue.
            if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
                perror("Error reading input");
                return;
            }

            // Quitamos algun caracter de nueva linea ("\n") que fgets() incluye al final de la cadena, para que no de
            //problemas luego.
            buffer[strcspn(buffer, "\n")] = '\0';

            // Si vemos que no hay nada en el buffer, avisamos al usuario de que no hay ninguna palabra y que repita.
            if (strlen(buffer) == 0) {
                printf("No se ha introducido ninguna palabra. Por favor, intenta nuevamente.\n");
            } else if (strlen(buffer) >= MAX_LENGTH) { // Si la palabra supera los 20 caracteres, avisamos al usuario de
                //que no hay ninguna palabra y que repita.
                printf("La palabra excede 20 caracteres. Por favor, intenta nuevamente.\n");
                // para que no queden trozos de la larga palabra por ahi, limpiamos el bufer de entrada de la consola, de
                //cualquier cosa que se haya quedado dentro, con el siguiente codigo:
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
            } else { // Aqui revisamos si hay espacios en la palabra introducida por el usuario.
                // Tenemos aqui nuestra variable de control, 'hasSpaces', la cual pasara a tener un valor de 1 si la
                // palabra tuviera espacios.
                int hasSpaces = 0;
                for (int j = 0; buffer[j] != '\0'; j++) {
                    if (isspace(buffer[j])) {
                        hasSpaces = 1;
                        break;
                    }
                }
                //si la palabra tiene espacios, pues avisamos al usuario y de que repita.
                if (hasSpaces) {
                    printf("La palabra no debe contener espacios. Por favor, intenta nuevamente.\n");
                } else { // y si no hay espacios, pues la palabra ya paso todas las validaciones y pasamos el valor de lo que
                    //hemos guardado y validado en la variable buffer, a la variable words[i], del indice que toque.
                    strcpy(words[i], buffer);
                    printf(" %s\n", words[i]);
                    //tenemos la palabra lista, asi que podemos salir del loop dandole un valor distinto de cero a 'valid' para pasar
                    //a la siguiente palabra.
                    valid = 1;
                }
            }
        }
    }
}

void printWords(char words[MAX_WORDS][MAX_LENGTH]) {
    printf("Estas son tus palabras ordenadas:\n"); // Imprime un encabezado indicando que se mostraran las palabras ordenadas.
    for (int i = 0; i < MAX_WORDS; i++) { // Inicia un bucle for que itera desde i = 0 hasta i < MAX_WORDS. i se utiliza como indice para recorrer las palabras.
        printf("%s\n", words[i]); // Imprime la palabra almacenada en words[i]. %s es el especificador de formato para cadenas de caracteres. \n añade un salto de linea despues de cada palabra.
    }
}

void orderWords(int orderSelected, char words[MAX_WORDS][MAX_LENGTH]) {
    for (int i = 0; i < MAX_WORDS - 1; i++) {  // Bucle externo: itera desde la primera palabra (indice 0) hasta la penultima (indice MAX_WORDS - 2).
        for (int j = i + 1; j < MAX_WORDS; j++) { // Bucle interno: itera desde la palabra siguiente a la actual (indice i + 1) hasta la última palabra (indice MAX_WORDS - 1).
            int shouldSwap = 0; // Inicializa una variable booleana (en realidad un entero que actua como booleano) para indicar si se deben intercambiar las palabras. 0 significa falso, 1 significa verdadero.
            if (orderSelected == 1 && strcmp(words[i], words[j]) > 0) { // Verifica si se selecciono el orden ascendente (orderSelected == 1) Y si la palabra en words[i] es lexicograficamente mayor que la palabra en words[j] (strcmp devuelve un valor > 0).
                shouldSwap = 1; // Si ambas condiciones son verdaderas, se deben intercambiar las palabras.
            } else if (orderSelected == 2 && strcmp(words[i], words[j]) < 0) { // Verifica si se selecciono el orden descendente (orderSelected == 2) Y si la palabra en words[i] es lexicograficamente menor que la palabra en words[j] (strcmp devuelve un valor < 0).
                shouldSwap = 1; // Si ambas condiciones son verdaderas, se deben intercambiar las palabras.
            }

            if (shouldSwap) { // Si shouldSwap es 1 (verdadero), se procede al intercambio de las palabras.
                char temp[MAX_LENGTH]; // Declara un array temporal (temp) para almacenar una de las palabras durante el intercambio.
                strcpy(temp, words[i]); // Copia la palabra en words[i] al array temporal temp.
                strcpy(words[i], words[j]); // Copia la palabra en words[j] a la posición words[i], sobreescribiendo la palabra original.
                strcpy(words[j], temp); // Copia la palabra almacenada en temp (la palabra original de words[i]) a la posición words[j], completando el intercambio.
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////FUNCIONES DE LA OPCION 4 - Conversion de coordenadas:

// Funcion para que el usuario elija una opcion del menu del ejercicio 4.
// Es exactamente igual a la función chooseOption, solo que apunta a otra variable y pone otras condiciones numericas:
void selectConversion (int *conversionSelected) {
    char introducedConversion[MAX_LENGTH];

    do {
        printf("Elige una conversion para tus coordenadas: \n\n");
        printf("Opcion 1: Convertir de cartesianas a polares.\n");
        printf("Opcion 2: Convertir de polares a cartesianas. \n");
        printf("Opcion 3: Salir del programa: \n\n");

        do {
            printf("Ingresa la opcion: ");
            fgets(introducedConversion, MAX_LENGTH, stdin);

            introducedConversion[strcspn(introducedConversion, "\n")] = '\0';

            if (!validateNumbers(introducedConversion) || strlen(introducedConversion) > 1) {
                printf("Solamente se puede introducir un numero.\n");
                *conversionSelected = 0;
            } else {
                *conversionSelected = atoi(introducedConversion);
            }
        } while (*conversionSelected == 0);

        if (*conversionSelected < 1 || *conversionSelected > 3) {
            printf("Opcion no valida. Por favor, ingresa la primera, la segunda o la tercera opcion.\n");
        }

    } while (*conversionSelected < 1 || *conversionSelected > 3);
}

// Funcion para convertir de cartesianas a polares
void cartesianToPolar(double x, double y, double *r, double *theta) {
    // Recibe las coordenadas cartesianas (x, y) y punteros a r y theta.
    *r = sqrt(x*x + y*y);
    // Calcula la magnitud (r) usando el teorema de Pitágoras: r = sqrt(x^2 + y^2).
    *theta = atan2(y, x);
    // Calcula el ángulo (theta) usando la función atan2(y, x), que maneja correctamente los cuadrantes.
}

// Funcion para convertir de polares a cartesianas
void polarToCartesian(double r, double theta, double *x, double *y) {
    // Recibe las coordenadas polares (r, theta) y punteros a x e y.
    *x = r * cos(theta);
    // Calcula la coordenada x: x = r * cos(theta).
    *y = r * sin(theta);
    // Calcula la coordenada y: y = r * sin(theta).
}

// Función para validar si una cadena representa un numero decimal válido.
int validateDecimals(char chain[MAX_LENGTH]) {
    int point = 0; // Inicializa un contador para el numero de puntos decimales encontrados.
    int slash = 0; // Inicializa un contador para el numero de rayas de negativos encontrados.
    // Itera a través de cada carácter de la cadena.
    for (int i = 0; i < strlen(chain); i++) {
        if (!isdigit(chain[i]) && chain[i] != '.' && chain[i] != '-') {
            // Si el caracter actual no es un digito, un punto decimal ni un signo menos, la cadena no es un numero decimal valido, y retorna 0 (falso).
            return 0;
        }
        if (chain[i] == '.') {
            // Si el caracter actual es un punto decimal:
            point++; // Incrementa el contador de puntos decimales.
            if (point > 1) {
                // Si ya se ha encontrado mas de un punto decimal, la cadena no es un numero decimal valido, y retorna 0 (falso).
                return 0;
            }
        }
        if (chain[i] == '-') {
            // Si el caracter actual es una raya:
            slash++; // Incrementa el contador de rayas de negativo.
            if (slash > 1) {
                // Si ya se ha encontrado más de una raya, la cadena no es un numero valido, y retorna 0 (falso).
                return 0;
            }
        }
    }
    // Si se llega al final del bucle sin encontrar errores, la cadena es un numero decimal valido, y retorna 1 (verdadero).
    return 1;
}

void readCoordenates(double *coordenate) {
    char numberIntroduced[MAX_LENGTH];

    do { // Bucle do-while interno para la validacion de la entrada que escribe el usuario.
        fgets(numberIntroduced, MAX_LENGTH, stdin); // Lee la entrada del usuario, incluyendo espacios, y la guarda en optionSelected.
        // fgets es más seguro que scanf para evitar desbordamientos de buffer.

        numberIntroduced[strcspn(numberIntroduced, "\n")] = '\0'; // Elimina el caracter de nueva linea ('\n') que
        // fgets puede dejar al final de la cadena. strcspn encuentra la primera ocurrencia de '\n' y devuelve su indice, para que despues el
        // valor a ese indice sea igual a nulo ('\0')

        if (!validateDecimals(numberIntroduced)) { // Valida si la entrada contiene solo numeros, puntos o rayas.
            printf("Solamente se pueden introducir numeros validos.\n"); // Mensaje de error para el usuario si la entrada no es valida.
            *coordenate = 0; // Asigna 0 a *coordinate para que el bucle interno se repita.
        } else { // Si la entrada es un numero valido, convierte la cadena a un numero decimal usando atof() y lo guarda en la variable apuntada por coordinate.
            *coordenate = atof(numberIntroduced);
        }
    } while (*coordenate == 0); // // El bucle interno se repite mientras *coordinate sea 0 (es decir, mientras la entrada no sea un numero valido).
}

// Esta funcion imprime los resultados de la conversion de coordenadas, basandose en el tipo de conversion que se realizo.
void printResults(double x, double y, double r, double theta, int conversionSelected) {
    // Se utiliza un switch para determinar que tipo de resultado se debe imprimir.
    switch (conversionSelected) {
        case 1:
            // Caso 1: Se realizo la conversion de coordenadas cartesianas a polares.
            printf("Coordenadas polares: r = %.2f, theta = %.2f radianes\n", r, theta);
        // Se imprime el valor de 'r' (magnitud) y 'theta' (angulo en radianes)
        // con dos decimales de precision.
        break;

        case 2:
            // Caso 2: Se realizo la conversión de coordenadas polares a cartesianas.
            printf("Coordenadas cartesianas: x = %.2f, y = %.2f\n", x, y);
        // Se imprime el valor de 'x' y 'y' (coordenadas cartesianas)
        // con dos decimales de precision.
        break;

        default:
            // default para manejar casos no validos.
            printf("Opcion no valida. Por favor.\n");
        break;
    }
}



