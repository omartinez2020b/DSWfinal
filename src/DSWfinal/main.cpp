#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "habitacion.h"
#include "posicion.h"
#include "coordenadas.h"
#include "pibot.h"
#include "tello.h"
#include "simulacion.h"


int main()
{
    srand(time(NULL));

    Habitacion hab1(20, 60);
    Simulacion escenario(hab1);
    Tello tello1(0, 0);

    escenario.simular_tello();


    return 0;
}
