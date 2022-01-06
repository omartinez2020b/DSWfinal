#include "simulacion.h"
#include "posicion.h"
#include "coordenadas.h"

void Simulacion::simular_tello(Tello& tello)
{
    // Variables
    Posicion pos_esquina_infd;
    Posicion pos_puerta;
    Coordenadas coord_robot;

    // Se coloca todo en posición inicial
    hab.get_esquina_infd(pos_esquina_infd);
    hab.colocar_puerta_aleatoria(pos_puerta);
    hab.obtener_coordenadas_aleatorias_para_robot(coord_robot);
    hab.colocar_tello(coord_robot, false);
    hab.dibujar();

    // Se comprueba si la puerta ya se encuentra nada más empezar
    bool puerta = tello.detectar_objeto(pos_puerta);
    int distancia = tello.leer_ultrasonidos(pos_esquina_infd);

    while (!puerta)
    {
        system("clear");

        if (distancia <= 1) tello.girar_derecha();
        tello.avanzar();

        tello.get_coordenadas(coord_robot);
        hab.colocar_tello(coord_robot, true);
        hab.dibujar();

        puerta = tello.detectar_objeto(pos_puerta);
        distancia = tello.leer_ultrasonidos(pos_esquina_infd);

    }
    system("clear");
    hab1.colocar_tello(coord_robot, false);
    hab1.dibujar();
}
