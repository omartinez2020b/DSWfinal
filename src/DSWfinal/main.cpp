#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "habitacion.h"
#include "posicion.h"
#include "coordenadas.h"
#include "pibot.h"
#include "tello.h"


int main()
{
    srand(time(NULL));

    Posicion pos_puerta;
    Posicion pos_esquina_infd;
    Habitacion hab1(20, 60, pos_esquina_infd);
    hab1.colocar_puerta_aleatoria(pos_puerta);

    Coordenadas coord_robot;
    hab1.obtener_coordenadas_aleatorias_para_robot(coord_robot);
    Tello mypibot(coord_robot);

    hab1.colocar_tello(coord_robot, false);
    hab1.dibujar();

    bool puerta = mypibot.detectar_objeto(pos_puerta);
    int distancia = mypibot.leer_ultrasonidos(pos_esquina_infd);
    while (!puerta)
    {
        system("clear");
        cout << "La puerta está en X= " << pos_puerta.get_x() << " y " << "Y= " << pos_puerta.get_y() << endl;

        if (distancia <= 1) mypibot.girar_derecha();
        mypibot.avanzar();

        mypibot.get_coordenadas(coord_robot);
        cout << "EL robot está en X= " << coord_robot.get_x() << " y " << "Y= " << coord_robot.get_y() << endl;
        hab1.colocar_tello(coord_robot, true);
        hab1.dibujar();

        puerta = mypibot.detectar_objeto(pos_puerta);
        distancia = mypibot.leer_ultrasonidos(pos_esquina_infd);

    }

    hab1.colocar_tello(coord_robot, false);
    hab1.dibujar();


    return 0;
}
