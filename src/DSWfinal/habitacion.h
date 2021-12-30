#ifndef HABITACION_H_INCLUDED
#define HABITACION_H_INCLUDED

#include "tipos.h"
#include "posicion.h"
#include "coordenadas.h"

class Habitacion
{
public:
    Habitacion(Posicion& esquina_inf_dcha);
    void colocar_puerta_aleatoria(Posicion& pos);
    void obtener_coordenadas_aleatorias_para_robot(Coordenadas& coord) const;
    void colocar_pibot(Coordenadas& coord);
    void colocar_tello(Coordenadas& coord, bool volando);
    void dibujar(void) const;
private:
    static const int MAX_FILAS = 20;
    static const int MAX_COLUMNAS = 60;
    char matriz[MAX_FILAS][MAX_COLUMNAS];
    Posicion esquina_infd;
};

#endif // HABITACION_H_INCLUDED
