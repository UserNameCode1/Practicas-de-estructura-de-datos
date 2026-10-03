#include <iostream>
#include <iomanip> 

using namespace std;


//verificar el PIN
bool pedirPIN() {
    int pin;
    int intentos = 3;

    while (intentos > 0) {
        cout << "Ingrese su PIN: ";
        cin >> pin;

        if (pin == 1234) {
            cout << "\n¡PIN correcto! Bienvenido.\n\n";
            return true; // Acceso concedido
        } else {
            intentos--; // Restamos 1 intento
            cout << "PIN incorrecto. Te quedan " << intentos << " intento(s).\n";