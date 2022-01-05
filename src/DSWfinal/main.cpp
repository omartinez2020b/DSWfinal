#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "habitacion.h"
#include "posicion.h"
#include "coordenadas.h"
#include "pibot.h"


int main()
{
    srand(time(NULL));

    Posicion pos_puerta;
    Posicion pos_esquina_infd;
    Habitacion hab1(20, 60, pos_esquina_infd);
    hab1.colocar_puerta_aleatoria(pos_puerta);

    Coordenadas coord_robot;
    hab1.obtener_coordenadas_aleatorias_para_robot(coord_robot);
    Pibot mypibot(coord_robot);

    hab1.colocar_pibot(coord_robot);
    hab1.dibujar();
    int distancia = mypibot.leer_ultrasonidos(pos_esquina_infd);
    while (!mypibot.detectar_objeto(pos_puerta))
    {
        system("clear");
        cout << "La puerta está en X= " << pos_puerta.get_x() << " y " << "Y= " << pos_puerta.get_y() << endl;
        if (distancia == 0) mypibot.girar_derecha();
        mypibot.avanzar();

        mypibot.get_coordenadas(coord_robot);
        cout << "EL robot está en X= " << coord_robot.get_x() << " y " << "Y= " << coord_robot.get_y() << endl;
        hab1.colocar_pibot(coord_robot);
        hab1.dibujar();
        distancia = mypibot.leer_ultrasonidos(pos_esquina_infd);
    }


    return 0;
}
