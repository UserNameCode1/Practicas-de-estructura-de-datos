#include <iostream>
#include <string>

using namespace std;

int main() {
    int opcion = 0;

    do {
        cout << "\n=== SISTEMA DE CALIFICACIONES ===" << endl;
        cout << "1. Registrar estudiante" << endl;
        cout << "2. Ver informacion del programa" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: {
                string nombreAlumno;
                string estado;
                int edad = 0;
                float calificacion1 = 0.0f;
                float calificacion2 = 0.0f;
                float calificacion3 = 0.0f;
                int cantidadCalificaciones = 0;
                int aprobadas = 0;
                int reprobadas = 0;
                float calificacion = 0.0f;
                float sumaCalificaciones = 0.0f;
                float promedio = 0.0f;
                float calificacionMasAlta = 0.0f;
                float calificacionMasBaja = 0.0f;

                cout << "\nIngresa el nombre del alumno: ";
                getline(cin, nombreAlumno);

                cout << "Ingresa la edad del alumno: ";
                cin >> edad;

                while (edad < 0 || edad > 120) {
                    cout << "Edad invalida. Ingresa una edad entre 0 y 120: ";
                    cin >> edad;
                }

                cout << "primera calificacion: ";
                cin >> calificacion1;
                while (calificacion1 < 0 || calificacion1 > 10) {
                    cout << "Error: la calificacion debe estar entre 0 y 10. Intenta de nuevo: ";
                    cin >> calificacion1;
                }

                cout << "Cuantas calificaciones deseas registrar en el ciclo? ";
                cin >> cantidadCalificaciones;
                while (cantidadCalificaciones <= 0) {
                    cout << "Error: la cantidad debe ser mayor que cero. Intenta de nuevo: ";
                    cin >> cantidadCalificaciones;
                }

                cout << "segunda calificacion: ";
                cin >> calificacion2;
                while (calificacion2 < 0 || calificacion2 > 10) {
                    cout << "Error: la calificacion debe estar entre 0 y 10. Intenta de nuevo: ";
                    cin >> calificacion2;
                }

                cout << "tercera calificacion: ";
                cin >> calificacion3;
                while (calificacion3 < 0 || calificacion3 > 10) {
                    cout << "Error: la calificacion debe estar entre 0 y 10. Intenta de nuevo: ";
                    cin >> calificacion3;
                }

                promedio = (calificacion1 + calificacion2 + calificacion3) / 3.0f;
                
                for (int i = 1; i <= cantidadCalificaciones; i++) {
                    cout << "Ingresa la calificacion " << i << " de la lista extra: ";
                    cin >> calificacion;

                    while (calificacion < 0 || calificacion > 10) {
                        cout << "Error: la calificacion debe estar entre 0 y 10. Intenta de nuevo: ";
                        cin >> calificacion;
                    }

                    sumaCalificaciones += calificacion;

                    if (calificacion >= 6) {
                        aprobadas++;
                    } else {
                        reprobadas++;
                    }

                    if (i == 1) {
                        calificacionMasAlta = calificacion;
                        calificacionMasBaja = calificacion;
                    } else {
                        if (calificacion > calificacionMasAlta) {
                            calificacionMasAlta = calificacion;
                        }
                        if (calificacion < calificacionMasBaja) {
                            calificacionMasBaja = calificacion;
                        }
                    }
                }

                promedio = sumaCalificaciones / cantidadCalificaciones;

                if (promedio >= 9) {
                    estado = "EXCELENTE";
                } else if (promedio >= 7) {
                    estado = "APROBADO";
                } else if (promedio >= 6) {
                    estado = "REGULAR (aprobado con lo minimo)";
                } else {
                    estado = "REPROBADO";
                }

                cout << "\nResumen del estudiante" << endl;
                cout << "Nombre: " << nombreAlumno << endl;
                cout << "Edad: " << edad << endl;
                cout << "Calificacion 1: " << calificacion1 << endl;
                cout << "Calificacion 2: " << calificacion2 << endl;
                cout << "Calificacion 3: " << calificacion3 << endl;
                cout << "Cantidad de calificaciones: " << cantidadCalificaciones << endl;
                cout << "Promedio del ciclo: " << promedio << endl;
                cout << "Estado: " << estado << endl;
                cout << "Calificaciones aprobatorias: " << aprobadas << endl;
                cout << "Calificaciones reprobatorias: " << reprobadas << endl;
                cout << "Calificacion mas alta: " << calificacionMasAlta << endl;
                cout << "Calificacion mas baja: " << calificacionMasBaja << endl;
                break;
            }

            case 2:
                cout << "\n registrar los datos y calificaciones de un estudiante," << endl;
                cout << "promedio y determinar su estado academico." << endl;
                break;

            case 3:
                cout << "\nSaliendo del programa..." << endl;
                break;

            default:
                cout << "\nOpcion invalida. Intenta de nuevo." << endl;
        }
    } while (opcion != 3); 

    return 0;
}
