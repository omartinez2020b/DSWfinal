#include "pibot.h"
#include "tipos.h"
#include <iostream>
using namespace std;

void Pibot::avanzar(void)
{
    t_Orientacion orientacion = coord.get_orientacion();
    int x = coord.get_x();
    int y = coord.get_y();

    if (orientacion == NORTE) y = y - 1;
    else if (orientacion == ESTE) x = x + 1;
    else if (orientacion == OESTE) x = x - 1;
    else y = y + 1;

    coord.set_x(x);
    coord.set_y(y);
}

bool Pibot::detectar_objeto(Posicion& pos_objeto)
{
    bool detectado = false;
    int x_obj = pos_objeto.get_x();
    int y_obj = pos_objeto.get_y();

    int x_robot = coord.get_x();
    int y_robot = coord.get_y();
    t_Orientacion ori = coord.get_orientacion();

    switch(ori)
    {
        case ESTE:
            if (x_robot == x_obj && y_robot == y_obj + alcance_sensor) detectado = true;
            break;
        case SUR:
            if (x_robot == x_obj - alcance_sensor && y_robot == y_obj) detectado = true;
            break;
        case OESTE:
             if (x_robot == x_obj && y_robot == y_obj - alcance_sensor) detectado = true;
            break;
        default:
            if (x_robot == x_obj + alcance_sensor && y_robot == y_obj) detectado = true;
    }

    return detectado;
}

int Pibot::leer_ultrasonidos(Posicion& pos_esquina)
{
    int distancia;
    int x_esquina = pos_esquina.get_x();
    int y_esquina = pos_esquina.get_y();

    int x_robot = coord.get_x();
    int y_robot = coord.get_y();
    t_Orientacion ori = coord.get_orientacion();

    if (ori == ESTE) distancia = x_esquina - x_robot - 1; // Hay que contar con el grosor de las paredes
    else if (ori == SUR) distancia = y_esquina - y_robot -1;
    else if (ori == OESTE) distancia = x_robot - 1;
    else distancia = y_robot - 1;

    return distancia;
}

void Pibot::girar_derecha(void)
{
    t_Orientacion ori = coord.get_orientacion();

    if (ori == ESTE) coord.set_orientacion(SUR);
    else if (ori == SUR) coord.set_orientacion(OESTE);
    else if (ori == OESTE) coord.set_orientacion(NORTE);
    else coord.set_orientacion(ESTE);
}


