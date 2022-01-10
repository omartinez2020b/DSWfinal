#include "simulacion.h"
#include <unistd.h>

/* Esta función tiene escasamente más de 20 líneas, debido a que se ha puesto el código
de manera más legible con espacios en blanco */
void Simulacion::simular_tello()
{
    int lectura_distancia;
    bool volando = false;
    inicializar_entorno();
    Tello* tello = new Tello(coord_robot);
    hab.colocar_tello(coord_robot, volando);
    hab.dibujar();

    bool puerta_detectada = tello->detectar_objeto(pos_puerta);

    while (!puerta_detectada)
    {
        sleep(1); // Los giros también duran 1s: decisión de diseño
        system("clear");
        volando = !puerta_detectada;
        lectura_distancia = tello->leer_ultrasonidos(pos_esquina_infd);
        if (lectura_distancia < tello->obtener_distancia_avance())
            tello->girar_derecha();
        else
            tello->avanzar();

        tello->get_coordenadas(coord_robot);
        hab.colocar_tello(coord_robot, volando);
        hab.dibujar();
        puerta_detectada = tello->detectar_objeto(pos_puerta);
    }
    system("clear");
    hab.colocar_tello(coord_robot, volando);
    hab.dibujar();
    delete tello;
}

void Simulacion::simular_pibot()
{
    int lectura_distancia;
    inicializar_entorno();
    Pibot* pibot = new Pibot(coord_robot);
    hab.colocar_pibot(coord_robot);
    hab.dibujar();

    bool puerta_detectada = pibot->detectar_objeto(pos_puerta);

    while (!puerta_detectada)
    {
        sleep(1); // Los giros también duran 1s: decisión de diseño
        system("clear");
        lectura_distancia = pibot->leer_ultrasonidos(pos_esquina_infd);
        if (lectura_distancia < pibot->obtener_distancia_avance())
            pibot->girar_derecha();
        else
            pibot->avanzar();

        pibot->get_coordenadas(coord_robot);
        hab.colocar_pibot(coord_robot);
        hab.dibujar();
        puerta_detectada = pibot->detectar_objeto(pos_puerta);
    }
    system("clear");
    hab.colocar_pibot(coord_robot);
    hab.dibujar();
    delete pibot;
}

// Realiza todas las funciones necesarias iniciales de la habitación
void Simulacion::inicializar_entorno()
{
    hab.get_esquina_infd(pos_esquina_infd);
    hab.colocar_puerta_aleatoria(pos_puerta);
    hab.obtener_coordenadas_aleatorias_para_robot(coord_robot);
}

