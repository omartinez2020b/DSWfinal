#include "simulacion.h"

/* Esta función tiene más de 20 líneas, dado que sería lo que iría en el main pero
se ha puesto así para facilitar la abstracción y el uso de la simulación */
void Simulacion::simular_tello()
{
    inicializar_entorno();
    Tello* tello = new Tello(coord_robot);
    hab.colocar_tello(coord_robot, false);
    /* El tello tiene un fallo de diseño, puesto que su sensor tiene 2 de alcance,
    si la puerta está justo en el bloque de en medio entre él y la de enfrente
    (en alguna de las paredes de los lados), no se detectará nunca. Por lo tanto,
    se reduce cuando se alcanzan 200 iteraciones la distancia para girar a 0 */
    int iters = 0;
    int detect = 1;
    bool puerta = tello->detectar_objeto(pos_puerta);
    int distancia = tello->leer_ultrasonidos(pos_esquina_infd);
    while (!puerta)
    {
        system("clear");
        if (distancia <= detect) tello->girar_derecha();
        else tello->avanzar();
        tello->get_coordenadas(coord_robot);
        hab.colocar_tello(coord_robot, true);
        hab.dibujar();
        puerta = tello->detectar_objeto(pos_puerta);
        distancia = tello->leer_ultrasonidos(pos_esquina_infd);
        iters++;
        if (iters > 200) detect = 0;
    }
    system("clear");
    hab.colocar_tello(coord_robot, false);
    hab.dibujar();
    delete tello;
}

void Simulacion::inicializar_entorno()
{
    hab.get_esquina_infd(pos_esquina_infd);
    hab.colocar_puerta_aleatoria(pos_puerta);
    hab.obtener_coordenadas_aleatorias_para_robot(coord_robot);
    hab.dibujar();
}

void Simulacion::simular_pibot()
{
    inicializar_entorno();
    Pibot* pibot = new Pibot(coord_robot);
    hab.colocar_pibot(coord_robot);

    bool puerta = pibot->detectar_objeto(pos_puerta);
    int distancia = pibot->leer_ultrasonidos(pos_esquina_infd);
    while (!puerta)
    {
        system("clear");
        if (distancia == 0) pibot->girar_derecha();
        else pibot->avanzar();
        pibot->get_coordenadas(coord_robot);
        hab.colocar_pibot(coord_robot);
        hab.dibujar();
        puerta = pibot->detectar_objeto(pos_puerta);
        distancia = pibot->leer_ultrasonidos(pos_esquina_infd);
    }
    system("clear");
    hab.colocar_pibot(coord_robot);
    hab.dibujar();
    delete pibot;
}


