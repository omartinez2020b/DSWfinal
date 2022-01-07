#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED

#include "coordenadas.h"
#include <iostream>
using namespace std;

class Robot
{
    public:
        Robot(const Coordenadas& c): coord(c) {}
        /* Se añade un destructor virtual porque más adelante se usarán las clases
        derivadas con memoria dinámica, y así se destruye todo óptimamente */
        virtual ~Robot() {}
        void get_coordenadas(Coordenadas& c) const { c = coord; }

        virtual bool detectar_objeto(Posicion& pos_objeto) = 0;
        virtual int leer_ultrasonidos(Posicion& pos_esquina) = 0;
        virtual void avanzar(void) = 0;
        virtual void girar_derecha(void) = 0;


    protected:
        Coordenadas coord;
        int alcance_sensor;
};


#endif // ROBOT_H_INCLUDED
