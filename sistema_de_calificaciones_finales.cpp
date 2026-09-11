#include <iostream>
#include <string>

using namespace std;

int main() {

    string nombre;
    int edad;
    float calificacion1, calificacion2, calificacion3;
    float promedio;

    
    cout << "Ingrese el nombre del estudiante: ";
    getline(cin, nombre);

    cout << "Ingrese la edad del estudiante: ";
    cin >> edad;

    
    if (edad < 0 || edad > 120) {
        cout << "Error: Edad invalida" << endl;
        return 1;
    }

    
    cout << "Ingrese la calificacion 1 (0 a 10): ";
    cin >> calificacion1;
    cout << "Ingrese la calificacion 2 (0 a 10): ";
    cin >> calificacion2;
    cout << "Ingrese la calificacion 3 (0 a 10): ";
    cin >> calificacion3;

    
    if (calificacion1 < 0 || calificacion1 > 10 ||
        calificacion2 < 0 || calificacion2 > 10 ||
        calificacion3 < 0 || calificacion3 > 10) {
        cout << "Error: Alguna de las calificaciones no esta en el rango de 0 a 10." << endl;
        return 1;
    }

    
    promedio = (calificacion1 + calificacion2 + calificacion3) / 3.0;

    // resumen
    cout << "\n=== RESUMEN DEL ESTUDIANTE ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << " anos" << endl;
    cout << "Promedio: " << promedio << endl;

    cout << "Estado: ";
    if (promedio >= 9.0) {
        cout << "EXCELENTE" << endl;
    } else if (promedio >= 7.0) {
        cout << "APROBADO" << endl;
    } else if (promedio >= 6.0) {
        cout << "REGULAR" << endl;
    } else {
        cout << "REPROBADO" << endl;
    }

    return 0;
}
