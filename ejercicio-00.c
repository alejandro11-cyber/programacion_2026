#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ESTUDIANTES 100
#define MAX_NOMBRE 50
#define MAX_CODIGO 20

typedef struct {
    char nombre[MAX_NOMBRE];
    char codigo[MAX_CODIGO];
    int edad;
    float promedio;
    bool activo;
} Estudiante;

Estudiante estudiantes[MAX_ESTUDIANTES];
int total = 0;

// Validacion de promedio
int promedioValido(float p) { return p >= 0.0 && p <= 10.0; }

// ===== FUNCIONES DE ACTUALIZACION =====
void actualizarNombre(Estudiante *e, const char *nuevoNombre) {
    strncpy(e->nombre, nuevoNombre, MAX_NOMBRE);
    e->nombre[MAX_NOMBRE-1] = '\0';
}

void actualizarCodigo(Estudiante *e, const char *nuevoCodigo) {
    strncpy(e->codigo, nuevoCodigo, MAX_CODIGO);
    e->codigo[MAX_CODIGO-1] = '\0';
}

void actualizarEdad(Estudiante *e, int nuevaEdad) {
    e->edad = nuevaEdad;
}

void actualizarPromedio(Estudiante *e, float nuevoPromedio) {
    if (promedioValido(nuevoPromedio)) {
        e->promedio = nuevoPromedio;
    } else {
        printf("Error: Promedio invalido (0.0 - 10.0)\n");
    }
}

void actualizarActivo(Estudiante *e, bool estado) {
    e->activo = estado;
}

// ===== FUNCIONES DE VISUALIZACION =====
void mostrarNombre(Estudiante *e) { printf("Nombre: %s\n", e->nombre); }
void mostrarCodigo(Estudiante *e) { printf("Codigo: %s\n", e->codigo); }
void mostrarEdad(Estudiante *e) { printf("Edad: %d anios\n", e->edad); }
void mostrarPromedio(Estudiante *e) { printf("Promedio: %.2f\n", e->promedio); }
void mostrarActivo(Estudiante *e) { printf("Estado: %s\n", e->activo ? "Activo" : "Inactivo"); }

void mostrarInformacionCompleta(Estudiante *e) {
    printf("\n--- Datos del Estudiante ---\n");
    mostrarNombre(e);
    mostrarCodigo(e);
    mostrarEdad(e);
    mostrarPromedio(e);
    mostrarActivo(e);
}

// ===== FUNCIONES PRINCIPALES =====
void agregarEstudiante() {
    if (total >= MAX_ESTUDIANTES) {
        printf("Error: Capacidad maxima alcanzada.\n");
        return;
    }

    Estudiante e;
    printf("\n--- Nuevo Estudiante ---\n");

    printf("Nombre: ");
    getchar(); // limpiar buffer
    fgets(e.nombre, MAX_NOMBRE, stdin);
    e.nombre[strcspn(e.nombre, "\n")] = 0;

    printf("Codigo: ");
    scanf("%s", e.codigo);

    printf("Edad: ");
    scanf("%d", &e.edad);

    do {
        printf("Promedio (0.0 - 10.0): ");
        scanf("%f", &e.promedio);
    } while(!promedioValido(e.promedio));

    int act;
    printf("Activo (1=si, 0=no): ");
    scanf("%d", &act);
    e.activo = (act == 1);

    estudiantes[total++] = e;
    printf("Estudiante agregado con exito.\n");
}

void mostrarUno() {
    if (total == 0) {
        printf("No hay estudiantes registrados.\n");
        return;
    }

    char cod[MAX_CODIGO];
    printf("Ingrese el codigo a buscar: ");
    scanf("%s", cod);

    for (int i = 0; i < total; i++) {
        if (strcmp(estudiantes[i].codigo, cod) == 0) {
            mostrarInformacionCompleta(&estudiantes[i]);
            return;
        }
    }
    printf("Estudiante no encontrado.\n");
}

void mostrarTodos() {
    if (total == 0) {
        printf("No hay estudiantes registrados.\n");
        return;
    }

    printf("\n=== Lista de Estudiantes (%d) ===\n", total);
    for (int i = 0; i < total; i++) {
        printf("\n[%d]\n", i+1);
        mostrarInformacionCompleta(&estudiantes[i]);
    }
}

// ===== MENU =====
void menu() {
    printf("\n=== GESTION DE ESTUDIANTES ===\n");
    printf("1. Agregar Estudiante\n");
    printf("2. Mostrar estudiante por codigo\n");
    printf("3. Mostrar todos los estudiantes\n");
    printf("4. Salir\n");
    printf("Opcion: ");
}

// ===== MAIN =====
int main() {
    int op;

    do {
        menu();
        if (scanf("%d", &op) != 1) {
            printf("Error. Ingrese un numero valido.\n");
            while (getchar() != '\n'); // limpiar buffer
            continue;
        }

        switch(op) {
            case 1: agregarEstudiante(); break;
            case 2: mostrarUno(); break;
            case 3: mostrarTodos(); break;
            case 4: printf("Saliendo del programa...\n"); break;
            default: printf("Opcion invalida.\n");
        }
    } while(op != 4);

    return 0;
}