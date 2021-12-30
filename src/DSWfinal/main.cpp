#include <iostream>
using namespace std;

#include "habitacion.h"
#include "posicion.h"

using namespace std;

int main()
{
    Posicion pos_puerta;
    Habitacion hab1(20, 30);
    hab1.colocar_puerta_aleatoria(pos_puerta);
    hab1.dibujar();

    return 0;
}
