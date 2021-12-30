#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED

#include "coordenadas.h"

class Robot
{
public:
    Robot(const Coordenadas& c): coord(c) {}
    void get_coordenadas(Coordenadas& c) const { c = coord; }

    virtual bool detectar_objeto(Posicion& pos_objeto) = 0;
    virtual int leer_ultrasonidos(Posicion& pos_esquina) = 0;
    virtual void avanzar(void) = 0;
    virtual void girar_derecha(void) = 0;
    virtual int obtener_distancia_avance(void) const = 0;

protected:
    Coordenadas coord;
    int distancia_avance;
};


#endif // ROBOT_H_INCLUDED
