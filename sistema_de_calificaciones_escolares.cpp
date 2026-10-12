#include <iostream>
#include <string>
#include <limits>

using namespace std;

// =======================================================
// PROTOTIPOS DE FUNCIONES
// =======================================================
void mostrarMenu();
int leerEntero(string mensaje, int min, int max);
float leerCalificacion(int numero);
float calcularPromedio(float suma, int n);
string obtenerEstado(float promedio);
void registrarEstudiante();

// =======================================================
// FUNCIÓN PRINCIPAL
// =======================================================
int main() {
    int opcion = 0;

    do {
        mostrarMenu();
        opcion = leerEntero("Opcion: ", 1, 3);

        switch (opcion) {
            case 1:
                registrarEstudiante();
                break;

            case 2:
                cout << "\nPrograma para registrar datos y calificaciones de un estudiante," << endl;
                cout << "calcular su promedio y determinar su estado academico." << endl;
                break;

            case 3:
                cout << "\nSaliendo del programa..." << endl;
                break;
        }
    } while (opcion != 3);

    return 0;
}

// =======================================================
// DEFINICIÓN DE FUNCIONES
// =======================================================

// 1. Imprime las opciones del menú
void mostrarMenu() {
    cout << "\n=== SISTEMA DE CALIFICACIONES ===" << endl;
    cout << "1. Registrar estudiante" << endl;
    cout << "2. Ver informacion del programa" << endl;
    cout << "3. Salir" << endl;
}

// 2. Pide y valida la entrada de un entero dentro de un rango determinado
int leerEntero(string mensaje, int min, int max) {
    int valor = 0;
    cout << mensaje;
    
    while (!(cin >> valor) || valor < min || valor > max) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida. Por favor, ingresa un entero entre " << min << " y " << max << ": ";
    }
    
    return valor;
}

// 3. Pide y valida una calificación individual en el rango de 0 a 10
float leerCalificacion(int numero) {
    float calificacion = 0.0f;
    cout << "Ingresa la calificacion " << numero << ": ";
    
    while (!(cin >> calificacion) || calificacion < 0.0f || calificacion > 10.0f) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: la calificacion debe estar entre 0 y 10. Intenta de nuevo: ";
    }
    
    return calificacion;
}

// 4. Retorna el promedio exacto dividiendo la suma entre el número total de notas
float calcularPromedio(float suma, int n) {
    if (n <= 0) return 0.0f;
    return suma / static_cast<float>(n);
}

// 5. Determina y retorna la categoría académica del alumno según su promedio
string obtenerEstado(float promedio) {
    if (promedio >= 9.0f) {
        return "EXCELENTE";
    } else if (promedio >= 7.0f) {
        return "APROBADO";
    } else if (promedio >= 6.0f) {
        return "REGULAR (aprobado con lo minimo)";
    } else {
        return "REPROBADO";
    }
}

// 6. Gestiona todo el flujo de la opción 1 (captura de datos y reporte)
void registrarEstudiante() {
    string nombreAlumno;
    
    // Limpiar salto de línea remanente antes de usar getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nIngresa el nombre del alumno: ";
    getline(cin, nombreAlumno);

    int edad = leerEntero("Ingresa la edad del alumno (0-120): ", 0, 120);
    int cantidadCalificaciones = leerEntero("Cuantas calificaciones deseas registrar?: ", 1, 100);

    float sumaCalificaciones = 0.0f;
    int aprobadas = 0;
    int reprobadas = 0;
    float calificacionMasAlta = -1.0f;
    float calificacionMasBaja = 11.0f;

    for (int i = 1; i <= cantidadCalificaciones; i++) {
        float calificacion = leerCalificacion(i);
        sumaCalificaciones += calificacion;

        if (calificacion >= 6.0f) {
            aprobadas++;
        } else {
            reprobadas++;
        }

        if (calificacion > calificacionMasAlta) {
            calificacionMasAlta = calificacion;
        }
        if (calificacion < calificacionMasBaja) {
            calificacionMasBaja = calificacion;
        }
    }

    float promedio = calcularPromedio(sumaCalificaciones, cantidadCalificaciones);
    string estado = obtenerEstado(promedio);

    cout << "\n--- RESUMEN DEL ESTUDIANTE ---" << endl;
    cout << "Nombre: " << nombreAlumno << endl;
    cout << "Edad: " << edad << endl;
    cout << "Cantidad de calificaciones: " << cantidadCalificaciones << endl;
    cout << "Promedio del ciclo: " << promedio << endl;
    cout << "Estado: " << estado << endl;
    cout << "Calificaciones aprobatorias: " << aprobadas << endl;
    cout << "Calificaciones reprobatorias: " << reprobadas << endl;
    cout << "Calificacion mas alta: " << calificacionMasAlta << endl;
    cout << "Calificacion mas baja: " << calificacionMasBaja << endl;
}