#include "tello.h"
#include <iostream>
using namespace std;

void Tello::avanzar()
{
    if (bateria_actual > 0)
    {
        for (int i = 0; i < 2; i++) Pibot::avanzar(); // Simplemente se avanza dos veces
        bateria_actual--;
    }
    else
    {
        if (distancia_avance == 2) distancia_avance = 1;
        Pibot::avanzar();
    }
}
