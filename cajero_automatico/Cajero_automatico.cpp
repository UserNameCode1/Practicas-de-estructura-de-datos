#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    cout << fixed << setprecision(2);

    int pin;
    int intentos = 3;
    bool pinCorrecto = false;

    while (intentos > 0) {
        cout << "Ingrese su PIN de 4 digitos: ";
        cin >> pin;

        if (pin == 1234) {
            pinCorrecto = true;
            intentos = 0; 
        } else {
            intentos = intentos - 1;
            if (intentos > 0) {
                cout << "PIN incorrecto. Le quedan " << intentos << " intento(s).\n\n";
            }
        }
    }

    if (pinCorrecto == false) {
        cout << "\n[!] TARJETA BLOQUEADA. Agoto sus 3 intentos.\n";
        return 0; 
    }

    cout << "\n¡Bienvenido al Cajero Automático!\n\n";

    double saldo = 5000.00;
    int opcion = 0;

    while (opcion != 5) {
        cout << "-------------------------------\n";
        cout << "         MENÚ PRINCIPAL        \n";
        cout << "-------------------------------\n";
        cout << "1. Consultar Saldo\n";
        cout << "2. Depositar\n";
        cout << "3. Retirar\n";
        cout << "4. Retiros Rápidos\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "\n-> Su saldo actual es: $" << saldo << "\n\n";

        } else if (opcion == 2) {
            double deposito;
            cout << "\n¿Cuánto desea depositar?: $";
            cin >> deposito;

            if (deposito <= 0) {
                cout << "[ERROR] El depósito debe ser mayor a $0.00\n\n";
            } else if (deposito > 10000) {
                cout << "[ERROR] No puede depositar más de $10,000.00\n\n";
            } else {
                saldo = saldo + deposito; // Suma directa
                cout << "[OK] Depósito exitoso. Nuevo saldo: $" << saldo << "\n\n";
            }

        } else if (opcion == 3) {
            double retiro;
            cout << "\n¿Cuánto desea retirar? (en billetes de 100): $";
            cin >> retiro;

            if (retiro <= 0) {
                cout << "[ERROR] El retiro debe ser mayor a $0.00\n\n";
            } else if ((int)retiro % 100 != 0) {
                cout << "[ERROR] Debe ser múltiplo de 100 (ejemplo: 200, 500, 1000).\n\n";
            } else {
                // Calcular comisión
                double comision = 0;
                if (retiro < 1000) {
                    comision = 15.00;
                }

                double totalCobrar = retiro + comision;

                if (totalCobrar > saldo) {
                    cout << "[ERROR] Saldo insuficiente.\n";
                    if (comision > 0) {
                        cout << "(Recuerde que por retirar menos de $1000 se cobran $15 de comisión).\n";
                    }
                    cout << "\n";
                } else {
                    saldo = saldo - totalCobrar; // Resta directa
                    cout << "[OK] Retiro realizado con éxito.\n";
                    if (comision > 0) {
                        cout << "Comisión aplicada: $15.00\n";
                    }
                    cout << "Nuevo saldo: $" << saldo << "\n\n";
                }
            }

        } else if (opcion == 4) {
            cout << "\n--- TABLA DE RETIROS RÁPIDOS ---\n";
            
            if (saldo >= 515) {
                cout << "$500 (Total: $515 con comisión)  -> DISPONIBLE\n";
            } else {
                cout << "$500 (Total: $515 con comisión)  -> NO DISPONIBLE\n";
            }

            if (saldo >= 1000) {
                cout << "$1000 (Sin comisión)            -> DISPONIBLE\n";
            } else {
                cout << "$1000 (Sin comisión)            -> NO DISPONIBLE\n";
            }

            if (saldo >= 1500) {
                cout << "$1500 (Sin comisión)            -> DISPONIBLE\n";
            } else {
                cout << "$1500 (Sin comisión)            -> NO DISPONIBLE\n";
            }

            if (saldo >= 2000) {
                cout << "$2000 (Sin comisión)            -> DISPONIBLE\n";
            } else {
                cout << "$2000 (Sin comisión)            -> NO DISPONIBLE\n";
            }

            if (saldo >= 2500) {
                cout << "$2500 (Sin comisión)            -> DISPONIBLE\n";
            } else {
                cout << "$2500 (Sin comisión)            -> NO DISPONIBLE\n";
            }

            if (saldo >= 3000) {
                cout << "$3000 (Sin comisión)            -> DISPONIBLE\n\n";
            } else {
                cout << "$3000 (Sin comisión)            -> NO DISPONIBLE\n\n";
            }

        } else if (opcion == 5) {
            cout << "\n Gracias Hasta pronto.\n";

        } else {
            cout << "\n[ERROR] Opción no válida. Intente de nuevo.\n\n";
        }
    }

    return 0;
}