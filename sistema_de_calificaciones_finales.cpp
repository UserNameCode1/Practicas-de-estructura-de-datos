#include <iostream>
#include <string>

using namespace std;

int main() {
    int opcion;

    // opciones
    cout << "=== SISTEMA DE CALIFICACIONES ===" << endl;
    cout << "1. Registrar estudiante" << endl;
    cout << "2. Ver informacion del programa" << endl;
    cout << "3. Salir" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    // Estructura switch-case 
    switch (opcion) {
        case 1: {
            string nombre;
            int edad;
            int numCalificaciones;
            float suma = 0.0f;
            int aprobadas = 0;
            int reprobadas = 0;
            float maxCalificacion = -1.0f;
            float minCalificacion = 11.0f;

            // 
            cin.ignore();

            cout << "\n--- REGISTRO DE ESTUDIANTE ---" << endl;
            cout << "Ingrese el nombre del estudiante: ";
            getline(cin, nombre);

            cout << "Ingrese la edad: ";
            cin >> edad;

            // Validación de edad (Nivel 2)
            if (edad < 0 || edad > 120) {
                cout << "Error: Edad invalida." << endl;
                return 1;
            }

            // (Nivel 4)
            cout << "¿Cuantas calificaciones deseas registrar?: ";
            cin >> numCalificaciones;

            if (numCalificaciones <= 0) {
                cout << "Error: El numero de calificaciones debe ser mayor a 0." << endl;
                return 1;
            }

            for (int i = 1; i <= numCalificaciones; i++) {
                float calificacion;
                cout << "Ingrese la calificacion " << i << " (0 a 10): ";
                cin >> calificacion;

                // Validación de cada calificación (Nivel 2)
                if (calificacion < 0.0f || calificacion > 10.0f) {
                    cout << "Error: La calificacion debe estar entre 0 y 10." << endl;
                    return 1;
                }

                // Acumulación de suma y conteo de aprobadas/reprobadas (Nivel 4)
                suma += calificacion;
                if (calificacion >= 6.0f) {
                    aprobadas++;
                } else {
                    reprobadas++;
                }

                //  (Nivel 4)
                if (calificacion > maxCalificacion) {
                    maxCalificacion = calificacion;
                }
                if (calificacion < minCalificacion) {
                    minCalificacion = calificacion;
                }
            }

            // Nivel 1 & 4
            float promedio = suma / numCalificaciones;

            // Resumen e impresión de datos (Nivel 1, 2 y 4)
            cout << "\n=== RESUMEN DEL ESTUDIANTE ===" << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "Edad: " << edad << " años" << endl;
            cout << "Promedio: " << promedio << endl;

            cout << "Estado: ";
            if (promedio >= 9.0f) {
                cout << "EXCELENTE" << endl;
            } else if (promedio >= 7.0f) {
                cout << "APROBADO" << endl;
            } else if (promedio >= 6.0f) {
                cout << "REGULAR (aprobado con lo minimo)" << endl;
            } else {
                cout << "REPROBADO" << endl;
            }

            //  Nivel 4
            cout << "Calificaciones aprobatorias: " << aprobadas << endl;
            cout << "Calificaciones reprobatorias: " << reprobadas << endl;
            cout << "Calificacion mas alta: " << maxCalificacion << endl;
            cout << "Calificacion mas baja: " << minCalificacion << endl;

            break;
        }

        case 2:
            cout << "\n--- INFORMACION DEL PROGRAMA ---" << endl;
            cout << "Sistema de Calificaciones Escolares" << endl;
            cout << "Practica #2 de Estructuras de Datos: Implementacion de switch-case y ciclos for." << endl;
            break;

        case 3:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opción invalida. Intente de nuevo." << endl;
            break;
    }

    return 0;
}
