#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "habitacion.h"
#include "posicion.h"


int main()
{
    srand(time(NULL));

    Posicion pos_puerta;
    Habitacion hab1(20, 30);
    hab1.colocar_puerta_aleatoria(pos_puerta);
    hab1.dibujar();
    Coor

    return 0;
}
