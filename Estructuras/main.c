#include <stdio.h>

// Definimos la estructura Alumno
struct Alumno {
    int matricula;
    char nombre[50];
    char direccion[50];
    char carrera[50];
    float promedio;
};

// Prototipos de funciones
void ingresarDatos(struct Alumno *alumnos, int n);
void mostrarDatos(struct Alumno *alumnos, int n);

int main() {

    int n;
    printf("Ingrese el numero de alumnos: ");
    scanf("%d", &n);

    // Crear un arreglo de estructuras Alumno
    struct Alumno alumnos[n];

    int opcion;
    do {
        // Mostrar menu
        printf("\nMENU:\n");
        printf("1. Ingresar datos de alumnos.\n");
        printf("2. Mostrar datos de alumnos.\n");
        printf("0. Salir.\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Llamar a la funcion para ingresar datos
                ingresarDatos(alumnos, n);
                break;

            case 2:
                // Llamar a la funcion para mostrar datos
                mostrarDatos(alumnos, n);
                break;

            case 0:
                printf("Saliendo del programa, hecho por Santiago Molina.\n");
                break;

            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 0);

    return 0;
}

// Funcion para ingresar datos de los alumnos
void ingresarDatos(struct Alumno *alumnos, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nIngrese los datos del alumno %d:\n", i + 1);

        // Solicitar y almacenar la matricula
        printf("Matricula: ");
        scanf("%d", &alumnos[i].matricula);

        // Solicitar y almacenar el nombre
        printf("Nombre: ");
        fflush(stdin);  // Limpiar el bufer de entrada antes de leer una cadena
        gets(alumnos[i].nombre);

        // Solicitar y almacenar la direccion
        printf("Direccion: ");
        fflush(stdin);
        gets(alumnos[i].direccion);

        // Solicitar y almacenar la carrera
        printf("Carrera: ");
        fflush(stdin);
        gets(alumnos[i].carrera);

        // Solicitar y almacenar el promedio
        printf("Promedio: ");
        scanf("%f", &alumnos[i].promedio);
    }
}

// Funcion para mostrar datos de los alumnos
void mostrarDatos(struct Alumno *alumnos, int n) {
    printf("\nDatos de los alumnos ingresados:\n");

    // Iterar sobre cada alumno y mostrar sus datos
    for (int i = 0; i < n; i++) {
        printf("\nAlumno %d:\n", i + 1);
        printf("Matricula: %d\n", alumnos[i].matricula);
        printf("Nombre: %s\n", alumnos[i].nombre);
        printf("Direccion: %s\n", alumnos[i].direccion);
        printf("Carrera: %s\n", alumnos[i].carrera);
        printf("Promedio: %.2f\n", alumnos[i].promedio);
    }
}