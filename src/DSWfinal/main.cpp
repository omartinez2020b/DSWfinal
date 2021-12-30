#include <iostream>
using namespace std;

#include "habitacion.h"
#include "posicion.h"

using namespace std;

int main()
{
    Posicion pos1(60, 20);
    Posicion pos_puerta;
    Habitacion hab1(pos1);
    hab1.colocar_puerta_aleatoria(pos_puerta);
    hab1.dibujar();
    cout << pos1.get_x() << endl;
    return 0;
}
