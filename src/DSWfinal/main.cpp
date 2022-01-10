#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "habitacion.h"
#include "simulacion.h"


int main()
{
    srand(time(NULL));
    int filas, columnas;
    int sel = 0;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "Bienvenido al escenario de simulación de Lo-Rovout SL, by Iguan T.Aten" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Para empezar, vamos a establecer el tamaño del entorno simulado" << endl;
    cout << "Introduzca el número de filas (6-20): ";
    cin >> filas;
    cout << "Introduzca el número de columnas (6-60): ";
    cin >> columnas;
    Habitacion hab(filas, columnas);
    Simulacion entorno(hab);
    while (sel != 3)
    {
        cout << "Seleccione si quiere simular un Pibot(1), un Tello(2) o salir(3): ";
        cin >> sel;
        system("clear");
        if (sel == 1) entorno.simular_pibot();
        else if (sel == 2) entorno.simular_tello();
        entorno.reset();
    }
    cout << "Hasta la próxima!" << endl;

    return EXIT_SUCCESS;
}
